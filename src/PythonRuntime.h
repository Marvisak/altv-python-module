#pragma once

#include <main.h>
#include <PythonResource.h>

class PythonRuntime : public alt::IScriptRuntime
{
    std::vector<PythonResource*> resources {};
    static PythonRuntime* instance;

public:
    PythonRuntime();


    alt::IResource::Impl* CreateImpl(alt::IResource* resource) override;

    void DestroyImpl(alt::IResource::Impl* impl) override;
    void OnDispose() override;
    PythonResource* GetPythonResourceFromPath(std::string const &path);

    static PythonRuntime* GetInstance()
    {
        return instance;
    }
};
