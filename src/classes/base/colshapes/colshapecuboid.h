#pragma once

#include "classes/base/colshape.h"

class ColshapeCuboid : public Colshape
{

 private:
	alt::Ref<alt::IColShape> colshape;

 public:
	static alt::Ref<alt::IColShape> Create(double x, double y, double z, double x2, double y2, double z2)
	{
		return Core->CreateColShapeCube(alt::Position(x, y, z), alt::Position(x2, y2, z2));
	}

	ColshapeCuboid(alt::Ref<alt::IColShape> colshape)
		: colshape(colshape), Colshape(colshape){};
};

void RegisterColshapeCuboidClass(const py::module_& m);
