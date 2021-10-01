#include "classes/base/colshape.h"
#include "classes/base/worldobject.h"

void RegisterColshapeClass(const py::module_& m)
{
	auto pyClass = py::class_<Colshape, WorldObject>(m, "Colshape");

	// Methods
	pyClass.def("isPointIn", &Colshape::IsPointIn, py::arg("vector"));
	pyClass.def("isEntityIn", &Colshape::IsEntityIn, py::arg("entity"));

	// Properties
	pyClass.def_property("playersOnly", &Colshape::GetPlayersOnly, &Colshape::SetPlayersOnly);
	pyClass.def_property_readonly("colshapeType", &Colshape::GetColshapeType);
}
