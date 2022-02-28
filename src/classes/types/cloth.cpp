#include "classes/classes.hpp"

std::string ToString(alt::Cloth _this) {
    return "Cloth(drawable: " + std::to_string(_this.drawableId) + ", texture: " + std::to_string(_this.textureId) + ", palette: " + std::to_string(_this.paletteId) + ")";
}

void RegisterClothClass(const py::module_& m) {
    auto pyClass = py::class_<alt::Cloth>(m, "Cloth");
    pyClass.def(py::init<uint16_t, uint8_t, uint8_t>(), py::arg("drawable"), py::arg("texture"), py::arg("palette"));
    pyClass.def_readwrite("drawable", &alt::Cloth::drawableId);
    pyClass.def_readwrite("texture", &alt::Cloth::textureId);
    pyClass.def_readwrite("palette", &alt::Cloth::paletteId);
    pyClass.def("__str__", &ToString);
}