#include "classes/types/vector3.hpp"
#include "classes/types/enums.hpp"
#include "classes/classes.hpp"
#include "utils.hpp"


py::list GetAllPlayers(const py::object& type) {
    return Utils::ArrayToPyList<alt::Ref<alt::IPlayer>>(alt::ICore::Instance().GetPlayers());
}

alt::IPlayer* GetPlayerById(uint16_t id) {
    auto entity = alt::ICore::Instance().GetEntityByID(id);
    if (entity && entity->GetType() == alt::IBaseObject::Type::PLAYER)
        return dynamic_cast<alt::IPlayer*>(entity.Get());
    return nullptr;
}

void Spawn(alt::IPlayer* _this, float x, float y, float z, uint32_t delay = 0) {
	alt::Position altPos{x, y, z};
    _this->Spawn(altPos, delay);
}

void Spawn(alt::IPlayer* _this, Vector3 pos, uint32_t delay = 0) {
    _this->Spawn(pos.ToAlt(), delay);
}

py::list GetCurrentWeaponComponents(alt::IPlayer* _this) {
    return Utils::ArrayToPyList<uint32_t>(_this->GetCurrentWeaponComponents());
}

py::list GetWeapons(alt::IPlayer* _this) {
	py::list list;
	alt::Array<alt::Weapon> weapons = _this->GetWeapons();
	for (const alt::Weapon& weapon : weapons) {
		py::dict dict;
		dict["hash"] = weapon.hash;
		dict["tint_index"] = weapon.tintIndex;
		dict["components"] = weapon.components;
		list.append(dict);
	}
    return list;
}

void SetDlcClothes(alt::IPlayer* _this, uint32_t dlc, uint8_t component, uint16_t drawable, uint8_t texture, uint8_t palette = 2) {
    if (drawable < 128)
        _this->SetDlcClothes(component, drawable, texture, palette, dlc);
    else
        throw py::value_error("Drawable can't be higher than 127");
}

bool SetDlcProps(alt::IPlayer* _this, uint32_t dlc, uint8_t component, uint8_t drawable, uint8_t texture ) {
    return _this->SetDlcProps(component, drawable, texture, dlc);
}

Vector3 GetAimPos(alt::IPlayer* _this) {
    return (Vector3)_this->GetAimPos();
}

Vector3 GetHeadRot(alt::IPlayer* _this) {
    return (Vector3)_this->GetHeadRotation();
}

py::object GetEntityAimingAt(alt::IPlayer* _this) {
    return Utils::GetBaseObject(_this->GetEntityAimingAt());
}

WeaponTint GetCurrentWeaponTintIndex(alt::IPlayer* _this) {
    return (WeaponTint)_this->GetCurrentWeaponTintIndex();
}

Vector3 GetEntityAimOffset(alt::IPlayer* _this) {
    return (Vector3)_this->GetEntityAimOffset();
}

py::dict GetClothes(alt::IPlayer* _this, uint8_t component) {
	alt::Cloth cloth = _this->GetClothes(component);
	py::dict dict;
	dict["drawable"] = cloth.drawableId;
	dict["texture"] = cloth.textureId;
	dict["palette"] = cloth.paletteId;
	return dict;
}

py::dict GetDlcClothes(alt::IPlayer* _this, uint8_t component) {
	alt::DlcCloth dlcCloth = _this->GetDlcClothes(component);
	py::dict dict;
	dict["dlc"] = dlcCloth.dlc;
	dict["drawable"] = dlcCloth.drawableId;
	dict["texture"] = dlcCloth.textureId;
	dict["palette"] = dlcCloth.paletteId;
	return dict;
}

py::dict GetDlcProp(alt::IPlayer* _this, uint8_t component) {
	alt::DlcProp dlcProp = _this->GetDlcProps(component);
	py::dict dict;
	dict["dlc"] = dlcProp.dlc;
	dict["drawable"] = dlcProp.drawableId;
	dict["texture"] = dlcProp.textureId;
	return dict;
}

py::dict GetHeadBlendData(alt::IPlayer* _this) {
	alt::HeadBlendData headBlendData = _this->GetHeadBlendData();
	py::dict dict;
	dict["shape_first_id"] = headBlendData.shapeFirstID;
	dict["shape_second_id"] = headBlendData.shapeSecondID;
	dict["shape_third_id"] = headBlendData.shapeThirdID;
	dict["skin_first_id"] = headBlendData.skinFirstID;
	dict["skin_second_id"] = headBlendData.skinSecondID;
	dict["skin_third_id"] = headBlendData.skinThirdID;
	dict["shape_mix"] = headBlendData.shapeMix;
	dict["skin_mix"] = headBlendData.skinMix;
	dict["third_mix"] = headBlendData.thirdMix;
	return dict;
}

py::dict GetHeadOverlay(alt::IPlayer* _this, uint8_t overlayId) {
	alt::HeadOverlay headOverlay = _this->GetHeadOverlay(overlayId);
	py::dict dict;
	dict["index"] = headOverlay.index;
	dict["opacity"] = headOverlay.opacity;
	dict["color_type"] = headOverlay.colorType;
	dict["color_index"] = headOverlay.colorIndex;
	dict["second_color_index"] = headOverlay.secondColorIndex;
	return dict;
}

py::dict GetProps(alt::IPlayer* _this, uint8_t component) {
	alt::Prop prop = _this->GetProps(component);
	py::dict dict;
	dict["drawable"] = prop.drawableId;
	dict["texture"] = prop.textureId;
	return dict;
}


py::object GetLocalMeta(alt::IPlayer* _this, const std::string& key) {
    return Utils::MValueToValue(_this->GetLocalMetaData(key));
}

void SetLocalMeta(alt::IPlayer* _this, const std::string& key, const py::object& value) {
    _this->SetLocalMetaData(key, Utils::ValueToMValue(value));
}

void Emit(alt::IPlayer* _this, const std::string& eventName, const py::args& args) {
	alt::MValueArgs eventArgs;
	for (const py::handle& arg : *args)
		eventArgs.Push(Utils::ValueToMValue(arg.cast<py::object>()));
	alt::ICore::Instance().TriggerClientEvent(_this, eventName, eventArgs);
}


void RegisterPlayerClass(const py::module_& m) {
    auto pyClass = py::class_<alt::IPlayer, alt::IEntity, alt::Ref<alt::IPlayer>>(m, "Player", py::multiple_inheritance());

    // Static
    pyClass.def_property_readonly_static("all", &GetAllPlayers);
    pyClass.def_static("get_by_id", &GetPlayerById, py::arg("id"));

    // Events
    pyClass.def("emit", &Emit, py::arg("event_name"));

    // Player Data
    pyClass.def_property_readonly("name", &alt::IPlayer::GetName);
    pyClass.def_property_readonly("ip", &alt::IPlayer::GetIP);
    pyClass.def_property_readonly("connected", &alt::IPlayer::IsConnected);
    pyClass.def_property_readonly("ping", &alt::IPlayer::GetPing);
    pyClass.def_property_readonly("social_id", &alt::IPlayer::GetSocialID);
    pyClass.def_property_readonly("hwid_hash", &alt::IPlayer::GetHwidHash);
    pyClass.def_property_readonly("hwid_ex_hash", &alt::IPlayer::GetHwidExHash);
    pyClass.def_property_readonly("auth_token", &alt::IPlayer::GetAuthToken);
    pyClass.def("kick", &alt::IPlayer::Kick, py::arg("reason") = "Kicked");

    // Game Data
    pyClass.def_property_readonly("speed", &alt::IPlayer::GetMoveSpeed);
    pyClass.def_property_readonly("aim_pos", &GetAimPos);
    pyClass.def_property_readonly("head_rot", &GetHeadRot);
    pyClass.def_property_readonly("entity_aiming_at", &GetEntityAimingAt);
    pyClass.def_property_readonly("entity_aim_offset", &GetEntityAimOffset);
    pyClass.def_property("invincible", &alt::IPlayer::GetInvincible, &alt::IPlayer::SetInvincible);
    pyClass.def("play_ambient_speech", &alt::IPlayer::PlayAmbientSpeech, py::arg("speech_name"), py::arg("speech_param"), py::arg("speech_dict_hash"));


    // Weather & Time
    pyClass.def("set_date_time", &alt::IPlayer::SetDateTime, py::arg("day"), py::arg("month"), py::arg("year"), py::arg("hour"), py::arg("minute"), py::arg("second"));
    pyClass.def("set_weather", &alt::IPlayer::SetWeather);

    // Vehicles
    pyClass.def_property_readonly("in_vehicle", &alt::IPlayer::IsInVehicle);
    pyClass.def_property_readonly("vehicle", &alt::IPlayer::GetVehicle);
    pyClass.def_property_readonly("seat", &alt::IPlayer::GetSeat);
    pyClass.def("set_into_vehicle", &alt::IPlayer::SetIntoVehicle, py::arg("vehicle"), py::arg("seat"));

    // Health
    pyClass.def_property("health", &alt::IPlayer::GetHealth, &alt::IPlayer::SetHealth);
    pyClass.def_property("max_health", &alt::IPlayer::GetMaxHealth, &alt::IPlayer::SetMaxHealth);
    pyClass.def("clear_blood_damage", &alt::IPlayer::ClearBloodDamage);

    // Armour
    pyClass.def_property("armour", &alt::IPlayer::GetArmour, &alt::IPlayer::SetArmour);
    pyClass.def_property("max_armour", &alt::IPlayer::GetMaxArmour, &alt::IPlayer::SetMaxArmour);

    // Weapons
    pyClass.def_property("current_weapon", &alt::IPlayer::GetCurrentWeapon, &alt::IPlayer::SetCurrentWeapon);
    pyClass.def("give_weapon", &alt::IPlayer::GiveWeapon, py::arg("weapon_hash"), py::arg("ammo"), py::arg("equip_now"));
    pyClass.def("remove_weapon", &alt::IPlayer::RemoveWeapon, py::arg("weapon_hash"));
    pyClass.def("remove_all_weapons", &alt::IPlayer::RemoveAllWeapons);
    pyClass.def("set_weapon_tint_index", &alt::IPlayer::SetWeaponTintIndex, py::arg("weapon_hash"), py::arg("tint_index"));
    pyClass.def_property_readonly("current_weapon_tint_index", &GetCurrentWeaponTintIndex);
    pyClass.def_property_readonly("current_weapon_components", &GetCurrentWeaponComponents);
    pyClass.def("add_weapon_component", &alt::IPlayer::AddWeaponComponent, py::arg("weapon_hash"), py::arg("component"));
    pyClass.def("remove_weapon_component", &alt::IPlayer::RemoveWeaponComponent, py::arg("weapon_hash"), py::arg("component"));
    pyClass.def_property_readonly("weapons", &GetWeapons);

    // Current Status
    pyClass.def_property_readonly("dead", &alt::IPlayer::IsDead);
    pyClass.def_property_readonly("jumping", &alt::IPlayer::IsJumping);
    pyClass.def_property_readonly("in_ragdoll", &alt::IPlayer::IsInRagdoll);
    pyClass.def_property_readonly("aiming", &alt::IPlayer::IsAiming);
    pyClass.def_property_readonly("shooting", &alt::IPlayer::IsShooting);
    pyClass.def_property_readonly("reloading", &alt::IPlayer::IsReloading);
    pyClass.def_property_readonly("super_jump", &alt::IPlayer::IsSuperJumpEnabled);
    pyClass.def_property_readonly("crouching", &alt::IPlayer::IsCrouching);
    pyClass.def_property_readonly("stealthy", &alt::IPlayer::IsStealthy);
    pyClass.def_property_readonly("flashlight_active", &alt::IPlayer::IsFlashlightActive);

    // Face Features
    pyClass.def("set_head_overlay", &alt::IPlayer::SetHeadOverlay, py::arg("overlay_id"), py::arg("index"), py::arg("opacity"));
    pyClass.def("remove_head_overlay", &alt::IPlayer::RemoveHeadOverlay, py::arg("overlay_id"));
    pyClass.def("set_head_overlay_color", &alt::IPlayer::SetHeadOverlayColor, py::arg("overlay_id"), py::arg("color_type"), py::arg("color_index"), py::arg("second_color_index"));
    pyClass.def("get_head_overlay", &GetHeadOverlay, py::arg("overlay_id"));
    pyClass.def("set_face_feature", &alt::IPlayer::SetFaceFeature, py::arg("index"), py::arg("scale"));
    pyClass.def("get_face_feature_scale", &alt::IPlayer::GetFaceFeatureScale, py::arg("index"));
    pyClass.def("remove_face_feature", &alt::IPlayer::RemoveFaceFeature, py::arg("index"));
    pyClass.def("set_head_blend_palette_color", &alt::IPlayer::SetHeadBlendPaletteColor, py::arg("id"), py::arg("red"), py::arg("green"), py::arg("blue"));
    pyClass.def("get_head_blend_palette_color", &alt::IPlayer::GetHeadBlendPaletteColor, py::arg("id"));
    pyClass.def("set_head_blend_data", &alt::IPlayer::SetHeadBlendData, py::arg("shape_first_id"), py::arg("shape_second_id"), py::arg("shape_third_id"), py::arg("skin_first_id"), py::arg("skin_second_id"), py::arg("skin_third_id"), py::arg("shape_mix"), py::arg("skin_mix"), py::arg("third_mix"));
    pyClass.def_property_readonly("head_blend_data", &GetHeadBlendData);
	pyClass.def("get_eye_color", &alt::IPlayer::GetEyeColor);
	pyClass.def("set_eye_color", &alt::IPlayer::SetEyeColor, py::arg("eye_color"));
    pyClass.def_property("hair_color", &alt::IPlayer::GetHairColor, &alt::IPlayer::SetHairColor);
    pyClass.def_property("hair_highlight_color", &alt::IPlayer::GetHairHighlightColor, &alt::IPlayer::SetHairHighlightColor);

    // Clothing & Props
    pyClass.def("get_clothes", &GetClothes, py::arg("component"));
    pyClass.def("set_clothes", &alt::IPlayer::SetClothes, py::arg("component"), py::arg("drawable"), py::arg("texture"), py::arg("palette") = 0);
    pyClass.def("get_dlc_clothes", &GetDlcClothes, py::arg("component"));
    pyClass.def("set_dlc_clothes", &SetDlcClothes, py::arg("dlc"), py::arg("component"), py::arg("drawable"), py::arg("texture"), py::arg("palette") = 2);
    pyClass.def("get_prop", &GetProps, py::arg("component"));
    pyClass.def("set_prop", &alt::IPlayer::SetProps, py::arg("component"), py::arg("drawable"), py::arg("texture"));
    pyClass.def("get_dlc_prop", &GetDlcProp, py::arg("component"));
    pyClass.def("set_dlc_prop", &SetDlcProps, py::arg("dlc"), py::arg("component"), py::arg("drawable"), py::arg("texture"));
    pyClass.def("clear_prop", &alt::IPlayer::ClearProps);

    // Streaming Range
    pyClass.def("is_entity_in_streaming_range", py::overload_cast<alt::Ref<alt::IEntity>>(&alt::IPlayer::IsEntityInStreamingRange), py::arg("entity"));
    pyClass.def("is_entity_in_streaming_range", py::overload_cast<uint16_t>(&alt::IPlayer::IsEntityInStreamingRange), py::arg("id"));

    // Spawn
    pyClass.def("spawn", py::overload_cast<alt::IPlayer*, Vector3, uint32_t>(&Spawn), py::arg("pos"), py::arg("delay") = 0);
    pyClass.def("spawn", py::overload_cast<alt::IPlayer*, float, float, float, uint32_t>(&Spawn), py::arg("x"), py::arg("y"), py::arg("z"), py::arg("delay") = 0);
    pyClass.def("despawn", &alt::IPlayer::Despawn);

    // Local MetaData
    pyClass.def("get_local_meta", &GetLocalMeta, py::arg("key"));
    pyClass.def("has_local_meta", &alt::IPlayer::HasLocalMetaData, py::arg("key"));
    pyClass.def("set_local_meta", &SetLocalMeta, py::arg("key"), py::arg("value"));
    pyClass.def("delete_local_meta", &alt::IPlayer::DeleteLocalMetaData, py::arg("key"));
}

