#include "player.h"

void Player::Spawn(float x, float y, float z, unsigned int delay) {
    alt::Position altPos {x, y, z};
    player->Spawn(altPos, delay);
}

void Player::Spawn(Vector3 coords, unsigned int delay) {
    player->Spawn(coords.toAltPos(), delay);
}