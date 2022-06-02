#include "resource.hpp"

void RegisterResourceClass(const py::module_& m)
{
	auto pyClass = py::class_<Resource>(m, "Resource");
	pyClass.def_property_readonly("is_started", &Resource::IsStarted);
	pyClass.def_property_readonly("type", &Resource::GetType);
	pyClass.def_property_readonly("name", &Resource::GetName);
	pyClass.def_property_readonly("main", &Resource::GetMain);
	pyClass.def_property_readonly("path", &Resource::GetPath);
	pyClass.def_property_readonly("config", &Resource::GetConfig);
	pyClass.def_property_readonly("exports", &Resource::GetExports);
	pyClass.def_property_readonly("dependencies", &Resource::GetDependencies);
	pyClass.def_property_readonly("dependants", &Resource::GetDependants);
	pyClass.def_property_readonly("required_permissions", &Resource::GetRequiredPermissions);
	pyClass.def_property_readonly("optional_permissions", &Resource::GetOptionalPermissions);

	pyClass.def_static("get_by_name", &Resource::GetByName, py::arg("resource_name"));
	pyClass.def_property_readonly_static("all", &Resource::GetAllResources);
	pyClass.def_property_readonly_static("current", &Resource::GetCurrent);
}
