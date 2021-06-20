#pragma once
#include <main.h>
#include <utils.h>
#include <classes/vector3.h>
#include <classes/base/entity.h>


class Player : public Entity {
    alt::Ref<alt::IPlayer> player;
public:
    Player(alt::Ref<alt::IPlayer> player) : player(player), Entity(player) {};

    alt::Ref<alt::IPlayer> GetBaseObject() const { return player; }

    static py::list GetAllPlayers(const py::object& self) {
        auto players = Core->GetPlayers();
        py::list pyList;
        for (const auto& player : players) {
            pyList.append(py::cast(Player(player)));
        }
        return pyList;
    }

    // Health
    uint16_t GetHealth() const { return player->GetHealth(); }
    void SetHealth(uint16_t number) { player->SetHealth(number); }
    bool IsDead() { return player->IsDead(); }

    // Armour
    uint16_t GetArmour() const { return player->GetArmour(); }
    void SetArmour(uint16_t number) { player->SetArmour(number); }
    uint16_t GetMaxArmour() const { return player->GetMaxArmour(); }
    void SetMaxArmour(uint16_t number) { return player->SetMaxArmour(number); }

    // Rotation
    Vector3 GetHeadRotation() const { return player->GetHeadRotation(); }

    // Model
    void SetModel(const py::object& model);
    void ClearBloodDamage() { player->ClearBloodDamage(); }


    // Authentication
    std::string GetName() const { return player->GetName().ToString(); }
    std::string GetAuthToken() const { return player->GetAuthToken().ToString(); }
    uint64_t GetHWIDHash() const { return player->GetHwidHash(); }
    uint64_t GetHWIDExHash() const { return player->GetHwidExHash(); }
    std::string GetIP() const { return player->GetIP().ToString(); }
    uint64_t GetSocialId() const { return player->GetSocialID(); }

    // Connection Info
    bool IsConnected() const { return player->IsConnected(); }
    uint32_t GetPing() const { return player->GetPing(); }
    void Kick(const std::string& reason="Kicked") { player->Kick(reason); }


    // Weapons
    uint32_t GetCurrentWeapon() const { return player->GetCurrentWeapon();}
    void SetCurrentWeapon(uint32_t weaponHash) { player->SetCurrentWeapon(weaponHash); }
    void GiveWeapon(uint32_t weaponHash, int ammoCount, bool equipNow) { player->GiveWeapon(weaponHash, ammoCount, equipNow); }
    void GiveWeapon(const std::string& weaponName, int ammoCount, bool equipNow) { player->GiveWeapon(Core->Hash(weaponName), ammoCount, equipNow); }

    void RemoveWeapon(uint32_t weaponHash) { player->RemoveWeapon(weaponHash); }
    void RemoveWeapon(const std::string& weaponName) { player->RemoveWeapon(Core->Hash(weaponName)); }
    void RemoveAllWeapons() { player->RemoveAllWeapons(); }

    py::list GetCurrentWeaponComponents() const { return Utils::ArrayToPyList(player->GetCurrentWeaponComponents()); }
    uint8_t GetCurrentWeaponTintIndex() const { return player->GetCurrentWeaponTintIndex(); }

    uint8_t GetWeaponTintIndex(uint32_t weaponHash) { return player->GetWeaponTintIndex(weaponHash); }
    uint8_t GetWeaponTintIndex(const std::string& weaponName) { return player->GetWeaponTintIndex(Core->Hash(weaponName)); }

    bool HasWeaponComponent(uint32_t weapon, uint32_t component) { return player->HasWeaponComponent(weapon, component); }
    bool HasWeaponComponent(const std::string& weapon, uint32_t component) { return player->HasWeaponComponent(Core->Hash(weapon), component); }
    bool HasWeaponComponent(uint32_t weapon, const std::string& component) { return player->HasWeaponComponent(weapon, Core->Hash(component)); }
    bool HasWeaponComponent(const std::string& weapon, const std::string& component) { return player->HasWeaponComponent(Core->Hash(weapon), Core->Hash(component)); }

    void AddWeaponComponent(uint32_t weapon, uint32_t component) { return player->AddWeaponComponent(weapon, component); }
    void AddWeaponComponent(const std::string& weapon, uint32_t component) { return player->AddWeaponComponent(Core->Hash(weapon), component); }
    void AddWeaponComponent(uint32_t weapon, const std::string& component) { return player->AddWeaponComponent(weapon, Core->Hash(component)); }
    void AddWeaponComponent(const std::string& weapon, const std::string& component) { return player->AddWeaponComponent(Core->Hash(weapon), Core->Hash(component)); }

    void RemoveWeaponComponent(uint32_t weapon, uint32_t component) { return player->RemoveWeaponComponent(weapon, component); }
    void RemoveWeaponComponent(const std::string& weapon, uint32_t component) { return player->RemoveWeaponComponent(Core->Hash(weapon), component); }
    void RemoveWeaponComponent(uint32_t weapon, const std::string& component) { return player->RemoveWeaponComponent(weapon, Core->Hash(component)); }
    void RemoveWeaponComponent(const std::string& weapon, const std::string& component) { return player->RemoveWeaponComponent(Core->Hash(weapon), Core->Hash(component)); }

    void SetWeaponTintIndex(uint32_t weapon, uint8_t tintIndex) { return player->SetWeaponTintIndex(weapon, tintIndex); }
    void SetWeaponTintIndex(const std::string& weapon, uint8_t tintIndex) { return player->SetWeaponTintIndex(Core->Hash(weapon), tintIndex); }

    bool IsFlashlightActive() const { return player->IsFlashlightActive(); }

    // Actions
    bool IsJumping() { return player->IsJumping(); }
    bool IsInRagdoll() { return player->IsInRagdoll(); }
    bool IsShooting() { return player->IsShooting(); }
    bool IsAiming() { return player->IsAiming(); }
    bool IsReloading() { return player->IsReloading(); }

    // Time
    void SetDateTime(int second, int minute, int hour, int day, int month, int year) { player->SetDateTime(day, month, year, hour, minute, second); }

    // Weather
    void SetWeather(uint32_t weather) { player->SetWeather(weather); }

    // Speed
    float GetMoveSpeed() const { return player->GetMoveSpeed(); }

    // Aiming
    Vector3 GetEntityAimingOffset() const { return player->GetEntityAimOffset(); }
    py::object GetEntityAimingAt() const {
        auto entity = player->GetEntityAimingAt();
        if (entity != 0)
            return py::cast(Entity(player->GetEntityAimingAt()));
        return py::none();
    }
    Vector3 GetAimPos() const { return player->GetAimPos(); }

    // Spawning
    void Spawn(float x, float y, float z, unsigned int delay);
    void Spawn(Vector3 coords, unsigned int delay);
    void Despawn() { player->Despawn(); }

    // Events
    void Emit(const std::string& eventName, const py::args& args);

    static void RegisterPlayerClass(const py::module_& m)
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
        pyClass.def_property_readonly("name", &Player::GetName);
        pyClass.def_property_readonly("authToken", &Player::GetAuthToken);
        pyClass.def_property_readonly("hwidHash", &Player::GetHWIDHash);
        pyClass.def_property_readonly("hwidExHash", &Player::GetHWIDExHash);
        pyClass.def_property_readonly("ip", &Player::GetIP);
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
        pyClass.def("removeWeapon", py::overload_cast<const std::string&>(&Player::GetWeaponTintIndex));

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

        pyClass.def("setWeaponComponent", py::overload_cast<uint32_t, uint8_t>(&Player::SetWeaponTintIndex));
        pyClass.def("setWeaponComponent", py::overload_cast<const std::string&, uint8_t>(&Player::SetWeaponTintIndex));

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

        // Event
        pyClass.def("emit", &Player::Emit);
    }
};
