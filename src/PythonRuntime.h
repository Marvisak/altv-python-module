#pragma once

#include "PythonResource.h"
#include "main.h"
#include "events/events.h"

class PythonRuntime : public alt::IScriptRuntime
{
	std::vector<PythonResource*> Resources{};
	static PythonRuntime* Instance;
public:
	PythonRuntime();
	alt::IResource::Impl* CreateImpl(alt::IResource* resource) override;
	void DestroyImpl(alt::IResource::Impl* impl) override;
	void OnDispose() override;
	PythonResource* GetPythonResourceFromPath(std::string const& path);

	static PythonRuntime* GetInstance()
	{
		return Instance;
	}
};
