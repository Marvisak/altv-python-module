#include "vehicle.h"

void RegisterVehicleClass(const py::module_& m) {
    auto pyClass = py::class_<Vehicle, Entity>(m, "Vehicle");
    pyClass.def(py::init([](const std::string& model, double x, double y, double z, double rx, double ry, double rz) {return Vehicle(Core->Hash(model), x, y, z, rx, ry, rz);}));
}