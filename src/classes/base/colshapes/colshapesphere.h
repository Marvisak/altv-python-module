#pragma once

#include "classes/base/colshape.h"

class ColshapeSphere : public Colshape
{

 private:
	alt::Ref<alt::IColShape> colshape;

 public:
	static alt::Ref<alt::IColShape> Create(double x, double y, double z, float radius)
	{
		return Core->CreateColShapeSphere(alt::Position(x, y, z), radius);
	}

	ColshapeSphere(alt::Ref<alt::IColShape> colshape)
		: colshape(colshape), Colshape(colshape){};
};

void RegisterColshapeSphereClass(const py::module_& m);
