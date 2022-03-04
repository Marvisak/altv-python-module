#include "vehicleneon.hpp"
#include "classes/classes.hpp"

std::string VehicleNeon::ToString() {
    return "VehicleNeon(left: " + std::to_string(left) + ", right: " + std::to_string(right) + ", front: " + std::to_string(front) + ", back: " + std::to_string((back)) + ")";
}

void RegisterVehicleNeonStruct(const py::module_& m) {
    auto pyClass = py::class_<VehicleNeon>(m, "VehicleNeon");
    pyClass.def(py::init<bool, bool, bool, bool>());
    pyClass.def_readwrite("left", &VehicleNeon::left);
    pyClass.def_readwrite("right", &VehicleNeon::right);
    pyClass.def_readwrite("front", &VehicleNeon::front);
    pyClass.def_readwrite("back", &VehicleNeon::back);
    pyClass.def("__str__", &VehicleNeon::ToString);
}
