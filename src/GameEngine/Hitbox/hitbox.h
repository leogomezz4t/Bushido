#ifndef HITBOX_H
#define HITBOX_H

#include "gameObject.h"
#include "stdbool.h"
#include "vector2.h"

struct hitbox_t {
    Vector2 offset;

    int width;
    int height;
    
    // debug
    bool debug;

    // references
    GameObject* gameObject;
};

// Methods
Hitbox Hitbox_From(float xOffset, float yOffset, int width, int height);

Vector2 Hitbox_GetPosition(Hitbox* hb);

bool Hitbox_OverlappingWith(Hitbox* hb, Hitbox* target);
#endif
