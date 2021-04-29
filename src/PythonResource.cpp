#include <main.h>
#include <PythonResource.h>

bool PythonResource::Start()
{
    alt::String path = resource->GetPath();
    alt::String mainFile = path + preferred_separator + resource->GetMain();
    FILE* fp = fopen(mainFile.CStr(), "r");
    bool crashed = PyRun_SimpleFile(fp, mainFile.CStr());
    return !crashed;
}
bool PythonResource::Stop()
{
    return true;
}

bool PythonResource::OnEvent(const alt::CEvent *ev) {
    auto type = ev->GetType();
    if(type == alt::CEvent::Type::RESOURCE_START)
    {
        for (const auto &func : Events["anyResourceStart"])
        {
            func();
        }
    }
    return true;
}

void PythonResource::OnCreateBaseObject(alt::Ref<alt::IBaseObject> object) {

}

void PythonResource::OnRemoveBaseObject(alt::Ref<alt::IBaseObject> object) {

}

void PythonResource::AddEvent(const std::string &eventName, const pybind11::function &eventFunc) {
    Events[eventName].push_back(eventFunc);
}

