#pragma once

#include "main.h"

class PythonRuntime;
class PythonResource : public alt::IResource::Impl
{
	PythonRuntime* Runtime;
	alt::IResource* Resource;
	typedef std::vector<py::function> EventsVector;
	typedef std::map<std::string, EventsVector> EventsMap;
	EventsMap LocalEvents;
	EventsMap RemoteEvents;

	std::unordered_map<alt::IBaseObject::Type, alt::Ref<alt::IBaseObject>> objects;

	friend PythonRuntime;

 public:
	PythonResource(PythonRuntime* runtime, alt::IResource* resource)
		: Runtime(runtime), Resource(resource)
	{
	}

	bool Start() override;

	bool Stop() override;

	bool OnEvent(const alt::CEvent* ev) override;

	alt::String GetFullPath();

	bool IsObjectValid(const alt::Ref<alt::IBaseObject>& object);

	void OnCreateBaseObject(alt::Ref<alt::IBaseObject> object) override;

	void OnRemoveBaseObject(alt::Ref<alt::IBaseObject> object) override;

	void AddLocalEvent(const std::string& eventName, const py::function& eventFunc);

	void AddRemoteEvent(const std::string& eventName, const py::function& eventFunc);

	class PythonFunction : public alt::IMValueFunction::Impl
	{
	 private:
		py::function func;

	 public:
		explicit PythonFunction(py::function func)
			: func(std::move(func)){};

		alt::MValue Call(alt::MValueArgs args) const override;
	};

	bool MakeClient(alt::IResource::CreationInfo* info, alt::Array<alt::String> files) override;
};
