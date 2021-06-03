#pragma once
#include <main.h>
#include <classes/vector3.h>

#include <utility>


class Player {
    alt::Ref<alt::IPlayer> player;
public:
    explicit Player(alt::Ref<alt::IPlayer> &&player) : player(player) {};

    alt::RefBase<alt::RefStore<alt::IPlayer>> GetBaseObject() { return player; }

    //Health
    unsigned short GetHealth() const { return player->GetHealth(); }
    void SetHealth(int number) { player->SetHealth(number); }

    // Armour
    unsigned short GetArmour() const { return player->GetArmour(); }
    void SetArmour(int number) { player->SetArmour(number); }

    // Authentication
    std::string GetAuthToken() const { return player->GetAuthToken().ToString(); }
    unsigned long long GetHWIDHash() const { return player->GetHwidHash(); }
    unsigned long long GetHWIDExHash() const { return player->GetHwidExHash(); }
    std::string GetIP() const { return player->GetIP().ToString(); }
    unsigned long long GetSocialId() const { return player->GetSocialID(); }

    //Position
    void Spawn(float x, float y, float z, unsigned int delay);
    void Spawn(Vector3 coords, unsigned int delay);

    static void RegisterPlayerClass(py::module_ m)
    {
        py::class_<Player>(std::move(m), "player")
            .def("spawn", py::overload_cast<float, float, float, unsigned int>(&Player::Spawn))
            .def("spawn", py::overload_cast<Vector3, unsigned int>(&Player::Spawn))
            .def_property("health", &Player::GetHealth, &Player::SetHealth)
            .def_property("armour", &Player::GetArmour, &Player::SetArmour)
            .def_property_readonly("authToken", &Player::GetAuthToken)
            .def_property_readonly("hwidHash", &Player::GetHWIDHash)
            .def_property_readonly("hwidExHash", &Player::GetHWIDExHash)
            .def_property_readonly("ip", &Player::GetIP)
            .def_property_readonly("socialId", &Player::GetSocialId);
    }
};
