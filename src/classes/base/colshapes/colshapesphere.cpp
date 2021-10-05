#include "colshapesphere.h"
#include "classes/base/colshape.h"

void RegisterColshapeSphereClass(const py::module_& m)
{
	auto pyClass = py::class_<ColshapeSphere, Colshape>(m, "ColshapeSphere");

	pyClass.def(py::init([](float x, float y, float z, float radius) { return ColshapeSphere(ColshapeSphere::Create(x, y, z, radius)); }));

	pyClass.def(py::init([](Vector3 pos, float radius) { return ColshapeSphere(ColshapeSphere::Create(pos.x, pos.y, pos.z, radius)); }));
}
