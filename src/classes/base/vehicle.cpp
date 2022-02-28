#pragma once
#include "classes/classes.hpp"
#include "classes/types/vector3.hpp"

PYBIND11_DECLARE_HOLDER_TYPE(T, alt::Ref<T>, true)

namespace pybind11::detail {
    template <typename T>
    struct holder_helper<alt::Ref<T>> {
        static const T* get(const alt::Ref<T> &p) { return p.Get(); }
    };
}

alt::IVehicle* CreateVehicle(uint32_t hash, alt::Position pos, alt::Rotation rot) {
    auto vehicle = alt::ICore::Instance().CreateVehicle(hash, pos, rot);
    if (vehicle)
        return vehicle.Get();
    throw std::exception("Failed to create vehicle");
}


void RegisterVehicleClass(const py::module_& m) {
    auto pyClass = py::class_<alt::IVehicle, alt::IEntity, alt::Ref<alt::IVehicle>>(m, "Vehicle");
    pyClass.def(py::init<>([](const std::string& model, float x, float y, float z, float rx, float ry, float rz) {
        auto hash = alt::ICore::Instance().Hash(model);
        return CreateVehicle(hash, alt::Position(x, y, z), alt::Rotation(rx, ry, rz));
    }));
    pyClass.def(py::init<>([](uint32_t hash, float x, float y, float z, float rx, float ry, float rz) {
        return CreateVehicle(hash, alt::Position(x, y, z), alt::Rotation(rx, ry, rz));
    }));
    pyClass.def(py::init<>([](const std::string& model, Vector3 pos, Vector3 rot) {
        auto hash = alt::ICore::Instance().Hash(model);
        return CreateVehicle(hash, pos.ToAltPos(), rot.ToAltRot());
    }));
    pyClass.def(py::init<>([](uint32_t hash, Vector3 pos, Vector3 rot) {
        return CreateVehicle(hash, pos.ToAltPos(), rot.ToAltRot());
    }));
}
