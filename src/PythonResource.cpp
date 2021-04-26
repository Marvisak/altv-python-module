#include <main.h>
#include <PythonResource.h>

bool PythonResource::Start() {
    alt::String dir = alt::String(resource->GetPath()) + alt::String(preferred_separator);
    alt::String mainFile = dir + resource->GetMain();
    FILE* fp = fopen(mainFile.CStr(), "r");
    // This might be updated to something better
    bool crashed = PyRun_SimpleFile(fp, mainFile.CStr());
    return !crashed;
}

bool PythonResource::Stop()
{
    return true;
}

bool PythonResource::OnEvent(const alt::CEvent *ev) {
    return true;
}

void PythonResource::OnCreateBaseObject(alt::Ref<alt::IBaseObject> object) {

}

void PythonResource::OnRemoveBaseObject(alt::Ref<alt::IBaseObject> object) {

}

