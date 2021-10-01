#pragma once

#include "classes/base/colshape.h"

class ColshapeRectangle : public Colshape
{

  private:
    alt::Ref<alt::IColShape> colshape;

  public:
    static alt::Ref<alt::IColShape> Create(float x, float y, float x2, float y2)
    {
        return Core->CreateColShapeRectangle(x, y, x2, y2, 0);
    }

    ColshapeRectangle(alt::Ref<alt::IColShape> colshape) : colshape(colshape), Colshape(colshape){};
};

void RegisterColshapeRectangleClass(const py::module_ &m);
