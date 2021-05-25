#include <main.h>
#include <PythonResource.h>
#include <PythonRuntime.h>
#include <utils.h>

bool PythonResource::Start()
{
    alt::String mainFile = GetFullPath();
    FILE* fp = fopen(mainFile.CStr(), "r");
    bool crashed = PyRun_SimpleFile(fp, mainFile.CStr());
    return !crashed;
}
bool PythonResource::Stop()
{
    return true;
}

bool PythonResource::OnEvent(const alt::CEvent* ev) {
    auto type = runtime->GetEventType(ev->GetType());
    if (runtime->GetEventArgs(type)) {
        auto getter = GetEventList(ev, type);
        auto arguments = runtime->GetEventArgs(type)(ev);
        for (const auto &listener : getter)
        {
            try {
                listener(*arguments);
            } catch (py::error_already_set &e)
            {
                py::print(e.what());
            }
        }
    } else {
        for (const auto &listener : ServerEvents[type])
        {
            try {
                listener();
            } catch (py::error_already_set &e) {
                py::print(e.what());
            }
        }
    }
    return true;
}

void PythonResource::OnCreateBaseObject(alt::Ref<alt::IBaseObject> object) {

}

void PythonResource::OnRemoveBaseObject(alt::Ref<alt::IBaseObject> object) {

}

void PythonResource::AddEvent(const std::string &eventName, const py::function &eventFunc) {
    ServerEvents[eventName].push_back(eventFunc);
}

alt::String PythonResource::GetFullPath() {
    alt::String path = resource->GetPath();
    alt::String fullPath = path + preferred_separator + resource->GetMain();
    return fullPath;
}

alt::MValue PythonResource::PythonFunction::Call(alt::MValueArgs args) const {
    py::list funcArgs;
    for (const auto& arg : args) {
        funcArgs.append(Utils::MValueToValue(arg));
    }
    auto returnValue = func(*funcArgs);
    return Utils::ValueToMValue(returnValue);
}

bool PythonResource::MakeClient(alt::IResource::CreationInfo* info, alt::Array<alt::String> files)
{
    info->type = "js";
    return true;
}

