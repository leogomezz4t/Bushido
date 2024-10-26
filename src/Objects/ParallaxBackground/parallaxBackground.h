#ifndef PARALLAX_H
#define PARALLAX_H

#include "gameObject.h"
#include "spriteRenderer.h"
#include <raylib.h>

#define PARALLAX_BACKGROUND_TYPE "parallax"

enum BackgroundType {
    BACK,
    MID,
    FORE
};

struct single_background_t {
    enum BackgroundType type;
    Vector2 position;
};

struct parallax_background_t {
    // VALUES
    Vector2 initialPosition;
    Vector2 offset;

    float scale;

    Texture2D* backLayerTexture;
    Texture2D* midLayerTexture;
    Texture2D* foreLayerTexture;

    int numCopies;
    // COMPONENTS
    GameObject gameObject;
};

typedef struct parallax_background_t ParallaxBackground;

void ParallaxBackground_Init(ParallaxBackground* bg, int x, int y);
#endif
