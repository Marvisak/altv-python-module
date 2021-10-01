#include "classes/base/colshapes/colshapecuboid.h"
#include "classes/base/colshape.h"

void RegisterColshapeCuboidClass(const py::module_& m)
{
	auto pyClass = py::class_<ColshapeCuboid, Colshape>(m, "ColshapeCuboid");

	pyClass.def(py::init([](float x, float y, float z, float x2, float y2, float z2) { return ColshapeCuboid(ColshapeCuboid::Create(x, y, z, x2, y2, z2)); }));

	pyClass.def(py::init([](Vector3 pos, Vector3 pos2) { return ColshapeCuboid(ColshapeCuboid::Create(pos.x, pos.y, pos.z, pos2.x, pos2.y, pos2.z)); }));
}
