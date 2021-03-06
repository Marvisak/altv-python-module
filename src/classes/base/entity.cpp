#include "classes/classes.hpp"
#include "classes/types/vector3.hpp"
#include "utils.hpp"

py::list GetAllEntities(const py::object& type)
{
	py::list list;
	auto array = alt::ICore::Instance().GetEntities();
	for (const auto& entity : array)
		list.append(Utils::GetBaseObject(entity));
	return list;
}

py::object GetEntityById(uint16_t id)
{
	return Utils::GetBaseObject(alt::ICore::Instance().GetEntityByID(id));
}

Vector3 GetRotation(alt::IEntity* _this)
{
	return (Vector3)_this->GetRotation();
}

void SetRotation(alt::IEntity* _this, Vector3 rot)
{
	_this->SetRotation(rot.ToAlt());
}

void AttachToEntity(alt::IEntity* _this, alt::IEntity* entity, int16_t entityBoneId, int16_t ownBoneId, Vector3 pos, Vector3 rot, bool enableCollisions, bool noFixedRotation)
{
	_this->AttachToEntity(entity, entityBoneId, ownBoneId, pos.ToAlt(), rot.ToAlt(), enableCollisions, noFixedRotation);
}

py::object GetSyncedMeta(alt::IEntity* _this, const std::string& key)
{
	return Utils::MValueToValue(_this->GetSyncedMetaData(key));
}

py::object GetStreamSyncedMeta(alt::IEntity* _this, const std::string& key)
{
	return Utils::MValueToValue(_this->GetStreamSyncedMetaData(key));
}

void SetSyncedMeta(alt::IEntity* _this, const std::string& key, const py::object& value)
{
	_this->SetSyncedMetaData(key, Utils::ValueToMValue(value));
}

void SetStreamSyncedMeta(alt::IEntity* _this, const std::string& key, const py::object& value)
{
	_this->SetStreamSyncedMetaData(key, Utils::ValueToMValue(value));
}

void ResetNetOwner(alt::IEntity* _this, bool disable_migration)
{
	_this->SetNetworkOwner(nullptr, disable_migration);
}

void SetModel(alt::IPlayer* _this, const py::object& object)
{
	if (py::isinstance<py::str>(object))
		_this->SetModel(alt::ICore::Instance().Hash(object.cast<std::string>()));
	else if (py::isinstance<py::int_>(object))
		_this->SetModel(object.cast<int>());
	else
		throw py::value_error("int or str expected");
}

void RegisterEntityClass(const py::module_& m)
{
	auto pyClass = py::class_<alt::IEntity, alt::IWorldObject, alt::Ref<alt::IEntity>>(m, "Entity");

	// Static
	pyClass.def_property_readonly_static("all", &GetAllEntities);
	pyClass.def_static("get_by_id", &GetEntityById, py::arg("id"));

	// Entity Data
	pyClass.def_property_readonly("id", &alt::IEntity::GetID);
	pyClass.def_property("rot", &GetRotation, &SetRotation);
	pyClass.def_property("streamed", &alt::IEntity::GetStreamed, &alt::IEntity::SetStreamed);
	pyClass.def_property("visible", &alt::IEntity::GetVisible, &alt::IEntity::SetVisible);
	pyClass.def_property("collision", &alt::IEntity::HasCollision, &alt::IEntity::SetCollision);
	pyClass.def_property("frozen", &alt::IEntity::IsFrozen, &alt::IEntity::SetFrozen);

	// Model
	pyClass.def_property("model", &alt::IEntity::GetModel, &SetModel);

	// NetOwner
	pyClass.def_property_readonly("net_owner", &alt::IEntity::GetNetworkOwner);
	pyClass.def("set_net_owner", &alt::IEntity::SetNetworkOwner, py::arg("player"), py::arg("disable_migration") = false);
	pyClass.def("reset_net_owner", &ResetNetOwner, py::arg("disable_migration") = false);

	// Attach
	pyClass.def("attach_to", &AttachToEntity, py::arg("entity"), py::arg("entity_bone_id"), py::arg("own_bone_id"), py::arg("pos"), py::arg("rot"), py::arg("enable_collisions"), py::arg("no_fixed_rotation"));
	pyClass.def("detach", &alt::IEntity::Detach);

	// Synced MetaData
	pyClass.def("get_synced_meta", &GetSyncedMeta, py::arg("key"));
	pyClass.def("has_synced_meta", &alt::IEntity::HasSyncedMetaData, py::arg("key"));
	pyClass.def("set_synced_meta", &SetSyncedMeta, py::arg("key"), py::arg("value"));
	pyClass.def("delete_synced_meta", &alt::IEntity::DeleteSyncedMetaData, py::arg("key"));

	// Stream Synced MetaData
	pyClass.def("get_stream_synced_meta", &GetStreamSyncedMeta, py::arg("key"));
	pyClass.def("has_stream_synced_meta", &alt::IEntity::HasStreamSyncedMetaData, py::arg("key"));
	pyClass.def("set_stream_synced_meta", &SetStreamSyncedMeta, py::arg("key"), py::arg("value"));
	pyClass.def("delete_stream_synced_meta", &alt::IEntity::DeleteStreamSyncedMetaData, py::arg("key"));
}
