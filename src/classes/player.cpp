#include "player.h"

void Player::Spawn(float x, float y, float z, unsigned int delay) {
    alt::Position altPos {x, y, z};
    player->Spawn(altPos, delay);
}