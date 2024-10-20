#ifndef COLLIDER_H
#define COLLIDER_H

#include "hitbox.h"
#include "gameObject.h"

#define MAX_HITBOXES 10

struct collider_t {
    // hitboxes
    Hitbox hitboxes[MAX_HITBOXES];
    int hitboxesLength;

    // references
    GameObject* gameObject;
};

// methods
Collider Collider_From(GameObject* go);

void Collider_AddHitbox(Collider* col, float offsetX, float offsetY, int width, int height);

bool Collider_OverlappingWith(Collider* coll, Collider* target);

void Collider_SetDebug(Collider* coll, bool state);
#endif
