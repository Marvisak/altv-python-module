#pragma once
#include "main.hpp"

void RegisterEnums(const py::module_& m);
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
