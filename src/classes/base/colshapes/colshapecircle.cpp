#include "classes/base/colshape.h"
#include "colshapecircle.h"

void RegisterColshapeCircleClass(const py::module_ &m) {
	auto pyClass = py::class_<ColshapeCircle, Colshape>(m, "ColshapeCircle");

	pyClass.def(py::init([](float x, float y, float z, float radius, float height) {
		return ColshapeCircle(ColshapeCircle::Create(x, y, z, radius));
	}));

	pyClass.def(py::init([](Vector3 pos, float radius, float height) {
		return ColshapeCircle(ColshapeCircle::Create(pos.x, pos.y, pos.z, radius));
	}));
}
