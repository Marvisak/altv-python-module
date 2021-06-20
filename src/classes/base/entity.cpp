#include "entity.h"
#include <classes/base/player.h>

Player Entity::GetNetOwner() const {
    return entity->GetNetworkOwner();
}

void Entity::SetNetOwner(const Player& player, bool disableMigration) {
    entity->SetNetworkOwner(player.GetBaseObject(), disableMigration);
}

void RegisterEntityClass(const py::module_ &m) {
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