#include "classes/types/vector3.hpp"
#include "classes/types/enums.hpp"
#include "classes/classes.hpp"
#include "utils.hpp"


py::list GetAllVehicles(const py::object& type) {
    return Utils::ArrayToPyList<alt::Ref<alt::IVehicle>>(alt::ICore::Instance().GetVehicles());
}

alt::IVehicle* GetVehicleById(uint16_t id) {
    auto entity = alt::ICore::Instance().GetEntityByID(id);
    if (entity && entity->GetType() == alt::IBaseObject::Type::VEHICLE)
        return dynamic_cast<alt::IVehicle*>(entity.Get());
    return nullptr;
}

alt::IVehicle* CreateVehicle(uint32_t hash, alt::Position pos, alt::Rotation rot) {
    auto vehicle = alt::ICore::Instance().CreateVehicle(hash, pos, rot);
    if (vehicle)
        return vehicle.Get();
    throw std::runtime_error("Failed to create vehicle");
}

WindowTint GetWindowTint(alt::IVehicle* _this) {
    return (WindowTint)(_this->GetWindowTint());
}

py::dict GetNeonActive(alt::IVehicle* _this) {
	py::dict dict;
    bool left, right, front, back;
    _this->GetNeonActive(&left, &right, &front, &back);
	dict["left"] = left;
	dict["right"] = right;
	dict["front"] = front;
	dict["back"] = back;
    return dict;
}

void SetNeonActive(alt::IVehicle* _this, const py::dict& neon) {
    _this->SetNeonActive(neon["left"].cast<bool>(), neon["right"].cast<bool>(), neon["front"].cast<bool>(), neon["back"].cast<bool>());
}

RadioStation GetRadioStationIndex(alt::IVehicle* _this) {
    return (RadioStation)(_this->GetRadioStationIndex());
}

VehicleLockState GetLockState(alt::IVehicle* _this) {
    return (VehicleLockState)(_this->GetLockState());
}

VehicleDoorState GetDoorState(alt::IVehicle* _this, uint8_t doorId) {
    return (VehicleDoorState)(_this->GetDoorState(doorId));
}

VehiclePartDamage GetPartDamageLevel(alt::IVehicle* _this, uint8_t partId) {
    return (VehiclePartDamage)(_this->GetPartDamageLevel(partId));
}

VehicleBumper GetBumperDamageLevel(alt::IVehicle* _this, uint8_t bumperId) {
    return (VehicleBumper)(_this->GetBumperDamageLevel(bumperId));
}

void SetSearchLightTo(alt::IVehicle* _this, alt::IEntity* entity, bool state) {
    _this->SetSearchLight(state, entity);
}

NumberPlateStyle GetNumberplateIndex(alt::IVehicle* _this) {
    return (NumberPlateStyle)(_this->GetNumberplateIndex());
}

Vector3 GetVelocity(alt::IVehicle* _this) {
    return (Vector3)(_this->GetVelocity());
}

void RegisterVehicleClass(const py::module_& m) {
    auto pyClass = py::class_<alt::IVehicle, alt::IEntity, alt::Ref<alt::IVehicle>>(m, "Vehicle");
    pyClass.def(py::init<>([](const std::string& model, float x, float y, float z, float rx, float ry, float rz) {
        auto hash = alt::ICore::Instance().Hash(model);
        return CreateVehicle(hash, alt::Position(x, y, z), alt::Rotation(rx, ry, rz));
    }), py::arg("model"), py::arg("x"), py::arg("y"), py::arg("z"), py::arg("rx"), py::arg("ry"), py::arg("rz"));
    pyClass.def(py::init<>([](uint32_t hash, float x, float y, float z, float rx, float ry, float rz) {
        return CreateVehicle(hash, alt::Position(x, y, z), alt::Rotation(rx, ry, rz));
    }), py::arg("hash"), py::arg("x"), py::arg("y"), py::arg("z"), py::arg("rx"), py::arg("ry"), py::arg("rz"));
    pyClass.def(py::init<>([](const std::string& model, Vector3 pos, Vector3 rot) {
        auto hash = alt::ICore::Instance().Hash(model);
        return CreateVehicle(hash, pos.ToAltPos(), rot.ToAltRot());
    }), py::arg("model"), py::arg("pos"), py::arg("rot"));
    pyClass.def(py::init<>([](uint32_t hash, Vector3 pos, Vector3 rot) {
        return CreateVehicle(hash, pos.ToAltPos(), rot.ToAltRot());
    }), py::arg("hash"), py::arg("pos"), py::arg("rot"));

    pyClass.def_property_readonly_static("all", &GetAllVehicles);
    pyClass.def_static("get_by_id", &GetVehicleById, py::arg("id"));

    pyClass.def("get_mod", &alt::IVehicle::GetMod, py::arg("mod_type"));
    pyClass.def("set_mod", &alt::IVehicle::SetMod, py::arg("mod_type"), py::arg("mod_id"));
    pyClass.def("get_mods_count", &alt::IVehicle::GetModsCount, py::arg("mod_type"));
    pyClass.def("get_extra", &alt::IVehicle::IsExtraOn, py::arg("extra_id"));
    pyClass.def("set_extra", &alt::IVehicle::ToggleExtra, py::arg("extra_id"), py::arg("state"));
    pyClass.def("get_door_state", &GetDoorState, py::arg("door_id"));
    pyClass.def("set_door_state", &alt::IVehicle::SetDoorState, py::arg("door_id"), py::arg("state"));
    pyClass.def("is_window_opened", &alt::IVehicle::IsWindowOpened, py::arg("window_id"));
    pyClass.def("set_window_opened", &alt::IVehicle::SetWindowOpened, py::arg("window_id"), py::arg("state"));
    pyClass.def("is_wheel_burst", &alt::IVehicle::IsWheelBurst, py::arg("wheel_id"));
    pyClass.def("does_wheel_has_tire", &alt::IVehicle::DoesWheelHasTire, py::arg("wheel_id"));
    pyClass.def("is_wheel_detached", &alt::IVehicle::IsWheelDetached, py::arg("wheel_id"));
    pyClass.def("is_wheel_on_fire", &alt::IVehicle::IsWheelOnFire, py::arg("wheel_id"));
    pyClass.def("get_wheel_health", &alt::IVehicle::GetWheelHealth, py::arg("wheel_id"));
    pyClass.def("set_wheel_health", &alt::IVehicle::SetWheelHealth, py::arg("wheel_id"), py::arg("health"));
    pyClass.def("get_part_damage_level", &GetPartDamageLevel);
    pyClass.def("get_part_bullet_holes", &alt::IVehicle::GetPartBulletHoles, py::arg("part_id"));
    pyClass.def("is_light_damaged", &alt::IVehicle::IsLightDamaged, py::arg("light_id"));
    pyClass.def("is_window_damaged", &alt::IVehicle::IsWindowDamaged, py::arg("window_id"));
    pyClass.def("is_special_light_damaged", &alt::IVehicle::IsSpecialLightDamaged, py::arg("special_light_id"));
    pyClass.def("get_armored_window_health", &alt::IVehicle::GetArmoredWindowHealth, py::arg("window_id"));
    pyClass.def("get_armored_window_shoot_count", &alt::IVehicle::GetArmoredWindowShootCount, py::arg("window_id"));
    pyClass.def("get_bumper_damage_level", &GetBumperDamageLevel, py::arg("bumper_id"));
    pyClass.def("repair", &alt::IVehicle::SetFixed);
    pyClass.def("set_wheels", &alt::IVehicle::SetWheels);
    pyClass.def("set_rear_wheels", &alt::IVehicle::SetRearWheels);
    pyClass.def("set_wheel_burst", &alt::IVehicle::SetWheelBurst, py::arg("wheel_id"), py::arg("state"));
    pyClass.def("set_wheel_has_tire", &alt::IVehicle::SetWheelHasTire, py::arg("wheel_id"), py::arg("state"));
    pyClass.def("set_wheel_detached", &alt::IVehicle::SetWheelDetached, py::arg("wheel_id"), py::arg("state"));
    pyClass.def("set_wheel_on_fire", &alt::IVehicle::SetWheelOnFire, py::arg("wheel_id"), py::arg("state"));
    pyClass.def("set_wheel_fixed", &alt::IVehicle::SetWheelFixed, py::arg("wheel_id"));
    pyClass.def("set_part_damage_level", &alt::IVehicle::SetPartDamageLevel, py::arg("part_id"), py::arg("level"));
    pyClass.def("set_part_bullet_holes", &alt::IVehicle::SetPartBulletHoles, py::arg("part_id"), py::arg("count"));
    pyClass.def("set_light_damaged", &alt::IVehicle::SetLightDamaged, py::arg("light_id"), py::arg("is_damaged"));
    pyClass.def("set_window_damaged", &alt::IVehicle::SetWindowDamaged, py::arg("window_id"), py::arg("is_damaged"));
    pyClass.def("set_special_light_damaged", &alt::IVehicle::SetSpecialLightDamaged, py::arg("special_light_id"), py::arg("is_damaged"));
    pyClass.def("set_armored_window_health", &alt::IVehicle::SetArmoredWindowHealth, py::arg("window_id"), py::arg("health"));
    pyClass.def("set_armored_window_shoot_count", &alt::IVehicle::SetArmoredWindowShootCount, py::arg("window_id"), py::arg("count"));
    pyClass.def("set_bumper_damage_level", &alt::IVehicle::SetBumperDamageLevel, py::arg("bumper_id"), py::arg("level"));
    pyClass.def("set_search_light_to", &SetSearchLightTo);

    pyClass.def_property("modkit", &alt::IVehicle::GetModKit, &alt::IVehicle::SetModKit);
    pyClass.def_property("primary_color", &alt::IVehicle::GetPrimaryColor, &alt::IVehicle::SetPrimaryColor);
    pyClass.def_property("primary_color_rgb", &alt::IVehicle::GetPrimaryColorRGB, &alt::IVehicle::SetPrimaryColorRGB);
    pyClass.def_property("secondary_color", &alt::IVehicle::GetSecondaryColor, &alt::IVehicle::SetSecondaryColor);
    pyClass.def_property("secondary_color_rgb", &alt::IVehicle::GetSecondaryColorRGB, &alt::IVehicle::SetSecondaryColorRGB);
    pyClass.def_property("pearl_color", &alt::IVehicle::GetPearlColor, &alt::IVehicle::SetPearlColor);
    pyClass.def_property("wheel_color", &alt::IVehicle::GetWheelColor, &alt::IVehicle::SetWheelColor);
    pyClass.def_property("interior_color", &alt::IVehicle::GetInteriorColor, &alt::IVehicle::SetInteriorColor);
    pyClass.def_property("dashboard_color", &alt::IVehicle::GetDashboardColor, &alt::IVehicle::SetDashboardColor);
    pyClass.def_property("tire_smoke_color", &alt::IVehicle::GetTireSmokeColor, &alt::IVehicle::SetTireSmokeColor);
    pyClass.def_property("custom_tires", &alt::IVehicle::GetCustomTires, &alt::IVehicle::SetCustomTires);
    pyClass.def_property("darkness", &alt::IVehicle::GetSpecialDarkness, &alt::IVehicle::SetSpecialDarkness);
    pyClass.def_property("number_plate_index", &GetNumberplateIndex, &alt::IVehicle::SetNumberplateIndex);
    pyClass.def_property("number_plate_text", &alt::IVehicle::GetNumberplateText, &alt::IVehicle::SetNumberplateText);
    pyClass.def_property("window_tint", &GetWindowTint, &alt::IVehicle::SetWindowTint);
    pyClass.def_property("dirt_level", &alt::IVehicle::GetDirtLevel, &alt::IVehicle::SetDirtLevel);
    pyClass.def_property("neon", &GetNeonActive, &SetNeonActive);
    pyClass.def_property("neon_color", &alt::IVehicle::GetNeonColor, &alt::IVehicle::SetNeonColor);
    pyClass.def_property("livery", &alt::IVehicle::GetLivery, &alt::IVehicle::SetLivery);
    pyClass.def_property("roof_livery", &alt::IVehicle::GetRoofLivery, &alt::IVehicle::SetRoofLivery);
    pyClass.def_property("game_state_base64", &alt::IVehicle::GetGameStateBase64, &alt::IVehicle::LoadGameStateFromBase64);
    pyClass.def_property("appearance_data_base64", &alt::IVehicle::GetAppearanceDataBase64, &alt::IVehicle::LoadAppearanceDataFromBase64);
    pyClass.def_property("health_data_base64", &alt::IVehicle::GetHealthDataBase64, &alt::IVehicle::LoadHealthDataFromBase64);
    pyClass.def_property("damage_data_base64", &alt::IVehicle::GetDamageDataBase64, &alt::IVehicle::LoadDamageDataFromBase64);
    pyClass.def_property("script_data_base64", &alt::IVehicle::GetScriptDataBase64, &alt::IVehicle::LoadScriptDataFromBase64);
    pyClass.def_property("engine_on", &alt::IVehicle::IsEngineOn, &alt::IVehicle::SetEngineOn);
    pyClass.def_property("headlight_color", &alt::IVehicle::GetHeadlightColor, &alt::IVehicle::SetHeadlightColor);
    pyClass.def_property("active_radio_station", &GetRadioStationIndex, &alt::IVehicle::SetRadioStationIndex);
    pyClass.def_property("siren_active", &alt::IVehicle::IsSirenActive, &alt::IVehicle::SetSirenActive);
    pyClass.def_property("lock_state", &GetLockState, &alt::IVehicle::SetLockState);
    pyClass.def_property("roof_state", &alt::IVehicle::GetRoofState, &alt::IVehicle::SetRoofState);
    pyClass.def_property("lights_multiplayer", &alt::IVehicle::GetLightsMultiplier, &alt::IVehicle::SetLightsMultiplier);
    pyClass.def_property("engine_health", &alt::IVehicle::GetEngineHealth, &alt::IVehicle::SetEngineHealth);
    pyClass.def_property("petrol_tank_health", &alt::IVehicle::GetPetrolTankHealth, &alt::IVehicle::SetPetrolTankHealth);
    pyClass.def_property("body_health", &alt::IVehicle::GetBodyHealth, &alt::IVehicle::SetBodyHealth);
    pyClass.def_property("body_additional_health", &alt::IVehicle::GetBodyAdditionalHealth, &alt::IVehicle::SetBodyAdditionalHealth);
    pyClass.def_property("manual_engine_control", &alt::IVehicle::IsManualEngineControl, &alt::IVehicle::SetManualEngineControl);
    pyClass.def_property("drift_mode_enabled", &alt::IVehicle::IsDriftMode, &alt::IVehicle::SetDriftMode);
    pyClass.def_property("is_mission_train", &alt::IVehicle::IsTrainMissionTrain, &alt::IVehicle::SetTrainMissionTrain);
    pyClass.def_property("is_train_engine", &alt::IVehicle::IsTrainEngine, &alt::IVehicle::SetTrainIsEngine);
    pyClass.def_property("train_track_id", &alt::IVehicle::GetTrainTrackId, &alt::IVehicle::SetTrainTrackId);
    pyClass.def_property("train_engine_id", &alt::IVehicle::GetTrainEngineId, &alt::IVehicle::SetTrainEngineId);
    pyClass.def_property("train_config_index", &alt::IVehicle::GetTrainConfigIndex, &alt::IVehicle::SetTrainConfigIndex);
    pyClass.def_property("train_distance_from_engine", &alt::IVehicle::GetTrainDistanceFromEngine, &alt::IVehicle::SetTrainDistanceFromEngine);
    pyClass.def_property("is_train_caboose", &alt::IVehicle::IsTrainCaboose, &alt::IVehicle::SetTrainIsCaboose);
    pyClass.def_property("train_direction", &alt::IVehicle::GetTrainDirection, &alt::IVehicle::SetTrainDirection);
    pyClass.def_property("train_passenger_carriages", &alt::IVehicle::HasTrainPassengerCarriages, &alt::IVehicle::SetTrainHasPassengerCarriages);
    pyClass.def_property("train_render_derailed", &alt::IVehicle::GetTrainRenderDerailed, &alt::IVehicle::SetTrainRenderDerailed);
    pyClass.def_property("train_force_doors_open", &alt::IVehicle::GetTrainForceDoorsOpen, &alt::IVehicle::SetTrainForceDoorsOpen);
    pyClass.def_property("train_cruise_speed", &alt::IVehicle::GetTrainCruiseSpeed, &alt::IVehicle::SetTrainCruiseSpeed);
    pyClass.def_property("train_carriage_config_index", &alt::IVehicle::GetTrainCarriageConfigIndex, &alt::IVehicle::SetTrainCarriageConfigIndex);
    pyClass.def_property("train_linked_to_backward_id", &alt::IVehicle::GetTrainLinkedToBackwardId, &alt::IVehicle::SetTrainLinkedToBackwardId);
    pyClass.def_property("train_linked_to_forward_id", &alt::IVehicle::GetTrainLinkedToForwardId, &alt::IVehicle::SetTrainLinkedToForwardId);
    pyClass.def_property("train_unk1", &alt::IVehicle::GetTrainUnk1, &alt::IVehicle::SetTrainUnk1);
    pyClass.def_property("train_unk2", &alt::IVehicle::GetTrainUnk2, &alt::IVehicle::SetTrainUnk2);
    pyClass.def_property("train_unk3", &alt::IVehicle::GetTrainUnk3, &alt::IVehicle::SetTrainUnk3);
    pyClass.def_property("boat_anchor_active", &alt::IVehicle::IsBoatAnchorActive, &alt::IVehicle::SetBoatAnchorActive);

    pyClass.def_property_readonly("driver", &alt::IVehicle::GetDriver);
    pyClass.def_property_readonly("destroyed", &alt::IVehicle::IsDestroyed);
    pyClass.def_property_readonly("modkits_count", &alt::IVehicle::GetModKitsCount);
    pyClass.def_property_readonly("is_primary_color_rgb", &alt::IVehicle::IsPrimaryColorRGB);
    pyClass.def_property_readonly("is_secondary_color_rgb", &alt::IVehicle::IsSecondaryColorRGB);
    pyClass.def_property_readonly("is_tire_smoke_color_custom", &alt::IVehicle::IsTireSmokeColorCustom);
    pyClass.def_property_readonly("wheel_type", &alt::IVehicle::GetWheelType);
    pyClass.def_property_readonly("front_wheel", &alt::IVehicle::GetWheelVariation);
    pyClass.def_property_readonly("rear_wheel", &alt::IVehicle::GetRearWheelVariation);
    pyClass.def_property_readonly("neon_active", &alt::IVehicle::IsNeonActive);
    pyClass.def_property_readonly("handbrake_active", &alt::IVehicle::IsHandbrakeActive);
    pyClass.def_property_readonly("daylight_on", &alt::IVehicle::IsDaylightOn);
    pyClass.def_property_readonly("nightlight_on", &alt::IVehicle::IsNightlightOn);
    pyClass.def_property_readonly("flamethrower_active", &alt::IVehicle::IsFlamethrowerActive);
    pyClass.def_property_readonly("wheels_count", &alt::IVehicle::GetWheelsCount);
    pyClass.def_property_readonly("repairs_count", &alt::IVehicle::GetRepairsCount);
    pyClass.def_property_readonly("has_armored_windows", &alt::IVehicle::HasArmoredWindows);
    pyClass.def_property_readonly("velocity", &GetVelocity);
    pyClass.def_property_readonly("attached", &alt::IVehicle::GetAttached);
    pyClass.def_property_readonly("attachedTo", &alt::IVehicle::GetAttachedTo);
}
