#include "colshaperectangle.h"
#include "classes/base/colshape.h"

void RegisterColshapeRectangleClass(const py::module_ &m)
{
    auto pyClass = py::class_<ColshapeRectangle, Colshape>(m, "ColshapeRectangle");

    pyClass.def(py::init([](float x, float y, float x2, float y2) { return ColshapeRectangle(ColshapeRectangle::Create(x, y, x2, y2)); }));
}
