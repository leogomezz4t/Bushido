#ifndef SPRITE_RENDERER_H
#define SPRITE_RENDERER_H

#include "spriteAnimation.h"
#include "sprite.h"
#include "gameObject.h"
#include "orientation.h"

typedef struct {
    char spriteName[256];
    int currentAnimationIndex;

    // Sprite reference
    Sprite* sprite;

    // references
    GameObject* gameObject;

    // Frame counting
    int currentFrame;

    // delay counter
    int frameDelay;
    int _frameCounter;

    // transform
    Vector2 positionOffset;
    float scale;
    Orientation orientation;
} SpriteRenderer;

SpriteAnimation* SpriteRenderer_GetCurrentSpriteAnimation(SpriteRenderer* sr);

SpriteRenderer SpriteRenderer_From(const char* spriteName, GameObject* go);

Vector2 SpriteRenderer_GetPosition(SpriteRenderer* sr);

Texture2D SpriteRenderer_GetCurrentFrame(SpriteRenderer* sr);

void SpriteRenderer_NextFrame(SpriteRenderer* sr);

void SpriteRenderer_Animate(SpriteRenderer* sr);

#endif
