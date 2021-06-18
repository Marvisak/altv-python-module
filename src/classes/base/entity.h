#pragma once
#include <main.h>
#include <utils.h>
#include <classes/vector3.h>
#include <classes/base/baseobject.h>

class Player;
class Entity : public BaseObject {
private:
    alt::Ref<alt::IEntity> entity;
public:
    alt::Ref<alt::IEntity> GetBaseObject() {
        return entity;
    }

    Entity(alt::Ref<alt::IEntity> entity) : entity(entity), BaseObject(entity) {};

    // Dimension
    int32_t GetDimension() const { return entity->GetDimension(); }
    void SetDimension(int32_t dimension) const { entity->SetDimension(dimension); }

    // ID
    uint16_t GetID() const { return entity->GetID(); }

    // Model
    uint32_t GetModel() const { return entity->GetModel(); }

    // NetOwner
    Player GetNetOwner() const;

    // Pos
    Vector3 GetPosition() const { return entity->GetPosition(); }
    void SetPosition(Vector3 pos) { entity->SetPosition(pos.toAltPos()); }

    // Rot
    Vector3 GetRotation() const { return entity->GetRotation(); }
    void SetRotation(Vector3 rotation) { entity->SetRotation(rotation.toAltRot()); }

    // Visibility
    bool GetVisible() const { return entity->GetVisible(); }
    void SetVisible(bool visible) const { return entity->SetVisible(visible); }


    static void RegisterEntityClass(const py::module_& m) {
        auto pyClass = py::class_<Entity, BaseObject>(m, "Entity");
        pyClass.def_property("dimension", &Entity::GetDimension, &Entity::SetDimension);
        pyClass.def_property_readonly("id", &Entity::GetID);
        pyClass.def_property_readonly("model", &Entity::GetModel);
        pyClass.def_property("pos", &Entity::GetPosition, &Entity::SetPosition);
        pyClass.def_property_readonly("netOwner", &Entity::GetNetOwner);
        pyClass.def_property("rot", &Entity::GetRotation, &Entity::SetRotation);
        pyClass.def_property("visible", &Entity::GetVisible, &Entity::SetVisible);
    }
};
