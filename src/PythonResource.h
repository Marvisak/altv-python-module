#pragma once

#include <main.h>
#include <PythonRuntime.h>

class PythonResource : public alt::IResource::Impl
{
    PythonRuntime* runtime;
    alt::IResource* resource;
public:
    PythonResource(PythonRuntime* runtime, alt::IResource* resource) : runtime(runtime), resource(resource) {};

    bool Start() override;

    bool Stop() override;

    bool OnEvent(const alt::CEvent* ev) override;

    void OnCreateBaseObject(alt::Ref<alt::IBaseObject> object) override;

    void OnRemoveBaseObject(alt::Ref<alt::IBaseObject> object) override;


};