#include "rgba.h"

void RegisterRGBAClass(const py::module_& m) {
    auto pyClass = py::class_<RGBA>(m, "RGBA");
    pyClass.def(py::init([](uint8_t _r, uint8_t _g, uint8_t _b, uint8_t _a) {return RGBA(_r, _g, _b, _a);}));
    pyClass.def_readwrite("r", &RGBA::r);
    pyClass.def_readwrite("g", &RGBA::g);
    pyClass.def_readwrite("b", &RGBA::b);
    pyClass.def_readwrite("a", &RGBA::a);
}
