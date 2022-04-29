#include "PythonResource.hpp"
#include <filesystem>
#include "utils.hpp"

bool PythonResource::Start() {
	PyThreadState_Swap(Runtime->GetInterpreter());
	Interpreter = Py_NewInterpreter();

	char separator = std::filesystem::path::preferred_separator;
	std::string path = Resource->GetPath();
	std::string main = Resource->GetMain();
	std::string fullPath = path + separator + main;

    // Makes importing local files possible
    py::module_ sys = py::module_::import("sys");
    py::list pyPath = sys.attr("path");
	pyPath.append(path);

	FILE* fp = fopen(fullPath.c_str(), "r");
	bool crashed = PyRun_SimpleFile(fp, fullPath.c_str());

	PyThreadState_Swap(Runtime->GetInterpreter());
	return !crashed;
}
bool PythonResource::Stop() {
	LocalEvents.clear();
	LocalCustomEvents.clear();
	RemoteEvents.clear();
	objects.clear();

	for (const auto& task : Tasks) delete task;
	for (const auto& timer : Timers) delete timer.second;
	Tasks.clear();
	Timers.clear();

	PyThreadState_Swap(Interpreter);
	Py_EndInterpreter(Interpreter);
	PyThreadState_Swap(Runtime->GetInterpreter());
	return true;
}

bool PythonResource::OnEvent(const alt::CEvent* event) {
	auto eventType = event->GetType();
	if (eventType == alt::CEvent::Type::SERVER_SCRIPT_EVENT || eventType == alt::CEvent::Type::CLIENT_SCRIPT_EVENT)
		HandleCustomEvent(event);
	else {
		auto eventHandler = EventHandler::Get(event);
		if (eventHandler) {
			py::list eventArgs;
			eventHandler->GetEventArgs(event, eventArgs);
			EventsVector callbacks = LocalEvents[eventType];
			for (const auto& callback : callbacks) {
				try {
					PyThreadState_Swap(Interpreter);
					py::object returnValue = callback(*eventArgs);
					PyThreadState_Swap(Runtime->GetInterpreter());
					if (py::isinstance<py::bool_>(returnValue) && !returnValue.cast<bool>())
						event->Cancel();
					else if (py::isinstance<py::str>(returnValue) && eventType == alt::CEvent::Type::PLAYER_BEFORE_CONNECT)
						reinterpret_cast<alt::CPlayerBeforeConnectEvent*>(const_cast<alt::CEvent*>(event))->Cancel(returnValue.cast<std::string>());
				} catch (py::error_already_set& e) {
					py::print(e.what());
				}
			}
		}
	}
    return true;
}

void PythonResource::OnTick() {
	for (auto task : Tasks) task->Update();
	for (auto it = Timers.cbegin(); it != Timers.cend();)
		if (it->second->Update()) {
			delete it->second;
			it = Timers.erase(it);
		} else
			it = std::next(it);
}

void PythonResource::HandleCustomEvent(const alt::CEvent* ev) {
	py::list eventArgs;
	EventsVector callbacks;
	if (ev->GetType() == alt::CEvent::Type::SERVER_SCRIPT_EVENT) {
		auto event = dynamic_cast<const alt::CServerScriptEvent*>(ev);
		std::string name = event->GetName();
		callbacks = LocalCustomEvents[name];
		for (const auto& arg : event->GetArgs()) {
			auto value = Utils::MValueToValue(arg);
			eventArgs.append(value);
		}
	} else {
		auto event = dynamic_cast<const alt::CClientScriptEvent*>(ev);
		std::string name = event->GetName();
		callbacks = RemoteEvents[name];
		eventArgs.append(event->GetTarget().Get());
		for (const auto& arg : event->GetArgs()) {
			auto value = Utils::MValueToValue(arg);
			eventArgs.append(value);
		}
	}
	for (const auto& callback : callbacks) {
		try {
			PyThreadState_Swap(Interpreter);
			callback(*eventArgs);
			PyThreadState_Swap(Runtime->GetInterpreter());
		} catch (py::error_already_set& e) {
			py::print(e.what());
		}
	}
}

void PythonResource::OnCreateBaseObject(alt::Ref<alt::IBaseObject> object) {
	object->AddRef();
	objects.insert({object->GetType(), object});
}

void PythonResource::OnRemoveBaseObject(alt::Ref<alt::IBaseObject> object) {
	auto range = objects.equal_range(object->GetType());
	for (auto it = range.first; it != range.second; it++)
		if (it->second == object) {
			objects.erase(it);
			break;
		}
}

bool PythonResource::IsObjectValid(const alt::Ref<alt::IBaseObject>& object) {
	auto range = objects.equal_range(object->GetType());
	for (auto it = range.first; it != range.second; it++)
		if (it->second == object) return true;
	return false;
}

int PythonResource::AddTimer(double milliseconds, const py::function& func) {
	auto task = new Interval(milliseconds, func);
	intervalId++;
	Timers[intervalId] = task;
	return intervalId;
}

void PythonResource::ClearTimer(int timerId) {
	auto interval = Timers[timerId];
	Timers.erase(timerId);
	delete interval;
}

void PythonResource::AddTask(double milliseconds, const py::function& func) {
	auto task = new Interval(milliseconds, func);
	Tasks.push_back(task);
}

Interval* PythonResource::GetInterval(const py::function& func) {
	for (int i{}; i<Tasks.size(); i++)
		if (Tasks[i]->GetFunc().is(func))
			return Tasks[i];
	return nullptr;
}


void PythonResource::AddLocalEvent(const alt::CEvent::Type& type, const py::function& eventFunc) {
	LocalEvents[type].push_back(eventFunc);
}

void PythonResource::AddLocalCustomEvent(const std::string& eventName, const py::function& eventFunc) {
    LocalCustomEvents[eventName].push_back(eventFunc);
}

void PythonResource::AddRemoteEvent(const std::string& eventName, const py::function& eventFunc) {
    RemoteEvents[eventName].push_back(eventFunc);
}

alt::MValue PythonResource::PythonFunction::Call(alt::MValueArgs args) const {
	py::list funcArgs;
	for (const auto& arg : args)
		funcArgs.append(Utils::MValueToValue(arg));
	auto returnValue = func(*funcArgs);
	return Utils::ValueToMValue(returnValue);
}

bool PythonResource::MakeClient(alt::IResource::CreationInfo* info, alt::Array<std::string> files) {
	info->type = "js";
	return true;
}
