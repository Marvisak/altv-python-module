#pragma once

#include "PythonResource.hpp"
#include "main.hpp"
#include "events/events.hpp"

class PythonRuntime : public alt::IScriptRuntime
{
	std::vector<PythonResource*> Resources{};
	PyThreadState* MainInterpreter;
	static PythonRuntime* Instance;
public:
	PythonRuntime();
	alt::IResource::Impl* CreateImpl(alt::IResource* resource) override;
	void DestroyImpl(alt::IResource::Impl* impl) override;
	void OnDispose() override;
	PythonResource* GetPythonResourceFromInterp(PyThreadState* state);

	PyThreadState* GetInterpreter() {
		return MainInterpreter;
	}

	static PythonRuntime* GetInstance()
	{
		return Instance;
	}
};
