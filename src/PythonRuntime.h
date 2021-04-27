#pragma once

class PythonRuntime : public alt::IScriptRuntime
{
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
