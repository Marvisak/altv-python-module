#include "player.h"

void Player::Spawn(float x, float y, float z, unsigned int delay) {
    alt::Position altPos {x, y, z};
    player->Spawn(altPos, delay);
}

void Player::Spawn(Vector3 coords, unsigned int delay) {
    player->Spawn(coords.toAltPos(), delay);
}

void Player::SetModel(const py::object& model) {
    auto type = Utils::GetTypeOfObject(model);
    if (type == "str") {
        uint32_t modelHash = Core->Hash(py::str(model).cast<std::string>());
        player->SetModel(modelHash);
    } else if (type == "int" || type == "float") {
        player->SetModel(py::int_(model).cast<unsigned int>());
    }
}
