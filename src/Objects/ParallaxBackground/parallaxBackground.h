#ifndef PARALLAX_H
#define PARALLAX_H

#include "gameObject.h"
#include "spriteRenderer.h"
#include <raylib.h>

struct parallax_background_t {
    // VALUES
    Vector2 initialPosition;
    Vector2 offset;
    // COMPONENTS
    GameObject gameObject;
};

typedef struct parallax_background_t ParallaxBackground;
#endif
