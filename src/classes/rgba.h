#pragma once

class RGBA {
public:
    unsigned char r, g, b, a;
    RGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : r(r), g(g), b(b), a(a) {}
    RGBA(alt::RGBA rgba) : r(rgba.r), g(rgba.g), b(rgba.b), a(rgba.a) {}

    static void RegisterRGBAClass(const py::module_& m)
    {
        py::class_<RGBA>(m, "RGBA")
            .def(py::init([](uint8_t _r, uint8_t _g, uint8_t _b, uint8_t _a) {return RGBA(_r, _g, _b, _a);}))
            .def_readwrite("r", &RGBA::r)
            .def_readwrite("g", &RGBA::g)
            .def_readwrite("b", &RGBA::b)
            .def_readwrite("a", &RGBA::a);
    }
};
