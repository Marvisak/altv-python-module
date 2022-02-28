#include "classes/classes.h"

std::string ToString(alt::DlcCloth _this) {
    return "DlcCloth(dlc: " + std::to_string(_this.dlc) + ", drawable: " + std::to_string(_this.drawableId) + ", texture: " + std::to_string(_this.textureId) + ", palette: " + std::to_string(_this.paletteId) + ")";
}

void RegisterDlcClothClass(const py::module_& m) {
    auto pyClass = py::class_<alt::DlcCloth>(m, "DlcCloth");
    pyClass.def(py::init<uint32_t, uint16_t, uint8_t, uint8_t>(), py::arg("dlc"), py::arg("drawable"), py::arg("texture"), py::arg("palette"));
    pyClass.def_readwrite("dlc", &alt::DlcCloth::dlc);
    pyClass.def_readwrite("drawable", &alt::DlcCloth::drawableId);
    pyClass.def_readwrite("texture", &alt::DlcCloth::textureId);
    pyClass.def_readwrite("palette", &alt::DlcCloth::paletteId);
    pyClass.def("__str__", &ToString);
}