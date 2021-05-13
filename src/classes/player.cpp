#include "player.h"

void Player::Spawn(float x, float y, float z, unsigned int delay) {
    alt::Position altPos {x, y, z};
    base->Spawn(altPos, delay);
}