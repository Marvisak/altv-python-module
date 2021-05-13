#pragma once
#include <main.h>
#include <classes/vector3.h>


class Player {
    alt::RefBase<alt::RefStore<alt::IPlayer>> base;
public:
    explicit Player(alt::RefBase<alt::RefStore<alt::IPlayer>> &&player) : base(player) {};

    //Health
    unsigned short GetHealth() const { return base->GetHealth(); }
    void SetHealth(int number) { base->SetHealth(number); }

    //Position
    void Spawn(float x, float y, float z, unsigned int delay);

};
