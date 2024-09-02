#ifndef SPRITE_H
#define SPRITE_H

#include "spriteAnimation.h"
#include <stdbool.h>

#define MAX_ANIMATION_LENGTH 15

typedef struct {
    const char* spriteName;

    SpriteAnimation spriteAnimations[MAX_ANIMATION_LENGTH]; 
    int spriteAnimationsLength;
} Sprite;

Sprite Sprite_From(const char* name);

bool Sprite_AreAllAnimationsLoaded(Sprite* s);

void Sprite_AddAnimation(Sprite* s, const char* name);

void Sprite_LoadAnimations(Sprite* s);

void Sprite_UnloadAnimations(Sprite* s);
#endif
