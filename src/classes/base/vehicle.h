#pragma once

#include "main.h"
#include "classes/vector3.h"
#include "entity.h"

class Vehicle : public Entity {
private:
    alt::Ref<alt::IVehicle> vehicle;
public:
    static alt::Ref<alt::IVehicle> SpawnVehicle(uint32_t modelHash, double x, double y, double z, double rx, double ry, double rz) {
        return Core->CreateVehicle(modelHash, alt::Position(x, y, z), alt::Rotation(rx, ry, rz));
    }

    alt::Ref<alt::IVehicle> GetBaseObject() {
        return vehicle;
    }

    Vehicle(alt::Ref<alt::IVehicle> vehicle) : vehicle(vehicle), Entity(vehicle) {}

};

void RegisterVehicleClass(const py::module_& m);