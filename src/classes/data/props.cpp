//
// Created by Marlon on 31/07/2021.
//

#include "props.h"

void RegisterPropClass(const py::module_& m)
{
	auto pyClass = py::class_<Props>(m, "props");
	pyClass.def(py::init([](uint16_t _drawableId, uint8_t _textureId) { return Props(_drawableId, _textureId); }));
	pyClass.def_readwrite("drawableId", &Props::drawableId);
	pyClass.def_readwrite("textureId", &Props::textureId);
	pyClass.def("__str__", &Props::toString);
}
