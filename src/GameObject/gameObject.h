#include "vectors.h"
#include "orientation.h"
#include <stdbool.h>

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
} GameObject;
