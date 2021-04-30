#pragma once

#include <main.h>
#include <PythonResource.h>

class PythonRuntime : public alt::IScriptRuntime
{
    std::vector<PythonResource*> resources {};
    static PythonRuntime* instance;
    const std::vector<std::string> EventTypes{
        "anyResourceError"
    };

public:
    PythonRuntime();

    std::string GetEventType(const alt::CEvent* ev);
    std::string GetEventType(alt::CEvent::Type ev);

    alt::IResource::Impl* CreateImpl(alt::IResource* resource) override;

    void DestroyImpl(alt::IResource::Impl* impl) override;
    void OnDispose() override;
    PythonResource* GetPythonResourceFromPath(std::string const &path);

    static PythonRuntime* GetInstance()
    {
        return instance;
    }
};
