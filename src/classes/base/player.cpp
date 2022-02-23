#include "player.h"

void Player::Spawn(float x, float y, float z, unsigned int delay)
{
	alt::Position altPos{x, y, z};
	player->Spawn(altPos, delay);
}

void Player::Spawn(Vector3 coords, unsigned int delay)
{
	player->Spawn(coords.toAltPos(), delay);
}

void Player::SetModel(const py::object& model)
{
	auto type = Utils::GetTypeOfObject(model);
	if (type == "str")
	{
		uint32_t modelHash = Core->Hash(py::str(model).cast<std::string>());
		player->SetModel(modelHash);
	}
	else if (type == "int" || type == "float")
	{
		player->SetModel(py::int_(model).cast<unsigned int>());
	}
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

void RegisterPlayerClass(const py::module_& m)
{
	auto pyClass = py::class_<Player, Entity>(m, "Player");

	// Static
	pyClass.def_property_readonly_static("all", &Player::GetAllPlayers);

	// Spawning
	pyClass.def("spawn", py::overload_cast<float, float, float, unsigned int>(&Player::Spawn));
	pyClass.def("spawn", py::overload_cast<Vector3, unsigned int>(&Player::Spawn));
	pyClass.def("despawn", &Player::Despawn);

	// Health
	pyClass.def_property("health", &Player::GetHealth, &Player::SetHealth);
	pyClass.def_property_readonly("dead", &Player::IsDead);
	pyClass.def_property("invincible", &Player::GetInvincible, &Player::SetInvincible);

	// Armour
	pyClass.def_property("armour", &Player::GetArmour, &Player::SetArmour);
	pyClass.def_property("maxArmour", &Player::GetMaxArmour, &Player::SetMaxArmour);

	// Speed
	pyClass.def_property_readonly("speed", &Player::GetMoveSpeed);

	// Model
	pyClass.def_property("model", &Player::GetModel, &Player::SetModel);
	pyClass.def("clearBloodDamage", &Player::ClearBloodDamage);

	// Rotation
	pyClass.def_property_readonly("headRot", &Player::GetHeadRotation);

	// Auth
	pyClass.def_property_readonly("hwidHash", &Player::GetHWIDHash);
	pyClass.def_property_readonly("hwidExHash", &Player::GetHWIDExHash);
	pyClass.def_property_readonly("socialId", &Player::GetSocialId);

	// Connection Info
	pyClass.def_property_readonly("connected", &Player::IsConnected);
	pyClass.def_property_readonly("ping", &Player::GetPing);
	pyClass.def("kick", &Player::Kick, py::arg("reason") = "Kicked");

	// Weapons
	pyClass.def_property("currentWeapon", &Player::GetCurrentWeapon, &Player::SetCurrentWeapon);
	pyClass.def_property_readonly("currentWeaponComponents", &Player::GetCurrentWeaponComponents);
	pyClass.def_property_readonly("currentWeaponTintIndex", &Player::GetCurrentWeaponTintIndex);
	pyClass.def("giveWeapon", py::overload_cast<uint32_t, int, bool>(&Player::GiveWeapon));
	pyClass.def("giveWeapon", py::overload_cast<const std::string&, int, bool>(&Player::GiveWeapon));

	pyClass.def("removeWeapon", py::overload_cast<uint32_t>(&Player::RemoveWeapon));
	pyClass.def("removeWeapon", py::overload_cast<const std::string&>(&Player::RemoveWeapon));

	pyClass.def("getWeaponTintIndex", py::overload_cast<uint32_t>(&Player::GetWeaponTintIndex));
	pyClass.def("getWeaponTintIndex", py::overload_cast<const std::string&>(&Player::GetWeaponTintIndex));

	pyClass.def("removeAllWeapons", &Player::RemoveAllWeapons);

	pyClass.def_property_readonly("flashlightActive", &Player::IsFlashlightActive);

	pyClass.def("hasWeaponComponent", py::overload_cast<uint32_t, uint32_t>(&Player::HasWeaponComponent));
	pyClass.def("hasWeaponComponent", py::overload_cast<const std::string&, uint32_t>(&Player::HasWeaponComponent));
	pyClass.def("hasWeaponComponent", py::overload_cast<uint32_t, const std::string&>(&Player::HasWeaponComponent));
	pyClass.def("hasWeaponComponent", py::overload_cast<const std::string&, const std::string&>(&Player::HasWeaponComponent));

	pyClass.def("addWeaponComponent", py::overload_cast<uint32_t, uint32_t>(&Player::AddWeaponComponent));
	pyClass.def("addWeaponComponent", py::overload_cast<const std::string&, uint32_t>(&Player::AddWeaponComponent));
	pyClass.def("addWeaponComponent", py::overload_cast<uint32_t, const std::string&>(&Player::AddWeaponComponent));
	pyClass.def("addWeaponComponent", py::overload_cast<const std::string&, const std::string&>(&Player::AddWeaponComponent));

	pyClass.def("removeWeaponComponent", py::overload_cast<uint32_t, uint32_t>(&Player::RemoveWeaponComponent));
	pyClass.def("removeWeaponComponent", py::overload_cast<const std::string&, uint32_t>(&Player::RemoveWeaponComponent));
	pyClass.def("removeWeaponComponent", py::overload_cast<uint32_t, const std::string&>(&Player::RemoveWeaponComponent));
	pyClass.def("removeWeaponComponent", py::overload_cast<const std::string&, const std::string&>(&Player::RemoveWeaponComponent));

	pyClass.def("setWeaponTintIndex", py::overload_cast<uint32_t, uint8_t>(&Player::SetWeaponTintIndex));
	pyClass.def("setWeaponTintIndex", py::overload_cast<const std::string&, uint8_t>(&Player::SetWeaponTintIndex));

	// Actions
	pyClass.def_property_readonly("jumping", &Player::IsJumping);
	pyClass.def_property_readonly("inRagdoll", &Player::IsInRagdoll);
	pyClass.def_property_readonly("aiming", &Player::IsAiming);
	pyClass.def_property_readonly("shooting", &Player::IsShooting);
	pyClass.def_property_readonly("reloading", &Player::IsReloading);

	// Aiming
	pyClass.def_property_readonly("entityAimingOffset", &Player::GetEntityAimingOffset);
	pyClass.def_property_readonly("entityAimingAt", &Player::GetEntityAimingAt);
	pyClass.def_property_readonly("aimPos", &Player::GetAimPos);

	// Time
	pyClass.def("setDateTime", &Player::SetDateTime);

	// Weather
	pyClass.def("setWeather", &Player::SetWeather);

	// Vehicle
	pyClass.def_property_readonly("vehicle", &Player::GetVehicle);
	pyClass.def_property_readonly("inVehicle", &Player::IsInVehicle);
	pyClass.def_property_readonly("seat", &Player::GetSeat);
	pyClass.def("setIntoVehicle", &Player::SetIntoVehicle);

	// Clothes
	pyClass.def("getClothes", &Player::GetClothes);
	pyClass.def("setClothes", &Player::SetClothes);

	pyClass.def("getDlcClothes", &Player::GetDlcClothes);
	pyClass.def("setDlcClothes", &Player::SetDlcClothes);

	// Props

	pyClass.def("getProps", &Player::GetProps);
	pyClass.def("setProps", &Player::SetProps);

	pyClass.def("getDlcProps", &Player::GetDlcProps);
	pyClass.def("setDlcProps", &Player::SetDlcProps);

	pyClass.def("clearProps", &Player::ClearProps);

	// Event
	//pyClass.def("emit", &Player::Emit);
}
