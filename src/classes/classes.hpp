#pragma once
#include "main.hpp"

PYBIND11_DECLARE_HOLDER_TYPE(T, alt::Ref<T>, true)

namespace pybind11::detail {
	template <typename T>
	struct holder_helper<alt::Ref<T>> {
		static const T* get(const alt::Ref<T> &p) { return p.Get(); }
	};
}

void RegisterEnums(const py::module_& m);
void RegisterRGBAClass(const py::module_& m);
void RegisterConnectionInfoClass(const py::module_& m);
void RegisterVehicleModelInfoClass(const py::module_& m);
void RegisterVector2Class(const py::module_& m);
void RegisterVector3Class(const py::module_& m);
void RegisterBaseObjectClass(const py::module_& m);
void RegisterWorldObjectClass(const py::module_& m);
void RegisterEntityClass(const py::module_& m);
void RegisterPlayerClass(const py::module_& m);
void RegisterVehicleClass(const py::module_& m);
void RegisterColShapeClass(const py::module_& m);
void RegisterResourceClass(const py::module_& m);
void RegisterBlipClass(const py::module_& m);
void RegisterCheckpointClass(const py::module_& m);
void RegisterVoiceChannelClass(const py::module_& m);
