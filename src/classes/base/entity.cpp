#include "entity.h"
#include <classes/base/player.h>

Player Entity::GetNetOwner() const {
    return entity->GetNetworkOwner();
}
