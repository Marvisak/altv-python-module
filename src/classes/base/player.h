#pragma once
#include <main.h>
#include <classes/vector3.h>

#include <utility>


class Player {
    alt::RefBase<alt::RefStore<alt::IPlayer>> player;
public:
    explicit Player(alt::RefBase<alt::RefStore<alt::IPlayer>> &&player) : player(player) {};

    alt::RefBase<alt::RefStore<alt::IPlayer>> GetBaseObject() { return player; }

    //Health
    unsigned short GetHealth() const { return player->GetHealth(); }
    void SetHealth(int number) { player->SetHealth(number); }

    //Position
    void Spawn(float x, float y, float z, unsigned int delay);

    static void RegisterPlayerClass(py::module_ m)
    {
        py::class_<Player>(std::move(m), "player")
            .def("spawn", &Player::Spawn)
            .def_property("health", &Player::GetHealth, &Player::SetHealth);
    }
};
