#pragma once
#include <main.h>
#include <utils.h>
#include <classes/vector3.h>

class Player {
    alt::Ref<alt::IPlayer> player;
public:

    explicit Player(alt::Ref<alt::IPlayer> player) : player(player) {};

    alt::Ref<alt::IPlayer> GetBaseObject() const { return player; }

    static py::list GetAllPlayers(const py::object& self) {
        auto players = Core->GetPlayers();
        py::list pyList;
        for (const auto& player : players) {
            pyList.append(py::cast(Player(player)));
        }
        return pyList;
    }

    //Health
    unsigned short GetHealth() const { return player->GetHealth(); }
    void SetHealth(int number) { player->SetHealth(number); }

    // Armour
    unsigned short GetArmour() const { return player->GetArmour(); }
    void SetArmour(int number) { player->SetArmour(number); }

    // Model
    void SetModel(const py::object& model);
    unsigned int GetModel() const {return player->GetModel();};

    // Authentication
    std::string GetAuthToken() const { return player->GetAuthToken().ToString(); }
    unsigned long long GetHWIDHash() const { return player->GetHwidHash(); }
    unsigned long long GetHWIDExHash() const { return player->GetHwidExHash(); }
    std::string GetIP() const { return player->GetIP().ToString(); }
    unsigned long long GetSocialId() const { return player->GetSocialID(); }

    // Weapons
    unsigned int GetCurrentWeapon() const { return player->GetCurrentWeapon();}
    void SetCurrentWeapon(unsigned int weaponHash) { player->SetCurrentWeapon(weaponHash); }
    void GiveWeapon(unsigned int weaponHash, int ammoCount, bool equipNow) {player->GiveWeapon(weaponHash, ammoCount, equipNow);};


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
        py::class_<Player>(m, "Player")
            // Static

            .def_property_readonly_static("all", &Player::GetAllPlayers)

            // Spawning
            .def("spawn", py::overload_cast<float, float, float, unsigned int>(&Player::Spawn))
            .def("spawn", py::overload_cast<Vector3, unsigned int>(&Player::Spawn))

            // Health
            .def_property("health", &Player::GetHealth, &Player::SetHealth)
            // Armour
            .def_property("armour", &Player::GetArmour, &Player::SetArmour)
            // Model
            .def_property("model", &Player::GetModel, &Player::SetModel)

            // Auth
            .def_property_readonly("authToken", &Player::GetAuthToken)
            .def_property_readonly("hwidHash", &Player::GetHWIDHash)
            .def_property_readonly("hwidExHash", &Player::GetHWIDExHash)
            .def_property_readonly("ip", &Player::GetIP)
            .def_property_readonly("socialId", &Player::GetSocialId)

            // Weapons
            .def_property("currentWeapon", &Player::GetCurrentWeapon, &Player::SetCurrentWeapon)
            .def("giveWeapon", &Player::GiveWeapon)

            // Event
            .def("emit", &Player::Emit);
    }
};
