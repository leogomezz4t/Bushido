#ifndef SPRITE_RENDERER_H
#define SPRITE_RENDERER_H

#include "spriteAnimation.h"

typedef struct {
    SpriteAnimation* currentAnimation;

    // Frame counting
    int currentFrame;

    // delay counter
    int frameDelay;
    int _frameCounter;

    // transform
    Vector2 position;
} SpriteRenderer;

SpriteRenderer SpriteRenderer_From(int x, int y);

Texture2D SpriteRenderer_GetCurrentFrame(SpriteRenderer* sr);

void SpriteRenderer_NextFrame(SpriteRenderer* sr);

void SpriteRenderer_Animate(SpriteRenderer* sr);

#endif
