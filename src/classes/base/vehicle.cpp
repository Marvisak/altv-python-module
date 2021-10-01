#include "vehicle.h"
#include "player.h"

Player Vehicle::GetDriver()
{
	return vehicle->GetDriver();
}

void RegisterVehicleClass(const py::module_& m)
{
	auto pyClass = py::class_<Vehicle, Entity>(m, "Vehicle");

	// constructors
	pyClass.def(py::init(
		[](const std::string& model, double x, double y, double z, double rx, double ry, double rz) { return Vehicle(Vehicle::SpawnVehicle(Core->Hash(model), x, y, z, rx, ry, rz)); }));
	pyClass.def(
		py::init([](const std::string& model, Vector3 pos, double rx, double ry, double rz) { return Vehicle(Vehicle::SpawnVehicle(Core->Hash(model), pos.x, pos.y, pos.z, rx, ry, rz)); }));
	pyClass.def(
		py::init([](const std::string& model, double x, double y, double z, Vector3 rot) { return Vehicle(Vehicle::SpawnVehicle(Core->Hash(model), x, y, z, rot.x, rot.y, rot.z)); }));
	pyClass.def(py::init([](const std::string& model, Vector3 pos, Vector3 rot) { return Vehicle(Vehicle::SpawnVehicle(Core->Hash(model), pos.x, pos.y, pos.z, rot.x, rot.y, rot.z)); }));
	pyClass.def(py::init([](uint32_t modelHash, double x, double y, double z, double rx, double ry, double rz) { return Vehicle(Vehicle::SpawnVehicle(modelHash, x, y, z, rx, ry, rz)); }));
	pyClass.def(py::init([](uint32_t modelHash, Vector3 pos, double rx, double ry, double rz) { return Vehicle(Vehicle::SpawnVehicle(modelHash, pos.x, pos.y, pos.z, rx, ry, rz)); }));
	pyClass.def(py::init([](uint32_t modelHash, double x, double y, double z, Vector3 rot) { return Vehicle(Vehicle::SpawnVehicle(modelHash, x, y, z, rot.x, rot.y, rot.z)); }));
	pyClass.def(py::init([](uint32_t modelHash, Vector3 pos, Vector3 rot) { return Vehicle(Vehicle::SpawnVehicle(modelHash, pos.x, pos.y, pos.z, rot.x, rot.y, rot.z)); }));

	// static
	pyClass.def_static("getByID", &Vehicle::GetById, py::arg("id"));
	pyClass.def_property_readonly_static("all", &Vehicle::GetAllVehicles);

	// properties
	pyClass.def_property("activeRadioStation", &Vehicle::GetRadioStationIndex, &Vehicle::SetRadioStationIndex);
	pyClass.def_property("bodyAdditionalHealth", &Vehicle::GetBodyAdditionalHealth, &Vehicle::SetBodyAdditionalHealth);
	pyClass.def_property("bodyHealth", &Vehicle::GetBodyHealth, &Vehicle::SetBodyHealth);
	pyClass.def_property("customPrimaryColor", &Vehicle::GetPrimaryColorRGB, &Vehicle::SetPrimaryColorRGB);
	pyClass.def_property("customSecondaryColor", &Vehicle::GetSecondaryColorRGB, &Vehicle::SetSecondaryColorRGB);
	pyClass.def_property_readonly("isPrimaryColorCustom", &Vehicle::IsPrimaryColorRGB);
	pyClass.def_property_readonly("isSecondaryColorCustom", &Vehicle::IsSecondaryColorRGB);
	pyClass.def_property("customTires", &Vehicle::GetCustomTires, &Vehicle::SetCustomTires);
	pyClass.def_property("darkness", &Vehicle::GetSpecialDarkness, &Vehicle::SetSpecialDarkness);
	pyClass.def_property("dashboardColor", &Vehicle::GetDashboardColor, &Vehicle::SetDashboardColor);
	pyClass.def_property_readonly("daylightOn", &Vehicle::IsDaylightOn);
	pyClass.def_property_readonly("destroyed", &Vehicle::IsDestroyed);
	pyClass.def_property("dirtLevel", &Vehicle::GetDirtLevel, &Vehicle::SetDirtLevel);
	pyClass.def_property_readonly("driver", &Vehicle::GetDriver);
	pyClass.def_property("engineHealth", &Vehicle::GetEngineHealth, &Vehicle::SetEngineHealth);
	pyClass.def_property("engineOn", &Vehicle::IsEngineOn, &Vehicle::SetEngineOn);
	pyClass.def_property_readonly("flamethrowerActive", &Vehicle::IsFlamethrowerActive);
	pyClass.def_property_readonly("frontWheels", &Vehicle::GetWheelVariation);
	pyClass.def_property_readonly("handbrakeActive", &Vehicle::IsHandbrakeActive);
	pyClass.def_property_readonly("hasArmoredWindows", &Vehicle::HasArmoredWindows);
	pyClass.def_property("headlightColor", &Vehicle::GetHeadlightColor, &Vehicle::SetHeadlightColor);
	pyClass.def_property("interiorColor", &Vehicle::GetInteriorColor, &Vehicle::SetInteriorColor);
	pyClass.def_property("lightsMultiplier", &Vehicle::GetLightsMultiplier, &Vehicle::SetLightsMultiplier);
	pyClass.def_property("livery", &Vehicle::GetLivery, &Vehicle::SetLivery);
	pyClass.def_property("lockState", &Vehicle::GetLockState, &Vehicle::SetLockState);
	pyClass.def_property("manualEngineControl", &Vehicle::IsManualEngineControl, &Vehicle::SetManualEngineControl);
	pyClass.def_property("modKit", &Vehicle::GetModKit, &Vehicle::SetModKit);
	pyClass.def_property_readonly("modKitsCount", &Vehicle::GetModKitsCount);
	pyClass.def_property_readonly("model", &Vehicle::GetModel);
	pyClass.def_property("neon", &Vehicle::GetNeonActive, &Vehicle::SetNeonActive);
	pyClass.def_property_readonly("neonActive", &Vehicle::IsNeonActive);
	pyClass.def_property("neonColor", &Vehicle::GetNeonColor, &Vehicle::SetNeonColor);
	pyClass.def_property_readonly("nightlightOn", &Vehicle::IsNightlightOn);
	pyClass.def_property("numberPlateIndex", &Vehicle::GetNumberplateIndex, &Vehicle::SetNumberplateIndex);
	pyClass.def_property("numberPlateText", &Vehicle::GetNumberplateText, &Vehicle::SetNumberplateText);
	pyClass.def_property("pearlColor", &Vehicle::GetPearlColor, &Vehicle::SetPearlColor);
	pyClass.def_property("petrolTankHealth", &Vehicle::GetPetrolTankHealth, &Vehicle::SetPetrolTankHealth);
	pyClass.def_property("primaryColor", &Vehicle::GetPrimaryColor, &Vehicle::SetPrimaryColor);
	pyClass.def_property_readonly("rearWheels", &Vehicle::GetRearWheelVariation);
	pyClass.def_property_readonly("repairsCount", &Vehicle::GetRepairsCount);
	pyClass.def_property("roofLivery", &Vehicle::GetRoofLivery, &Vehicle::SetRoofLivery);
	pyClass.def_property("roofState", &Vehicle::GetRoofState, &Vehicle::SetRoofState);
	pyClass.def_property("secondaryColor", &Vehicle::GetSecondaryColor, &Vehicle::SetSecondaryColor);
	pyClass.def_property("sirenActive", &Vehicle::IsSirenActive, &Vehicle::SetSirenActive);
	pyClass.def_property("tireSmokeColor", &Vehicle::GetTireSmokeColor, &Vehicle::SetTireSmokeColor);
	pyClass.def_property_readonly("tireSmokeColorCustom", &Vehicle::IsTireSmokeColorCustom);
	pyClass.def_property("wheelColor", &Vehicle::GetWheelColor, &Vehicle::SetWheelColor);
	pyClass.def_property_readonly("wheelType", &Vehicle::GetWheelType);
	pyClass.def_property_readonly("wheelsCount", &Vehicle::GetWheelsCount);
	pyClass.def_property("windowTint", &Vehicle::GetWindowTint, &Vehicle::SetWindowTint);

	// Methods
	pyClass.def("doesWheelHasTire", &Vehicle::DoesWheelHasTire, py::arg("wheelId"));
	pyClass.def("getAppearanceDataBase64", &Vehicle::GetAppearanceDataBase64);
	pyClass.def("getArmoredWindowHealth", &Vehicle::GetArmoredWindowHealth, py::arg("windowId"));
	pyClass.def("getArmoredWindowShootCount", &Vehicle::GetArmoredWindowShootCount, py::arg("windowId"));
	pyClass.def("getAttached", &Vehicle::GetAttached);
	pyClass.def("getAttachedTo", &Vehicle::GetAttachedTo);
	pyClass.def("getBumperDamageLevel", &Vehicle::GetBumperDamageLevel, py::arg("bumperId"));
	pyClass.def("getDamageStatusBase64", &Vehicle::GetDamageDataBase64);
	pyClass.def("getDoorState", &Vehicle::GetDoorState, py::arg("doorId"));
	pyClass.def("getExtra", &Vehicle::IsExtraOn, py::arg("extraId"));
	pyClass.def("getGamestateDataBase64", &Vehicle::GetGameStateBase64);
	pyClass.def("getHealthDataBase64", &Vehicle::GetHealthDataBase64);
	pyClass.def("getMod", &Vehicle::GetMod, py::arg("modType"));
	pyClass.def("getModsCount", &Vehicle::GetModsCount, py::arg("modType"));
	pyClass.def("getPartBulletHoles", &Vehicle::GetPartBulletHoles, py::arg("partId"));
	pyClass.def("getPartDamageLevel", &Vehicle::GetPartDamageLevel, py::arg("partId"));
	pyClass.def("getScriptDataBase64", &Vehicle::GetScriptDataBase64);
	pyClass.def("getWheelHealth", &Vehicle::GetWheelHealth, py::arg("wheelId"));
	pyClass.def("isLightDamaged", &Vehicle::IsLightDamaged, py::arg("lightId"));
	pyClass.def("isSpecialLightDamaged", &Vehicle::IsSpecialLightDamaged, py::arg("specialLightId"));
	pyClass.def("isWheelBurst", &Vehicle::IsWheelBurst, py::arg("wheelId"));
	pyClass.def("isWheelDetached", &Vehicle::IsWheelDetached, py::arg("wheelId"));
	pyClass.def("isWheelOnFire", &Vehicle::IsWheelOnFire, py::arg("wheelId"));
	pyClass.def("isWindowDamaged", &Vehicle::IsWindowDamaged, py::arg("windowId"));
	pyClass.def("isWindowOpened", &Vehicle::IsWindowOpened, py::arg("windowId"));
	pyClass.def("repair", &Vehicle::SetFixed);
	pyClass.def("setAppearanceDataBase64", &Vehicle::LoadAppearanceDataFromBase64, py::arg("base64"));
	pyClass.def("setArmoredWindowHealth", &Vehicle::SetArmoredWindowHealth, py::arg("windowId"), py::arg("health"));
	pyClass.def("setArmoredWindowShootCount", &Vehicle::SetArmoredWindowShootCount, py::arg("windowId"), py::arg("shootCount"));
	pyClass.def("setBumperDamageLevel", &Vehicle::SetBumperDamageLevel, py::arg("bumperId"), py::arg("damageLevel"));
	pyClass.def("setDamageStatusBase64", &Vehicle::LoadDamageDataFromBase64, py::arg("base64"));
	pyClass.def("setDoorState", &Vehicle::SetDoorState, py::arg("doorId"), py::arg("doorState"));
	pyClass.def("setExtra", &Vehicle::ToggleExtra, py::arg("extraId"), py::arg("state"));
	pyClass.def("setGamestateDataBase64", &Vehicle::LoadGameStateFromBase64, py::arg("base64"));
	pyClass.def("setHealthDataBase64", &Vehicle::LoadHealthDataFromBase64, py::arg("base64"));
	pyClass.def("setLightDamaged", &Vehicle::SetLightDamaged, py::arg("lightId"), py::arg("isDamaged"));
	pyClass.def("setMod", &Vehicle::SetMod, py::arg("modType"), py::arg("modId"));
	pyClass.def("setPartBulletHoles", &Vehicle::SetPartBulletHoles, py::arg("partId"), py::arg("count"));
	pyClass.def("setPartDamageLevel", &Vehicle::SetPartDamageLevel, py::arg("partId"), py::arg("level"));
	pyClass.def("setRearWheels", &Vehicle::SetRearWheels, py::arg("wheelId"));
	pyClass.def("setScriptDataBase64", &Vehicle::LoadScriptDataFromBase64, py::arg("base64"));
	pyClass.def("setSpecialLightDamaged", &Vehicle::SetSpecialLightDamaged, py::arg("specialLightId"), py::arg("isDamaged"));
	pyClass.def("setWheelBurst", &Vehicle::SetWheelBurst, py::arg("wheelId"), py::arg("state"));
	pyClass.def("setWheelDetached", &Vehicle::SetWheelDetached, py::arg("wheelId"), py::arg("state"));
	pyClass.def("setWheelFixed", &Vehicle::SetWheelFixed, py::arg("wheelId"));
	pyClass.def("setWheelHasTire", &Vehicle::SetWheelHasTire, py::arg("wheelId"), py::arg("state"));
	pyClass.def("setWheelHealth", &Vehicle::SetWheelHealth, py::arg("wheelId"), py::arg("health"));
	pyClass.def("setWheelOnFire", &Vehicle::SetWheelOnFire, py::arg("wheelId"), py::arg("state"));
	pyClass.def("setWheels", &Vehicle::SetWheels, py::arg("wheelType"), py::arg("wheelId"));
	pyClass.def("setWindowDamaged", &Vehicle::SetWindowDamaged, py::arg("windowId"), py::arg("isDamaged"));
	pyClass.def("setWindowOpened", &Vehicle::SetWindowOpened, py::arg("windowId"), py::arg("state"));
}
