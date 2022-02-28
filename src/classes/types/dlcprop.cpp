#include "classes/classes.hpp"

std::string ToString(alt::DlcProp _this) {
    return "DlcProp(dlc: " + std::to_string(_this.dlc) + ", drawable: " + std::to_string(_this.drawableId) + ", texture: " + std::to_string(_this.textureId) + ")";
}

void RegisterDlcPropClass(const py::module_& m) {
    auto pyClass = py::class_<alt::DlcProp>(m, "DlcProp");
    pyClass.def(py::init<uint32_t, uint8_t, uint8_t>(), py::arg("dlc"), py::arg("drawable"), py::arg("texture"));
    pyClass.def_readwrite("dlc", &alt::DlcProp::dlc);
    pyClass.def_readwrite("drawable", &alt::DlcProp::drawableId);
    pyClass.def_readwrite("texture", &alt::DlcProp::textureId);
    pyClass.def("__str__", &ToString);
}