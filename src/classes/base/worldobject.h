#pragma once

#include "main.h"
#include "baseobject.h"
#include "classes/vector3.h"

class WorldObject : public BaseObject {
private:
    alt::Ref<alt::IWorldObject> worldObject;
public:

    WorldObject(alt::Ref<alt::IWorldObject> worldObject) : worldObject(worldObject), BaseObject(worldObject) {}

    // Pos
    Vector3 GetPosition() const { return worldObject->GetPosition(); }
    void SetPosition(Vector3 pos) { worldObject->SetPosition(pos.toAltPos()); }

    // Dimension
    int32_t GetDimension() const { return worldObject->GetDimension(); }
    void SetDimension(int32_t dimension) const { worldObject->SetDimension(dimension); }

};

void RegisterWorldObjectClass(const py::module_& m);