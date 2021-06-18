#include "entity.h"
#include <classes/base/player.h>

Player Entity::GetNetOwner() const {
    return entity->GetNetworkOwner();
}

void Entity::SetNetOwner(const Player& player, bool disableMigration) {
    entity->SetNetworkOwner(player.GetBaseObject(), disableMigration);
}