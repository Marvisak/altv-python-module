//
// Created by Marlon on 30/07/2021.
//

#include "clothes.h"

void RegisterClothesClass(const py::module_ &m)
{
    auto pyClass = py::class_<Clothes>(m, "clothes");
    pyClass.def(py::init([](uint16_t _drawableId, uint8_t _textureId, uint8_t _paletteId) { return Clothes(_drawableId, _textureId, _paletteId); }));
    pyClass.def_readwrite("drawableId", &Clothes::drawableId);
    pyClass.def_readwrite("textureId", &Clothes::textureId);
    pyClass.def_readwrite("paletteId", &Clothes::paletteId);
    pyClass.def("__str__", &Clothes::toString);
}
