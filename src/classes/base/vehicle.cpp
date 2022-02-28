#pragma once
#include "classes/classes.h"
#include "classes/types/vector3.h"

PYBIND11_DECLARE_HOLDER_TYPE(T, alt::Ref<T>, true)

namespace pybind11::detail {
    template <typename T>
    struct holder_helper<alt::Ref<T>> {
        static const T* get(const alt::Ref<T> &p) { return p.Get(); }
    };
}

alt::Ref<alt::IVehicle> CreateVehicle(uint32_t hash, alt::Position pos, alt::Rotation rot) {
    auto vehicle = alt::ICore::Instance().CreateVehicle(hash, pos, rot);
    if (vehicle)
        return vehicle;
    throw std::exception("Failed to create vehicle");
}


void RegisterVehicleClass(const py::module_& m) {
    auto pyClass = py::class_<alt::IVehicle, alt::IEntity, alt::Ref<alt::IVehicle>>(m, "Vehicle");
}
