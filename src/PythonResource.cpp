#include "PythonResource.hpp"
#include "utils.hpp"

bool PythonResource::Start() {
	alt::String mainFile = GetFullPath();

	std::string path = Resource->GetPath().ToString();

    // Makes importing local files possible
    PyObject* sys = PyImport_ImportModule("sys");
    PyObject* pyPath = PyObject_GetAttrString(sys, "path");
    PyList_Append(pyPath, PyUnicode_FromString(path.c_str()));

	FILE* fp = fopen(mainFile.CStr(), "r");
	bool crashed = PyRun_SimpleFile(fp, mainFile.CStr());
	return !crashed;
}
bool PythonResource::Stop() {
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

alt::String PythonResource::GetFullPath() {
	alt::String path = Resource->GetPath();
	alt::String fullPath = path + preferred_separator + Resource->GetMain();
	return fullPath;
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
