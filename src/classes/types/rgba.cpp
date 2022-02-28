#include "classes/classes.h"

std::string ToString(alt::RGBA _this) {
    return "RGBA(" + std::to_string(_this.r) + ", " + std::to_string(_this.g) + ", " + std::to_string(_this.b) + ", " + std::to_string(_this.a) + ")";
}

void RegisterRGBAClass(const py::module_& m) {
    auto pyClass = py::class_<alt::RGBA>(m, "RGBA");
    pyClass.def(py::init<uint8_t, uint8_t, uint8_t, uint8_t>(), py::arg("r"), py::arg("g"), py::arg("b"), py::arg("a"));
    pyClass.def_readwrite("r", &alt::RGBA::r);
    pyClass.def_readwrite("g", &alt::RGBA::g);
    pyClass.def_readwrite("b", &alt::RGBA::b);
    pyClass.def_readwrite("a", &alt::RGBA::a);
    pyClass.def("to_bgra", &alt::RGBA::toBGRA);
    pyClass.def("to_argb", &alt::RGBA::toARGB);
    pyClass.def("__str__", &ToString);
}
