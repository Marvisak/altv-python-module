#pragma once

#include "classes/classes.hpp"
#include "utils.hpp"

class Resource {
 private:
	alt::IResource* resource;
 public:
	Resource(alt::IResource* resource) : resource(resource) {}

	bool IsStarted() {
		return resource->IsStarted();
	}

	std::string GetType() {
		return resource->GetType();
	}

	std::string GetName() {
		return resource->GetName();
	}

	std::string GetMain() {
		return resource->GetMain();
	}

	std::string GetPath() {
		return resource->GetPath();
	}

	py::dict GetExports() {
		return Utils::MValueToValue(resource->GetExports());
	}

	py::list GetDependencies() {
		return Utils::ArrayToPyList<std::string>(resource->GetDependencies());
	}

	py::list GetDependants() {
		return Utils::ArrayToPyList<std::string>(resource->GetDependants());
	}

	py::list GetRequiredPermissions() {
		py::list list;
		auto permissions = resource->GetRequiredPermissions();
		for (auto permission : permissions)
			list.append((int)permission);
		return list;
	}

	py::list GetOptionalPermissions() {
		py::list list;
		auto permissions = resource->GetOptionalPermissions();
		for (auto permission : permissions)
			list.append((int)permission);
		return list;
	}

	static Resource GetByName(const std::string& resourceName) {
		auto resource = alt::ICore::Instance().GetResource(resourceName);
		if (resource != nullptr)
			return {resource};
		return nullptr;
	}

	static py::list GetAllResources(const py::object& type) {
		py::list list;
		auto resources = alt::ICore::Instance().GetAllResources();
		for (auto resource : resources)
			list.append(Resource(resource));
		return list;
	}

	static Resource GetCurrent(const py::object& type) {
		PyThreadState* interp = PyThreadState_Get();
		PythonResource* resource = PythonRuntime::GetInstance()->GetPythonResourceFromInterp(interp);
		return {resource->GetResource()};
	}
};