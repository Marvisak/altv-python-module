#include "classes/classes.hpp"
#include "classes/types/vector3.hpp"
#include "classes/types/enums.hpp"

alt::ICheckpoint* CreateCheckpoint(uint8_t type, alt::Position pos, float radius, float height, alt::RGBA color) {
	auto checkpoint = alt::ICore::Instance().CreateCheckpoint(type, pos, radius, height, color);
	if (checkpoint)
		return checkpoint.Get();
	throw std::runtime_error("Failed to create Checkpoint");
}

CheckpointType GetCheckpointType(alt::ICheckpoint* _this) {
	return (CheckpointType)_this->GetCheckpointType();
}

void RegisterCheckpointClass(const py::module_& m) {
	auto pyClass = py::class_<alt::ICheckpoint, alt::Ref<alt::ICheckpoint>, alt::IColShape>(m, "Checkpoint");

	pyClass.def(py::init<>([](uint8_t type, double x, double y, double z, float radius, float height, uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
		return CreateCheckpoint(type, alt::Position(x, y, z), radius, height, alt::RGBA(r, g, b, a));
	}), py::arg("type"), py::arg("x"), py::arg("y"), py::arg("z"), py::arg("radius"), py::arg("height"), py::arg("r"), py::arg("g"), py::arg("b"), py::arg("a"));

	pyClass.def(py::init<>([](uint8_t type, Vector3 pos, float radius, float height, alt::RGBA color) {
		return CreateCheckpoint(type, pos.ToAlt(), radius, height, color);
	}), py::arg("type"), py::arg("pos"), py::arg("radius"), py::arg("height"), py::arg("color"));


	// TODO Once setters start working change them to normal properties
	pyClass.def_property_readonly("checkpoint_type", &GetCheckpointType);
	pyClass.def_property_readonly("height", &alt::ICheckpoint::GetHeight);
	pyClass.def_property_readonly("radius", &alt::ICheckpoint::GetRadius);
	pyClass.def_property_readonly("color", &alt::ICheckpoint::GetColor);
}
