#include "PythonResource.hpp"
#include "utils.hpp"

bool PythonResource::Start()
{
	PyThreadState_Swap(runtime->GetInterpreter());
	interpreter = Py_NewInterpreter();

	std::string path = resource->GetPath();
	std::string main = resource->GetMain();
	std::string fullPath = path + SEPARATOR + main;

	// Makes importing local files possible
	py::module_ sys = py::module_::import("sys");
	py::list pyPath = sys.attr("path");
	pyPath.append(fullPath.substr(0, fullPath.find_last_of("\\/")));

	py::dict modules = sys.attr("modules");
	py::object imp = py::module_::import("importlib.util");
	for (const auto& depName : resource->GetDependencies())
	{
		alt::IResource* dep = alt::ICore::Instance().GetResource(depName);

		py::object spec = imp.attr("spec_from_loader")(depName, py::none());
		py::object module = imp.attr("module_from_spec")(spec);

		py::dict exports = Utils::MValueToValue(dep->GetExports());
		for (auto exp : exports)
			module.attr(exp.first) = exp.second;
		modules[depName.c_str()] = module;
	}

	FILE* fp = fopen(fullPath.c_str(), "r");
	if (!fp)
	{
		alt::ICore::Instance().LogError("Main file not found");
		return false;
	}
	bool crashed = PyRun_SimpleFile(fp, fullPath.c_str());
	fclose(fp);

	PyThreadState_Swap(runtime->GetInterpreter());
	return !crashed;
}
bool PythonResource::Stop()
{
	localEvents.clear();
	localCustomEvents.clear();
	remoteEvents.clear();
	objects.clear();

	for (const auto& task : tasks) delete task;
	for (const auto& timer : timers) delete timer.second;
	tasks.clear();
	timers.clear();
	PyThreadState_Swap(interpreter);
	Py_EndInterpreter(interpreter);
	PyThreadState_Swap(runtime->GetInterpreter());
	return true;
}

bool PythonResource::OnEvent(const alt::CEvent* event)
{
	auto eventType = event->GetType();
	if (eventType == alt::CEvent::Type::SERVER_SCRIPT_EVENT || eventType == alt::CEvent::Type::CLIENT_SCRIPT_EVENT)
		HandleCustomEvent(event);
	else
	{
		auto eventHandler = EventHandler::Get(event);
		if (eventHandler)
		{
			auto callbacks = localEvents[eventType];
			if (callbacks.empty()) return true;
			py::list eventArgs;
			eventHandler->GetEventArgs(event, eventArgs);
			for (const auto& callback : callbacks)
			{
				try
				{
					PyThreadState_Swap(interpreter);
					py::object returnValue = callback(*eventArgs);
					PyThreadState_Swap(runtime->GetInterpreter());
					if (py::isinstance<py::bool_>(returnValue) && !returnValue.cast<bool>())
						event->Cancel();
					else if (py::isinstance<py::str>(returnValue) && eventType == alt::CEvent::Type::PLAYER_BEFORE_CONNECT)
						reinterpret_cast<alt::CPlayerBeforeConnectEvent*>(const_cast<alt::CEvent*>(event))->Cancel(returnValue.cast<std::string>());
				}
				catch (py::error_already_set& e)
				{
					e.discard_as_unraisable(callback.attr("__name__"));
				}
			}
		}
	}
	return true;
}

void PythonResource::OnTick()
{
	for (auto task : tasks)
	{
		uint32_t time = alt::ICore::Instance().GetNetTime();
		if (task->Update(time) && (alt::ICore::Instance().GetNetTime() - time) > 10)
			task->TimeWarning(time, resource->GetName());
	}
	for (auto it = timers.cbegin(); it != timers.cend();)
	{
		uint32_t time = alt::ICore::Instance().GetNetTime();
		if (it->second->Update(time))
		{
			if ((alt::ICore::Instance().GetNetTime() - time) > 10)
				it->second->TimeWarning(time, resource->GetName());
			delete it->second;
			it = timers.erase(it);
		}
		else
			it = std::next(it);
	}
}

void PythonResource::HandleCustomEvent(const alt::CEvent* ev)
{
	py::list eventArgs;
	std::vector<py::function> callbacks;
	if (ev->GetType() == alt::CEvent::Type::SERVER_SCRIPT_EVENT)
	{
		auto event = dynamic_cast<const alt::CServerScriptEvent*>(ev);
		std::string name = event->GetName();
		callbacks = localCustomEvents[name];
		if (callbacks.empty()) return;
		for (const auto& arg : event->GetArgs())
		{
			auto value = Utils::MValueToValue(arg);
			eventArgs.append(value);
		}
	}
	else
	{
		auto event = dynamic_cast<const alt::CClientScriptEvent*>(ev);
		std::string name = event->GetName();
		callbacks = remoteEvents[name];
		if (callbacks.empty()) return;
		eventArgs.append(event->GetTarget().Get());
		for (const auto& arg : event->GetArgs())
		{
			auto value = Utils::MValueToValue(arg);
			eventArgs.append(value);
		}
	}
	for (const auto& callback : callbacks)
	{
		try
		{
			PyThreadState_Swap(interpreter);
			callback(*eventArgs);
			PyThreadState_Swap(runtime->GetInterpreter());
		}
		catch (py::error_already_set& e)
		{
			e.discard_as_unraisable(callback.attr("__name__"));
		}
	}
}

void PythonResource::OnCreateBaseObject(alt::Ref<alt::IBaseObject> object)
{
	object->AddRef();
	objects.insert({object->GetType(), object});
}

void PythonResource::OnRemoveBaseObject(alt::Ref<alt::IBaseObject> object)
{
	auto range = objects.equal_range(object->GetType());
	for (auto it = range.first; it != range.second; it++)
		if (it->second == object)
		{
			objects.erase(it);
			break;
		}
}

bool PythonResource::IsObjectValid(const alt::Ref<alt::IBaseObject>& object)
{
	auto range = objects.equal_range(object->GetType());
	for (auto it = range.first; it != range.second; it++)
		if (it->second == object) return true;
	return false;
}

int PythonResource::AddTimer(double milliseconds, const py::function& func)
{
	auto task = new Interval(milliseconds, func, interpreter);
	intervalId++;
	timers[intervalId] = task;
	return intervalId;
}

void PythonResource::ClearTimer(int timerId)
{
	auto interval = timers[timerId];
	timers.erase(timerId);
	delete interval;
}

void PythonResource::AddTask(double milliseconds, const py::function& func)
{
	auto task = new Interval(milliseconds, func, interpreter);
	tasks.push_back(task);
}

Interval* PythonResource::GetInterval(const py::function& func)
{
	for (int i{}; i < tasks.size(); i++)
		if (tasks[i]->GetFunc().is(func))
			return tasks[i];
	return nullptr;
}

void PythonResource::AddLocalEvent(const alt::CEvent::Type& type, const py::function& eventFunc)
{
	localEvents[type].push_back(eventFunc);
}

void PythonResource::AddLocalCustomEvent(const std::string& eventName, const py::function& eventFunc)
{
	localCustomEvents[eventName].push_back(eventFunc);
}

void PythonResource::AddRemoteEvent(const std::string& eventName, const py::function& eventFunc)
{
	remoteEvents[eventName].push_back(eventFunc);
}

alt::MValue PythonResource::PythonFunction::Call(alt::MValueArgs args) const
{
	py::list funcArgs;
	for (const auto& arg : args)
		funcArgs.append(Utils::MValueToValue(arg));
	auto returnValue = func(*funcArgs);
	return Utils::ValueToMValue(returnValue);
}

bool PythonResource::MakeClient(alt::IResource::CreationInfo* info, alt::Array<std::string> files)
{
	info->type = "js";
	return true;
}
