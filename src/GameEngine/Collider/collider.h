#ifndef COLLIDER_H
#define COLLIDER_H

#include "hitbox.h"
#include "gameObject.h"

#define MAX_HITBOXES 10

enum ColliderType {
    COLLIDER_OVERLAPPING,
    COLLIDER_BLOCKING
};

struct collider_t {
    enum ColliderType type;    

    // hitboxes
    Hitbox hitboxes[MAX_HITBOXES];
    int hitboxesLength;

    // references
    GameObject* gameObject;
};

typedef struct collider_t Collider;

// methods
Collider Collider_From(enum ColliderType type, GameObject* go);

void Collider_AddHitbox(Collider* col, float offsetX, float offsetY, int width, int height);
#endif
