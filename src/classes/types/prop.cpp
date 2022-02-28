#include "classes/classes.h"

std::string ToString(alt::Prop _this) {
    return "Prop(drawable: " + std::to_string(_this.drawableId) + ", texture: " + std::to_string(_this.textureId) + ")";
}

void RegisterPropClass(const py::module_& m) {
    auto pyClass = py::class_<alt::Prop>(m, "Prop");
    pyClass.def(py::init<uint16_t, uint8_t>(), py::arg("drawable"), py::arg("texture"));
    pyClass.def_readwrite("drawable", &alt::Prop::drawableId);
    pyClass.def_readwrite("texture", &alt::Prop::textureId);
    pyClass.def("__str__", &ToString);
}