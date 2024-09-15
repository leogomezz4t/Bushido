#ifndef ENTITY_H
#define ENTITY_H

#include "stdbool.h"

struct entity_t {
    int hitpoints;
    int maxHitpoints;
    // damage taking
    bool invincible;

    // knockback
};

typedef struct entity_t Entity;

Entity Entity_From(int maxHitpoints);
#endif
