//
// Created by Marlon on 30/07/2021.
//

#include "dlcclothes.h"

void RegisterDlcClothesClass(const py::module_& m) {
    auto pyClass = py::class_<DlcClothes>(m, "dlcClothes");
    pyClass.def(py::init([](uint32_t _dlc, uint16_t _drawableId, uint8_t _textureId, uint8_t _paletteId) { return DlcClothes(_dlc, _drawableId, _textureId, _paletteId);}));
    pyClass.def_readwrite("dlc", &DlcClothes::dlc);
    pyClass.def_readwrite("drawableId", &DlcClothes::drawableId);
    pyClass.def_readwrite("textureId", &DlcClothes::textureId);
    pyClass.def_readwrite("paletteId", &DlcClothes::paletteId);
    pyClass.def("__str__", &DlcClothes::toString);
}
