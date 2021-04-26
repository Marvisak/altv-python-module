#include <main.h>
#include <PythonRuntime.h>

alt::ICore* Core;

EXPORT bool altMain(alt::ICore* core)
{
    alt::ICore::SetInstance(core);
    Core = core;
    auto runtime = new PythonRuntime();

    core->RegisterScriptRuntime("py", runtime);

    core->LogInfo("Python module successfully loaded");

    return true;
}

EXPORT uint32_t GetSDKVersion()
{
    return alt::ICore::SDK_VERSION;
}