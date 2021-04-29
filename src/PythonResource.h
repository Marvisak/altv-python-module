#pragma once

#include <main.h>

class PythonRuntime;
class PythonResource : public alt::IResource::Impl
{
    PythonRuntime* runtime;
    alt::IResource* resource;
    std::map<std::string, std::vector<pybind11::function>> Events;

    friend PythonRuntime;
public:
    PythonResource(PythonRuntime* runtime, alt::IResource* resource) : runtime(runtime), resource(resource) {};

    bool Start() override;

    bool Stop() override;

    bool OnEvent(const alt::CEvent* ev) override;

    void OnCreateBaseObject(alt::Ref<alt::IBaseObject> object) override;

    void OnRemoveBaseObject(alt::Ref<alt::IBaseObject> object) override;

    void AddEvent(const std::string &eventName, const pybind11::function &eventFunc);
};