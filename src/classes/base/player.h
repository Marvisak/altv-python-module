#pragma once
#include "main.h"
#include "utils.h"
#include "classes/vector3.h"
#include "entity.h"
#include "vehicle.h"
#include "../clothes.h"

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

    // Vehicles
    bool IsInVehicle() { return player->IsInVehicle(); }
    Vehicle GetVehicle() { return player->GetVehicle(); }
    uint8_t GetSeat() { return player->GetSeat(); }

    // Clothes

    Clothes GetClothes(uint8_t component) { return player->GetClothes(component); }
    void SetClothes(uint8_t component, uint16_t drawable, uint8_t texture, uint8_t palette) { player->SetClothes(component, drawable, texture, palette); }

    // Events
    void Emit(const std::string& eventName, const py::args& args);
};

void RegisterPlayerClass(const py::module_& m);
