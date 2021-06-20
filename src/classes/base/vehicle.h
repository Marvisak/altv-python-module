#pragma once

#include <main.h>

class Vehicle {
private:
    alt::Ref<alt::IVehicle> vehicle;
public:
    alt::Ref<alt::IVehicle> GetBaseObject() {
        return vehicle;
    }

    Vehicle(alt::Ref<alt::IVehicle> vehicle) : vehicle(vehicle) {}

};