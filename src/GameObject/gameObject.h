#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <stdbool.h>
#include "vector2.h"
#include "orientation.h"

typedef struct {
    Vector2 position;
    
    // transform
    int width;
    int height;

    Orientation orientation;

    // movement
    Vector2 velocity;

    // visibility
    bool isActive;

    // draw layer
    int drawLayer;

    // sprite

} GameObject;

GameObject GameObject_From(int x, int y, int width, int height);

#endif
