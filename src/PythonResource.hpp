#pragma once

#include "main.hpp"
#include "interval.hpp"

class PythonRuntime;
class PythonResource : public alt::IResource::Impl
{
	PythonRuntime* runtime;
	alt::IResource* resource;
	PyThreadState* interpreter;

	std::map<alt::CEvent::Type, std::vector<py::function>> localEvents;
	std::map<std::string, std::vector<py::function>> localCustomEvents;
	std::map<std::string, std::vector<py::function>> remoteEvents;

	int intervalId = 0;
	std::vector<Interval*> tasks;
	std::map<int, Interval*> timers;

	std::unordered_map<alt::IBaseObject::Type, alt::Ref<alt::IBaseObject>> objects;
 public:
	PythonResource(PythonRuntime* runtime, alt::IResource* resource)
		: runtime(runtime), resource(resource)
	{
	}

	bool Start() override;

	bool Stop() override;

	bool OnEvent(const alt::CEvent* ev) override;

	bool IsObjectValid(const alt::Ref<alt::IBaseObject>& object);

	void OnTick() override;

	void OnCreateBaseObject(alt::Ref<alt::IBaseObject> object) override;

	void OnRemoveBaseObject(alt::Ref<alt::IBaseObject> object) override;

	int AddTimer(double milliseconds, const py::function& func);

	void ClearTimer(int timerId);

	void AddTask(double milliseconds, const py::function& func);

	Interval* GetInterval(const py::function& func);

	void AddLocalEvent(const alt::CEvent::Type& type, const py::function& eventFunc);

	void AddLocalCustomEvent(const std::string& eventName, const py::function& eventFunc);

	void AddRemoteEvent(const std::string& eventName, const py::function& eventFunc);

	void HandleCustomEvent(const alt::CEvent* event);

	alt::IResource* GetResource() {
		return resource;
	}

	PyThreadState* GetInterpreter() {
		return interpreter;
	}

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
