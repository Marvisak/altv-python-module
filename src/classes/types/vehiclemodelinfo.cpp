#include "classes/classes.hpp"
#include "enums.hpp"

VehicleType GetType(const alt::VehicleModelInfo& modelInfo) {
	return (VehicleType)modelInfo.modelType;
}

py::list GetAvailableModKits(const alt::VehicleModelInfo& modelInfo) {
	py::list list;
	for (auto modkit : modelInfo.modkits)
		list.append(modkit != 0xFFFF);
	return list;
}

void RegisterVehicleModelInfoClass(const py::module_& m) {
	auto pyClass = py::class_<alt::VehicleModelInfo>(m, "VehicleModelInfo");
	pyClass.def_readonly("title", &alt::VehicleModelInfo::title);
	pyClass.def_readonly("wheels_count", &alt::VehicleModelInfo::wheelsCount);
	pyClass.def_readonly("has_armored_windows", &alt::VehicleModelInfo::hasArmoredWindows);
	pyClass.def_readonly("primary_color", &alt::VehicleModelInfo::primaryColor);
	pyClass.def_readonly("secondary_color", &alt::VehicleModelInfo::secondaryColor);
	pyClass.def_readonly("pearl_color", &alt::VehicleModelInfo::pearlColor);
	pyClass.def_readonly("wheels_color", &alt::VehicleModelInfo::wheelsColor);
	pyClass.def_readonly("interior_color", &alt::VehicleModelInfo::interiorColor);
	pyClass.def_readonly("dashboard_color", &alt::VehicleModelInfo::dashboardColor);
	pyClass.def_readonly("has_auto_attach_trailer", &alt::VehicleModelInfo::hasAutoAttachTrailer);

	pyClass.def_property_readonly("type", &GetType);
	pyClass.def_property_readonly("available_modkits", &GetAvailableModKits);

	pyClass.def("has_extra", &alt::VehicleModelInfo::DoesExtraExist, py::arg("extra_id"));
	pyClass.def("has_default_extra", &alt::VehicleModelInfo::DoesExtraDefault, py::arg("extra_id"));
}
