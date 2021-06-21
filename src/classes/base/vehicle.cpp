#include "vehicle.h"



void RegisterVehicleClass(const py::module_& m) {
    auto pyClass = py::class_<Vehicle, Entity>(m, "Vehicle");
    pyClass.def(py::init([](const std::string& model, double x, double y, double z, double rx, double ry, double rz) {
        return Vehicle(Vehicle::SpawnVehicle(Core->Hash(model), x, y, z, rx, ry, rz));
    }));
    pyClass.def(py::init([](const std::string& model, Vector3 pos, double rx, double ry, double rz) {
        return Vehicle(Vehicle::SpawnVehicle(Core->Hash(model), pos.x, pos.y, pos.z, rx, ry, rz));
    }));
    pyClass.def(py::init([](const std::string& model, double x, double y, double z, Vector3 rot) {
        return Vehicle(Vehicle::SpawnVehicle(Core->Hash(model), x, y, z, rot.x, rot.y, rot.z));
    }));
    pyClass.def(py::init([](const std::string& model, Vector3 pos, Vector3 rot) {
        return Vehicle(Vehicle::SpawnVehicle(Core->Hash(model), pos.x, pos.y, pos.z, rot.x, rot.y, rot.z));
    }));
    pyClass.def(py::init([](uint32_t modelHash, double x, double y, double z, double rx, double ry, double rz) {
        return Vehicle(Vehicle::SpawnVehicle(modelHash, x, y, z, rx, ry, rz));
    }));
    pyClass.def(py::init([](uint32_t modelHash, Vector3 pos, double rx, double ry, double rz) {
        return Vehicle(Vehicle::SpawnVehicle(modelHash, pos.x, pos.y, pos.z, rx, ry, rz));
    }));
    pyClass.def(py::init([](uint32_t modelHash, double x, double y, double z, Vector3 rot) {
        return Vehicle(Vehicle::SpawnVehicle(modelHash, x, y, z, rot.x, rot.y, rot.z));
    }));
    pyClass.def(py::init([](uint32_t modelHash, Vector3 pos, Vector3 rot) {
        return Vehicle(Vehicle::SpawnVehicle(modelHash, pos.x, pos.y, pos.z, rot.x, rot.y, rot.z));
    }));
}