#pragma once
#include "classes/base/entity.h"
#include "classes/base/worldobject.h"
#include "classes/data/vector3.h"

class Colshape : public WorldObject
{
  private:
    alt::Ref<alt::IColShape> colshape;

  public:
    bool IsEntityIn(Entity entity)
    {
        return colshape->IsEntityIn(entity.GetBaseObject());
    }
    bool IsPointIn(Vector3 vector)
    {
        return colshape->IsPointIn(vector.toAltPos());
    };

    // Getters
    bool GetPlayersOnly()
    {
        return colshape->IsPlayersOnly();
    }
    uint8_t GetColshapeType()
    {
        return static_cast<uint8_t>(colshape->GetColshapeType());
    }

    // Setters
    void SetPlayersOnly(bool playerOnly)
    {
        colshape->SetPlayersOnly(playerOnly);
    }

    Colshape(alt::Ref<alt::IColShape> colshape) : colshape(colshape), WorldObject(colshape)
    {
    }
};

void RegisterColshapeClass(const py::module_ &m);
