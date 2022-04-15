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
			auto eventArgs = eventHandler->GetEventArgs(event);
			EventsVector callbacks = LocalEvents[eventType];
			for (const auto& callback : callbacks) {
				try {
					callback(*eventArgs);
				} catch (py::error_already_set& e) {
					py::print(e.what());
					e.restore();
				}
			}
		}
	}
    return true;
}

void PythonResource::HandleCustomEvent(const alt::CEvent* ev) {
	py::list eventArgs;
	EventsVector callbacks;
	if (ev->GetType() == alt::CEvent::Type::SERVER_SCRIPT_EVENT) {
		auto event = dynamic_cast<const alt::CServerScriptEvent*>(ev);
		std::string name = event->GetName();
		callbacks = LocalCustomEvents[name];
		for (const auto& arg : event->GetArgs())
		{
			auto value = Utils::MValueToValue(arg);
			eventArgs.append(value);
		}
	} else {
		auto event = dynamic_cast<const alt::CClientScriptEvent*>(ev);
		std::string name = event->GetName();
		callbacks = RemoteEvents[name];
		eventArgs.append(event->GetTarget().Get());
		for (const auto& arg : event->GetArgs())
		{
			auto value = Utils::MValueToValue(arg);
			eventArgs.append(value);
		}
	}
	for (const auto& callback : callbacks) {
		try {
			callback(*eventArgs);
		} catch (py::error_already_set& e) {
			py::print(e.what());
			e.restore();
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
	{
		if (it->second == object)
		{
			objects.erase(it);
			break;
		}
	}
}

bool PythonResource::IsObjectValid(const alt::Ref<alt::IBaseObject>& object) {
	auto range = objects.equal_range(object->GetType());
	for (auto it = range.first; it != range.second; it++)
		if (it->second == object) return true;
	return false;
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
	{
		funcArgs.append(Utils::MValueToValue(arg));
	}
	auto returnValue = func(*funcArgs);
	return Utils::ValueToMValue(returnValue);
}

bool PythonResource::MakeClient(alt::IResource::CreationInfo* info, alt::Array<std::string> files) {
	info->type = "js";
	return true;
}
