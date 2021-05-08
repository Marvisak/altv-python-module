#include <main.h>
#include <PythonResource.h>
#include <PythonRuntime.h>

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
            listener(*arguments);
        }
    } else {
        for (const auto &listener : ServerEvents[type])
        {
            listener();
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

