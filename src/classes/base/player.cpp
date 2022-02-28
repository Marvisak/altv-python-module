#include "classes/types/vector3.hpp"
#include "classes/classes.hpp"
#include "utils.hpp"

PYBIND11_DECLARE_HOLDER_TYPE(T, alt::Ref<T>, true)

namespace pybind11::detail {
    template <typename T>
    struct holder_helper<alt::Ref<T>> {
        static const T* get(const alt::Ref<T> &p) { return p.Get(); }
    };
}


py::list GetAllPlayers(const py::object& type) {
    return Utils::ArrayToPyList<alt::Ref<alt::IPlayer>>(alt::ICore::Instance().GetPlayers());
}

alt::IPlayer* GetById(uint16_t id) {
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
    _this->Spawn(pos.ToAltPos(), delay);
}

void SetModel(alt::IPlayer* _this, const std::string& model)
{
    uint32_t modelHash = alt::ICore::Instance().Hash(py::str(model).cast<std::string>());
    _this->SetModel(modelHash);
}

py::list GetCurrentWeaponComponents(alt::IPlayer* _this) {
    return Utils::ArrayToPyList<uint32_t>(_this->GetCurrentWeaponComponents());
}

py::list GetWeapons(alt::IPlayer* _this) {
    return Utils::ArrayToPyList<alt::Weapon>(_this->GetWeapons());
}

void SetDlcClothes(alt::IPlayer* _this, uint32_t dlc, uint8_t component, uint16_t drawable, uint8_t texture, uint8_t palette = 2) {
    if (drawable < 128) {
        _this->SetDlcClothes(component, drawable, texture, palette, dlc);
    } else {
        throw py::value_error("Drawable can't be higher than 127");
    }
}

void SetDlcProps(alt::IPlayer* _this, uint32_t dlc, uint8_t component, uint8_t drawable, uint8_t texture ) {
    _this->SetDlcProps(component, drawable, texture, dlc);
}

Vector3 GetAimPos(alt::IPlayer* _this) {
    return Vector3(_this->GetAimPos());
}

Vector3 GetHeadRot(alt::IPlayer* _this) {
    return Vector3(_this->GetHeadRotation());
}

py::object GetEntityAimingAt(alt::IPlayer* _this) {
    return Utils::GetBaseObject(_this->GetEntityAimingAt());
}


Vector3 GetEntityAimOffset(alt::IPlayer* _this) {
    return Vector3(_this->GetEntityAimOffset());
}

/*
void Player::Emit(const std::string& eventName, const py::args& args)
{
	if (std::find(Utils::EventTypes.begin(), Utils::EventTypes.end(), eventName) != Utils::EventTypes.end())
		return;
	alt::MValueArgs eventArgs;
	for (const py::handle& arg : *args)
	{
		eventArgs.Push(Utils::ValueToMValue(arg.cast<py::object>()));
	}
	Core->TriggerClientEvent(player, eventName, eventArgs);
}
*/

void RegisterPlayerClass(const py::module_& m) {
    auto pyClass = py::class_<alt::IPlayer, alt::IEntity, alt::Ref<alt::IPlayer>>(m, "Player", py::multiple_inheritance());

    // Static
    pyClass.def_property_readonly_static("all", &GetAllPlayers);
    pyClass.def_static("get_by_id", &GetById, py::arg("id"));

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
    pyClass.def("give_weapon", &alt::IPlayer::GiveWeapon, py::arg("weaponHash"), py::arg("ammo"), py::arg("equip_now"));
    pyClass.def("remove_weapon", &alt::IPlayer::RemoveWeapon, py::arg("weaponHash"));
    pyClass.def("remove_all_weapons", &alt::IPlayer::RemoveAllWeapons);
    pyClass.def("set_weapon_tint_index", &alt::IPlayer::SetWeaponTintIndex, py::arg("weaponHash"), py::arg("tint_index"));
    pyClass.def_property_readonly("current_weapon_tint_index", &alt::IPlayer::GetCurrentWeaponTintIndex);
    pyClass.def_property_readonly("current_weapon_components", &GetCurrentWeaponComponents);
    pyClass.def("add_weapon_component", &alt::IPlayer::AddWeaponComponent, py::arg("weaponHash"), py::arg("component"));
    pyClass.def("remove_weapon_component", &alt::IPlayer::RemoveWeaponComponent, py::arg("weaponHash"), py::arg("component"));
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
    pyClass.def("get_head_overlay", &alt::IPlayer::GetHeadOverlay, py::arg("overlay_id"));
    pyClass.def("set_face_feature", &alt::IPlayer::SetFaceFeature, py::arg("index"), py::arg("scale"));
    pyClass.def("get_face_feature_scale", &alt::IPlayer::GetFaceFeatureScale, py::arg("index"));
    pyClass.def("remove_face_feature", &alt::IPlayer::RemoveFaceFeature, py::arg("index"));
    pyClass.def("set_head_blend_palette_color", &alt::IPlayer::SetHeadBlendPaletteColor, py::arg("id"), py::arg("red"), py::arg("green"), py::arg("blue"));
    pyClass.def("get_head_blend_palette_color", &alt::IPlayer::GetHeadBlendPaletteColor, py::arg("id"));
    pyClass.def("set_head_blend_data", &alt::IPlayer::SetHeadBlendData, py::arg("shape_first_id"), py::arg("shape_second_id"), py::arg("shape_third_id"), py::arg("skin_first_id"), py::arg("skin_second_id"), py::arg("skin_third_id"), py::arg("shape_mix"), py::arg("skin_mix"), py::arg("third_mix"));
    pyClass.def_property_readonly("head_blend_data", &alt::IPlayer::GetHeadBlendData);
    pyClass.def_property("eye_color", &alt::IPlayer::GetEyeColor, &alt::IPlayer::SetEyeColor);
    pyClass.def_property("hair_color", &alt::IPlayer::GetHairColor, &alt::IPlayer::SetHairColor);
    pyClass.def_property("hair_highlight_color", &alt::IPlayer::GetHairHighlightColor, &alt::IPlayer::SetHairHighlightColor);

    // Clothing & Props
    pyClass.def("get_clothes", &alt::IPlayer::GetClothes, py::arg("component"));
    pyClass.def("set_clothes", &alt::IPlayer::SetClothes, py::arg("component"), py::arg("drawable"), py::arg("texture"), py::arg("palette") = 0);
    pyClass.def("get_dlc_clothes", &alt::IPlayer::GetDlcClothes, py::arg("component"));
    pyClass.def("set_dlc_clothes", &SetDlcClothes, py::arg("dlc"), py::arg("component"), py::arg("drawable"), py::arg("texture"), py::arg("palette") = 2);
    pyClass.def("get_prop", &alt::IPlayer::GetProps, py::arg("component"));
    pyClass.def("set_prop", &alt::IPlayer::SetProps, py::arg("component"), py::arg("drawable"), py::arg("texture"));
    pyClass.def("get_dlc_prop", &alt::IPlayer::GetDlcProps, py::arg("component"));
    pyClass.def("set_dlc_prop", &SetDlcProps, py::arg("dlc"), py::arg("component"), py::arg("drawable"), py::arg("texture"));
    pyClass.def("clear_props", &alt::IPlayer::ClearProps);

    // Streaming Range
    pyClass.def("is_entity_in_streaming_range", py::overload_cast<alt::Ref<alt::IEntity>>(&alt::IPlayer::IsEntityInStreamingRange), py::arg("entity"));
    pyClass.def("is_entity_in_streaming_range", py::overload_cast<uint16_t>(&alt::IPlayer::IsEntityInStreamingRange), py::arg("id"));

    // Model
    pyClass.def_property("model", &alt::IPlayer::GetModel, py::overload_cast<unsigned int>(&alt::IPlayer::SetModel));
    pyClass.def_property("model", &alt::IPlayer::GetModel, py::overload_cast<alt::IPlayer*, const std::string&>(&SetModel));

    // Spawn
    pyClass.def("spawn", py::overload_cast<alt::IPlayer*, Vector3, uint32_t>(&Spawn), py::arg("pos"), py::arg("delay") = 0);
    pyClass.def("spawn", py::overload_cast<alt::IPlayer*, float, float, float, uint32_t>(&Spawn), py::arg("x"), py::arg("y"), py::arg("z"), py::arg("delay") = 0);
    pyClass.def("despawn", &alt::IPlayer::Despawn);
}

