#include "entity.h"

Entity Entity_From(int maxHitpoints) {
    Entity e;

    // parameter values
    e.maxHitpoints = maxHitpoints;
    e.hitpoints = maxHitpoints;

    // default values
    e.invincible = false;

    return e;
}
