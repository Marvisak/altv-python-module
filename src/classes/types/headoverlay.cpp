#include "classes/classes.h"

std::string ToString(alt::HeadOverlay _this) {
    return "HeadOverlay(index: " + std::to_string(_this.index) + ", opacity: " + std::to_string(_this.opacity) + ", colorType: " + std::to_string(_this.colorType) + ", colorIndex: " + std::to_string(_this.colorIndex) + ", secondColorIndex: " + std::to_string(_this.secondColorIndex) + ")";
}

void RegisterHeadOverlayClass(const py::module_& m) {
    auto pyClass = py::class_<alt::HeadOverlay>(m, "HeadOverlay");
    pyClass.def(py::init<uint8_t, float, uint8_t, uint8_t, uint8_t>(), py::arg("index"), py::arg("opacity"), py::arg("color_type"), py::arg("color_index"), py::arg("second_color_index"));
    pyClass.def_readwrite("index", &alt::HeadOverlay::index);
    pyClass.def_readwrite("opacity", &alt::HeadOverlay::opacity);
    pyClass.def_readwrite("color_type", &alt::HeadOverlay::colorType);
    pyClass.def_readwrite("color_index", &alt::HeadOverlay::colorIndex);
    pyClass.def_readwrite("second_color_index", &alt::HeadOverlay::secondColorIndex);
    pyClass.def("__str__", &ToString);
}