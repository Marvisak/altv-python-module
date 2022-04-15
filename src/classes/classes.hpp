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
void RegisterVehicleNeonStruct(const py::module_& m);
void RegisterRGBAClass(const py::module_& m);
void RegisterHeadOverlayClass(const py::module_& m);
void RegisterHeadBlendData(const py::module_& m);
void RegisterWeaponClass(const py::module_& m);
void RegisterClothClass(const py::module_& m);
void RegisterDlcClothClass(const py::module_& m);
void RegisterPropClass(const py::module_& m);
void RegisterDlcPropClass(const py::module_& m);
void RegisterVector3Class(const py::module_& m);
void RegisterBaseObjectClass(const py::module_& m);
void RegisterWorldObjectClass(const py::module_& m);
void RegisterEntityClass(const py::module_& m);
void RegisterPlayerClass(const py::module_& m);
void RegisterVehicleClass(const py::module_& m);
