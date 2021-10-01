#pragma once

#include "classes/base/colshape.h"

class ColshapeCircle : public Colshape
{

  private:
    alt::Ref<alt::IColShape> colshape;

  public:
    static alt::Ref<alt::IColShape> Create(double x, double y, double z, float radius)
    {
        return Core->CreateColShapeCircle(alt::Position(x, y, z), radius);
    }

    ColshapeCircle(alt::Ref<alt::IColShape> colshape) : colshape(colshape), Colshape(colshape){};
};

void RegisterColshapeCircleClass(const py::module_ &m);
