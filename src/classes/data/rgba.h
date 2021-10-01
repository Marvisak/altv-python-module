#pragma once

#include "main.h"

class RGBA {
public:
    unsigned char r, g, b, a;
    RGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : r(r), g(g), b(b), a(a) {}
    RGBA(alt::RGBA rgba) : r(rgba.r), g(rgba.g), b(rgba.b), a(rgba.a) {}

    alt::RGBA toAlt() const {
        return alt::RGBA{r,g,b,a};
    }
};

void RegisterRGBAClass(const py::module_& m);