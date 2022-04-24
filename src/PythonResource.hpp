#pragma once

#include "main.hpp"
#include "interval.hpp"

class PythonRuntime;
class PythonResource : public alt::IResource::Impl
{
	PythonRuntime* Runtime;
	alt::IResource* Resource;
	PyThreadState* Interpreter;

	typedef std::vector<py::function> EventsVector;
	typedef std::map<alt::CEvent::Type, EventsVector> EventsMap;
	typedef std::map<std::string, EventsVector> CustomEventsMap;
	EventsMap LocalEvents;
	CustomEventsMap LocalCustomEvents;
	CustomEventsMap RemoteEvents;

	typedef std::vector<Interval*> IntervalVector;
	IntervalVector Intervals;

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

	bool IsObjectValid(const alt::Ref<alt::IBaseObject>& object);

	void OnTick() override;

	void OnCreateBaseObject(alt::Ref<alt::IBaseObject> object) override;

	void OnRemoveBaseObject(alt::Ref<alt::IBaseObject> object) override;

	void AddInterval(double milliseconds, const py::function& func);

	Interval* GetInterval(const py::function& func);

	void AddLocalEvent(const alt::CEvent::Type& type, const py::function& eventFunc);

	void AddLocalCustomEvent(const std::string& eventName, const py::function& eventFunc);

	void AddRemoteEvent(const std::string& eventName, const py::function& eventFunc);

	void HandleCustomEvent(const alt::CEvent* event);

	class PythonFunction : public alt::IMValueFunction::Impl
	{
	 private:
		py::function func;

	 public:
		explicit PythonFunction(py::function func)
			: func(std::move(func)){};

		alt::MValue Call(alt::MValueArgs args) const override;
	};

	bool MakeClient(alt::IResource::CreationInfo* info, alt::Array<std::string> files) override;
};
