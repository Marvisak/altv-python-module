#include <main.h>
#include <PythonResource.h>

bool PythonResource::Start()
{
    alt::String mainFile = resource->GetMain();
    FILE* fp = fopen(mainFile.CStr(), "r");
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

