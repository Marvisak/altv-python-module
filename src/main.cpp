#include "main.h"
#include "PythonRuntime.h"

EXPORT bool altMain(alt::ICore* core)
{
	alt::ICore::SetInstance(core);

	try {
		auto runtime = new PythonRuntime();
		core->RegisterScriptRuntime("py", runtime);
	}
	catch (std::exception& e) {
		core->LogError(e.what());
        return false;
	}

	core->LogInfo("Python module successfully loaded");
	return true;
}

EXPORT uint32_t GetSDKVersion()
{
	return alt::ICore::SDK_VERSION;
}
