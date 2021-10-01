//
// Created by Marlon on 31/07/2021.
//

#include "dlcprops.h"

void RegisterDlcPropClass(const py::module_& m) {
    auto pyClass = py::class_<DlcProps>(m, "dlcProps");
    pyClass.def(py::init([](uint32_t _dlc, uint8_t _drawableId, uint8_t _textureId) { return DlcProps(_dlc, _drawableId, _textureId); }));
    pyClass.def_readwrite("dlc", &DlcProps::dlc);
    pyClass.def_readwrite("drawableId", &DlcProps::drawableId);
    pyClass.def_readwrite("textureId", &DlcProps::textureId);
    pyClass.def("__str__", &DlcProps::toString);
}