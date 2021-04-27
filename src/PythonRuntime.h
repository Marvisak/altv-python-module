#pragma once

#include <main.h>
#include <PythonResource.h>

class PythonRuntime : public alt::IScriptRuntime
{
    std::unordered_set<PythonResource*> resources;
    static PythonRuntime* instance;

public:
    PythonRuntime();


    alt::IResource::Impl* CreateImpl(alt::IResource* resource) override;

    void DestroyImpl(alt::IResource::Impl* impl) override;
    void OnDispose() override;

    static PythonRuntime* GetInstance()
    {
        return instance;
    }
};
