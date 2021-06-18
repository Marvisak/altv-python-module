#pragma once

#include <main.h>
#include <classes/base/baseobject.h>
#include <classes/vector3.h>

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

    static void RegisterWorldObjectClass(const py::module_& m) {
        auto pyClass = py::class_<WorldObject, BaseObject>(m, "WorldObject");
        pyClass.def_property("pos", &WorldObject::GetPosition, &WorldObject::SetPosition);
        pyClass.def_property("dimension", &WorldObject::GetDimension, &WorldObject::SetDimension);
    }

};