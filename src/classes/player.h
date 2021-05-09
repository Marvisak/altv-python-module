#pragma once
#include <main.h>
#include <classes/vector3.h>


class Player {
    alt::RefBase<alt::RefStore<alt::IPlayer>> player;
public:
    explicit Player(alt::RefBase<alt::RefStore<alt::IPlayer>> &&player) : player(player) {};

    //Health
    unsigned short GetHealth() const { return player->GetHealth(); }
    void SetHealth(int number) { player->SetHealth(number); }

    //Position
    void Spawn(float x, float y, float z, unsigned int delay);

};
