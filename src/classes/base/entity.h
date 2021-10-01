#pragma once
#include <utility>

#include "main.h"
#include "utils.h"
#include "worldobject.h"

class Player;
class Entity : public WorldObject {
private:
    alt::Ref<alt::IEntity> entity;
public:
    alt::Ref<alt::IEntity> GetBaseObject() {
        return entity;
    }

    Entity(alt::Ref<alt::IEntity> entity) : entity(entity), WorldObject(entity) {};

    static py::list GetAllEntities(const py::object& self) {
        auto entities = Core->GetEntities();
        py::list pyList;
        for (const auto& entity : entities) {
            pyList.append(py::cast(Entity(entity)));
        }
        return pyList;
    }

    // ID
    uint16_t GetID() const { return entity->GetID(); }

    // Model
    uint32_t GetModel() const { return entity->GetModel(); }

    // NetOwner
    Player GetNetOwner() const;
    void SetNetOwner(const Player& player, bool disableMigration=false);
    void ResetNetOwner(bool disableMigration=false) {
        entity->SetNetworkOwner(nullptr, disableMigration);
    }


    // Rot
    Vector3 GetRotation() const { return entity->GetRotation(); }
    void SetRotation(Vector3 rotation) { entity->SetRotation(rotation.toAltRot()); }

    // Visibility
    bool GetVisible() const { return entity->GetVisible(); }
    void SetVisible(bool visible) const { return entity->SetVisible(visible); }

    bool HasSyncedMetaData(const std::string& key) { return entity->HasSyncedMetaData(key); }
    py::object GetSyncedMetaData(const std::string& key) { return Utils::MValueToValue(entity->GetSyncedMetaData(key)); }
    bool HasStreamSyncedMetaData(const std::string& key) { return entity->HasStreamSyncedMetaData(key); }
    py::object GetStreamSyncedMetaData(const std::string& key) { return Utils::MValueToValue(entity->GetSyncedMetaData(key)); }

    void SetSyncedMetaData(const std::string& key, const py::object& val) { entity->SetSyncedMetaData(key, Utils::ValueToMValue(val));}
    void DeleteSyncedMetaData(const std::string& key) { entity->DeleteSyncedMetaData(key); }
    void SetStreamSyncedMetaData(const std::string& key, const py::object& val) { entity->SetStreamSyncedMetaData(key, Utils::ValueToMValue(val)); }
    void DeleteStreamSyncedMetaData(const std::string& key) { entity->DeleteStreamSyncedMetaData(key); }

    void AttachEntityToEntity(alt::Ref<alt::IEntity> otherEntity, int16_t otherBoneIndex, int16_t myBoneIndex, Vector3 position, Vector3 rotation, bool collision, bool noFixedRot) { entity->AttachToEntity(otherEntity, otherBoneIndex, myBoneIndex, position.toAltPos(), rotation.toAltRot(), collision, noFixedRot); }
    void Detach() { entity->Detach(); }

    void SetStreamed(bool toggle) { entity->SetStreamed(toggle); }
    bool GetStreamed() const { return entity->GetStreamed(); }

    static py::object GetById(uint16_t number) {
        auto entity = Core->GetEntityByID(number);
        if (entity.Get() != nullptr)
            return py::cast(Entity(entity));
        return py::none();
    }
};

void RegisterEntityClass(const py::module_& m);
