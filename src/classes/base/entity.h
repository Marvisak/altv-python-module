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

    static py::object GetById(uint16_t number) {
        auto entity = Core->GetEntityByID(number);
        if (entity.Get() != nullptr)
            return py::cast(Entity(entity));
        return py::none();
    }

    static void RegisterEntityClass(const py::module_& m) {
        auto pyClass = py::class_<Entity, WorldObject>(m, "Entity");

        pyClass.def_property_readonly_static("all", &Entity::GetAllEntities);

        // ID
        pyClass.def_property_readonly("id", &Entity::GetID);
        pyClass.def_static("getById", &Entity::GetById);

        // Model
        pyClass.def_property_readonly("model", &Entity::GetModel);

        // NetOwner
        pyClass.def_property_readonly("netOwner", &Entity::GetNetOwner);
        pyClass.def("setNetOwner", &Entity::SetNetOwner, py::arg("player"), py::arg("disableMigration") = false);
        pyClass.def("resetNetOwner", &Entity::ResetNetOwner, py::arg("disableMigration") = false);

        // Rot
        pyClass.def_property("rot", &Entity::GetRotation, &Entity::SetRotation);

        // Visibility
        pyClass.def_property("visible", &Entity::GetVisible, &Entity::SetVisible);

        // MetaData
        pyClass.def("deleteStreamSyncedMeta", &Entity::DeleteStreamSyncedMetaData);
        pyClass.def("deleteSyncedMeta", &Entity::DeleteSyncedMetaData);
        pyClass.def("getStreamSyncedMeta", &Entity::GetStreamSyncedMetaData);
        pyClass.def("getSyncedMeta", &Entity::GetSyncedMetaData);
        pyClass.def("hasStreamSyncedMeta", &Entity::HasStreamSyncedMetaData);
        pyClass.def("hasSyncedMeta", &Entity::HasSyncedMetaData);
        pyClass.def("setStreamSyncedMeta", &Entity::SetStreamSyncedMetaData);
        pyClass.def("setSyncedMeta", &Entity::SetSyncedMetaData);

    }
};
