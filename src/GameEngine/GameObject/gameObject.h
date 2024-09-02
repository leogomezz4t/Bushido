#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <stdbool.h>
#include "vector2.h"

typedef struct GameObject {
    Vector2 position;
    // movement
    Vector2 velocity;

    // Parent struct
    void* parentData;
    
    // behaviour
    void (*update)(void*);

    bool isActive;
} GameObject;

GameObject GameObject_From(int x, int y);

#endif
