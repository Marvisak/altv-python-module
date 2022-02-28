#include "classes/classes.h"

std::string ToString(alt::Weapon _this) {
    return "Weapon(hash: " + std::to_string(_this.hash) + ", tintIndex: " + std::to_string(_this.tintIndex) + ", components: " + std::to_string(_this.components.size()) + ")";
}

void RegisterWeaponClass(const py::module_& m) {
    auto pyClass = py::class_<alt::Weapon>(m, "Weapon");
    pyClass.def(py::init<uint32_t, uint8_t, std::unordered_set<uint32_t>>(), py::arg("drawable"), py::arg("texture"), py::arg("palette"));
    pyClass.def_readwrite("hash", &alt::Weapon::hash);
    pyClass.def_readwrite("tint_index", &alt::Weapon::tintIndex);
    pyClass.def_readwrite("components", &alt::Weapon::components);
    pyClass.def("__str__", &ToString);
}