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
    void SetHealth(int number) { player->SetHealth(number); }

    // Armour
    uint16_t GetArmour() const { return player->GetArmour(); }
    void SetArmour(int number) { player->SetArmour(number); }

    // Model
    void SetModel(const py::object& model);

    // Authentication
    std::string GetAuthToken() const { return player->GetAuthToken().ToString(); }
    uint64_t GetHWIDHash() const { return player->GetHwidHash(); }
    uint64_t GetHWIDExHash() const { return player->GetHwidExHash(); }
    std::string GetIP() const { return player->GetIP().ToString(); }
    uint64_t GetSocialId() const { return player->GetSocialID(); }

    // Weapons
    uint32_t GetCurrentWeapon() const { return player->GetCurrentWeapon();}
    void SetCurrentWeapon(unsigned int weaponHash) { player->SetCurrentWeapon(weaponHash); }
    void GiveWeapon(unsigned int weaponHash, int ammoCount, bool equipNow) { player->GiveWeapon(weaponHash, ammoCount, equipNow); }
    void GiveWeapon(const std::string& weaponName, int ammoCount, bool equipNow) { player->GiveWeapon(Core->Hash(weaponName), ammoCount, equipNow); }
    py::list GetCurrentWeaponComponents() const { return Utils::ArrayToPyList(player->GetCurrentWeaponComponents()); }
    uint8_t GetCurrentWeaponTintIndex() const { return player->GetCurrentWeaponTintIndex(); }


    // Entity Aiming
    Vector3 GetEntityAimingOffset() const { return player->GetEntityAimOffset(); }
    py::object GetEntityAimingAt() const {
        auto entity = player->GetEntityAimingAt();
        if (entity != 0) {
            return py::cast(Entity(player->GetEntityAimingAt()));
        } else {
            return py::none();
        }
    }


    // Spawning
    void Spawn(float x, float y, float z, unsigned int delay);
    void Spawn(Vector3 coords, unsigned int delay);

    // Events
    void Emit(const std::string& eventName, const py::args& args) {
        if (std::find(Utils::EventTypes.begin(), Utils::EventTypes.end(), eventName) != Utils::EventTypes.end())
            return;
        alt::MValueArgs eventArgs;
        for (const py::handle& arg : *args)
        {
            eventArgs.Push(Utils::ValueToMValue(arg.cast<py::object>()));
        }
        Core->TriggerClientEvent(player, eventName, eventArgs);
    }

    static void RegisterPlayerClass(const py::module_& m)
    {
        auto pyClass = py::class_<Player, Entity>(m, "Player");

        // Static
        pyClass.def_property_readonly_static("all", &Player::GetAllPlayers);

        // Spawning
        pyClass.def("spawn", py::overload_cast<float, float, float, unsigned int>(&Player::Spawn));
        pyClass.def("spawn", py::overload_cast<Vector3, unsigned int>(&Player::Spawn));

        // Health
        pyClass.def_property("health", &Player::GetHealth, &Player::SetHealth);
        // Armour
        pyClass.def_property("armour", &Player::GetArmour, &Player::SetArmour);
        // Model
        pyClass.def_property("model", &Player::GetModel, &Player::SetModel);

        // Auth
        pyClass.def_property_readonly("authToken", &Player::GetAuthToken);
        pyClass.def_property_readonly("hwidHash", &Player::GetHWIDHash);
        pyClass.def_property_readonly("hwidExHash", &Player::GetHWIDExHash);
        pyClass.def_property_readonly("ip", &Player::GetIP);
        pyClass.def_property_readonly("socialId", &Player::GetSocialId);

        // Weapons
        pyClass.def_property("currentWeapon", &Player::GetCurrentWeapon, &Player::SetCurrentWeapon);
        pyClass.def_property_readonly("currentWeaponComponents", &Player::GetCurrentWeaponComponents);
        pyClass.def_property_readonly("currentWeaponTintIndex", &Player::GetCurrentWeaponTintIndex);
        pyClass.def("giveWeapon", py::overload_cast<unsigned int, int, bool>(&Player::GiveWeapon));
        pyClass.def("giveWeapon", py::overload_cast<const std::string&, int, bool>(&Player::GiveWeapon));

        // Aiming
        pyClass.def_property_readonly("entityAimingOffset", &Player::GetEntityAimingOffset);
        pyClass.def_property_readonly("entityAimingAt", &Player::GetEntityAimingAt);

        // Event
        pyClass.def("emit", &Player::Emit);
    }
};
