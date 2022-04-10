#include "PythonResource.hpp"
#include <filesystem>
#include "utils.hpp"

bool PythonResource::Start() {
	PyThreadState_Swap(Runtime->GetInterpreter());
	Interpreter = Py_NewInterpreter();

	auto separator = std::filesystem::path::preferred_separator;
	std::string path = Resource->GetPath().ToString();
	std::string main = Resource->GetMain().ToString();
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
	PyThreadState_Swap(Interpreter);
	Py_EndInterpreter(Interpreter);
	PyThreadState_Swap(Runtime->GetInterpreter());
	return true;
}

bool PythonResource::OnEvent(const alt::CEvent* event) {
	auto eventHandler = EventHandler::Get(event);
    if (eventHandler) {
        auto eventName = eventHandler->GetEventName(event);
        auto eventArgs = eventHandler->GetEventArgs(event);
        EventsVector callbacks;
        if (event->GetType() == alt::CEvent::Type::CLIENT_SCRIPT_EVENT) {
            callbacks = RemoteEvents[eventName];
        } else {
            callbacks = LocalEvents[eventName];
        }
        for (const auto& callback : callbacks) {
            try {
                // TODO Figure out somehow how to call async function
                callback(*eventArgs);
            } catch (py::error_already_set& e) {
                py::print(e.what());
            }
        }
    }
    return true;
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

void PythonResource::AddLocalEvent(const std::string& eventName, const py::function& eventFunc) {
    LocalEvents[eventName].push_back(eventFunc);
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

bool PythonResource::MakeClient(alt::IResource::CreationInfo* info, alt::Array<alt::String> files) {
	info->type = "js";
	return true;
}
