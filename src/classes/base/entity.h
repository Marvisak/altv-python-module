#pragma once
#include <main.h>
#include <utils.h>
#include <classes/base/worldobject.h>

class Player;
class Entity : public WorldObject {
private:
    alt::Ref<alt::IEntity> entity;
public:
    alt::Ref<alt::IEntity> GetBaseObject() {
        return entity;
    }

    Entity(alt::Ref<alt::IEntity> entity) : entity(entity), WorldObject(entity) {};


    // ID
    uint16_t GetID() const { return entity->GetID(); }

    // Model
    uint32_t GetModel() const { return entity->GetModel(); }

    // NetOwner
    Player GetNetOwner() const;


    // Rot
    Vector3 GetRotation() const { return entity->GetRotation(); }
    void SetRotation(Vector3 rotation) { entity->SetRotation(rotation.toAltRot()); }

    // Visibility
    bool GetVisible() const { return entity->GetVisible(); }
    void SetVisible(bool visible) const { return entity->SetVisible(visible); }


    static void RegisterEntityClass(const py::module_& m) {
        auto pyClass = py::class_<Entity, WorldObject>(m, "Entity");
        pyClass.def_property_readonly("id", &Entity::GetID);
        pyClass.def_property_readonly("model", &Entity::GetModel);
        pyClass.def_property_readonly("netOwner", &Entity::GetNetOwner);
        pyClass.def_property("rot", &Entity::GetRotation, &Entity::SetRotation);
        pyClass.def_property("visible", &Entity::GetVisible, &Entity::SetVisible);
    }
};
