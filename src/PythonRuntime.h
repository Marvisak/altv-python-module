#pragma once

#include "PythonResource.h"
#include "main.h"

class PythonRuntime : public alt::IScriptRuntime
{
	std::vector<PythonResource*> resources{};
	static PythonRuntime* instance;
	typedef std::function<py::args(const alt::CEvent*)> GetterFunc;
	std::map<std::string, GetterFunc> ArgGetters{};

	inline void RegisterArgGetter(alt::CEvent::Type eventType, const GetterFunc& getter)
	{
		ArgGetters[GetEventType(eventType)] = getter;
	}

 public:
	PythonRuntime();

	inline GetterFunc GetEventArgs(const std::string& eventName)
	{
		return ArgGetters[eventName];
	}

	static std::string GetEventType(alt::CEvent::Type ev);

	alt::IResource::Impl* CreateImpl(alt::IResource* resource) override;

	void DestroyImpl(alt::IResource::Impl* impl) override;
	void OnDispose() override;
	PythonResource* GetPythonResourceFromPath(std::string const& path);

	static PythonRuntime* GetInstance()
	{
		return instance;
	}
};
