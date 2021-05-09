#pragma once
#include <main.h>


class Player {
    alt::RefBase<alt::RefStore<alt::IPlayer>> player;

public:
    unsigned short get_health() const { return player->GetHealth(); }
    void set_health(int number) { player->SetHealth(number); }
    explicit Player(alt::RefBase<alt::RefStore<alt::IPlayer>> &&player) : player(player) {};
};
