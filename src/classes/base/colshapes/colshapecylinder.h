#pragma once

#include "classes/base/colshape.h"

class ColshapeCylinder : public Colshape
{

 private:
	alt::Ref<alt::IColShape> colshape;

 public:
	static alt::Ref<alt::IColShape> Create(double x, double y, double z, float radius, float height)
	{
		return Core->CreateColShapeCylinder(alt::Position(x, y, z), radius, height);
	}

	ColshapeCylinder(alt::Ref<alt::IColShape> colshape)
		: colshape(colshape), Colshape(colshape){};
};

void RegisterColshapeCylinderClass(const py::module_& m);
