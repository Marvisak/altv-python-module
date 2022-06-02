#pragma once

#include "PythonResource.hpp"
#include "events/events.hpp"
#include "main.hpp"

class PythonRuntime : public alt::IScriptRuntime
{
	std::vector<PythonResource*> resources{};
	PyThreadState* mainInterpreter;
	static PythonRuntime* instance;
#ifdef __linux__
	void* python;
#endif
 public:
	PythonRuntime();
	alt::IResource::Impl* CreateImpl(alt::IResource* resource) override;
	void DestroyImpl(alt::IResource::Impl* impl) override;
	void OnDispose() override;
	PythonResource* GetPythonResourceFromInterp(PyThreadState* state);

	PyThreadState* GetInterpreter()
	{
		return mainInterpreter;
	}

	static PythonRuntime* GetInstance()
	{
		return instance;
	}
};
