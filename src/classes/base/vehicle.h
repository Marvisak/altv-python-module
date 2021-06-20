#pragma once

#include <main.h>
#include <classes/base/entity.h>

class Vehicle : public Entity {
private:
    alt::Ref<alt::IVehicle> vehicle;
    alt::Ref<alt::IVehicle> SpawnVehicle(uint32_t modelHash, double x, double y, double z, double rx, double ry, double rz) {
        return Core->CreateVehicle(modelHash, alt::Position(x, y, z), alt::Rotation(rx, ry, rz));
    }
public:
    alt::Ref<alt::IVehicle> GetBaseObject() {
        return vehicle;
    }

    Vehicle(alt::Ref<alt::IVehicle> vehicle) : vehicle(vehicle), Entity(vehicle) {}
    Vehicle(uint32_t modelHash, double x, double y, double z, double rx, double ry, double rz) : vehicle(
            SpawnVehicle(modelHash, x, y, z, rx, ry, rz)), Entity(vehicle) {}

};

void RegisterVehicleClass(const py::module_& m);