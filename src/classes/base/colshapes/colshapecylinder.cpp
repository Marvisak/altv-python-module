#include "classes/base/colshape.h"
#include "classes/base/colshapes/colshapecylinder.h"

void RegisterColshapeCylinderClass(const py::module_ &m) {
    auto pyClass = py::class_<ColshapeCylinder, Colshape>(m, "ColshapeCylinder");

    pyClass.def(py::init([](float x, float y, float z, float radius, float height) {
        return ColshapeCylinder(ColshapeCylinder::Create(x, y, z, radius, height));
    }));

    pyClass.def(py::init([](Vector3 pos, float radius, float height) {
        return ColshapeCylinder(ColshapeCylinder::Create(pos.x, pos.y, pos.z, radius, height));
    }));
}
