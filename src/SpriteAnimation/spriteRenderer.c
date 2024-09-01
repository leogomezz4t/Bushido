#include "spriteRenderer.h"
#include <stdio.h>
#include "orientation.h"
#include "spriteAnimation.h"
#include "stdlib.h"
#include <raylib.h>
#include <string.h>
#include "vector2.h"

#define BUSHIDO_FRAME_DELAY 7
#define EMPTY_ANIMATION_INDEX -1

SpriteRenderer SpriteRenderer_From(const char* spriteName, GameObject* go) {
    SpriteRenderer ret;

    ret.gameObject = go;

    strcpy(ret.spriteName, spriteName);

    ret.currentFrame = 0;
    ret.currentAnimationIndex = EMPTY_ANIMATION_INDEX;

    ret.frameDelay = BUSHIDO_FRAME_DELAY;
    ret._frameCounter = 0;

    ret.positionOffset = Vector2_From(0, 0);
    ret.scale = 1.0f;
    ret.orientation = ORIENTATION_RIGHT;

    return ret;
}

SpriteAnimation* SpriteRenderer_GetCurrentSpriteAnimation(SpriteRenderer* sr) {
    if (sr->currentAnimationIndex == EMPTY_ANIMATION_INDEX) {
        return NULL;
    }

    if (sr->currentAnimationIndex >= sr->sprite->spriteAnimationsLength) {
        return NULL;
    }

    return sr->sprite->spriteAnimations + sr->currentAnimationIndex;
}

Vector2 SpriteRenderer_GetPosition(SpriteRenderer* sr) {
    return Vector2_Add(sr->gameObject->position, sr->positionOffset); 
}

Texture2D SpriteRenderer_GetCurrentFrame(SpriteRenderer* sr) {
    return SpriteRenderer_GetCurrentSpriteAnimation(sr)->loadedTextures[sr->currentFrame];
}

void SpriteRenderer_NextFrame(SpriteRenderer* sr) {
    sr->currentFrame++;

    if (sr->currentFrame >= SpriteRenderer_GetCurrentSpriteAnimation(sr)->loadedTexturesLength) {
        sr->currentFrame = 0;
    }
}

void SpriteRenderer_Animate(SpriteRenderer* sr) {
    if (sr->currentAnimationIndex == EMPTY_ANIMATION_INDEX) {
        return;
    }
    // Check the frame delay
    if (sr->_frameCounter >= sr->frameDelay) {
        // reset frame counter
        sr->_frameCounter = 0;
        // go to the next frame
        SpriteRenderer_NextFrame(sr);
    }

    Rectangle r = {
        .width = SpriteRenderer_GetCurrentFrame(sr).width * sr->orientation,
        .height = SpriteRenderer_GetCurrentFrame(sr).height,
        .x = 0,
        .y = 0
    };
    // Draw the texture
    DrawTextureRec(
            SpriteRenderer_GetCurrentFrame(sr),
            r,
            SpriteRenderer_GetPosition(sr), 
            WHITE
    );

    // increment frame delay counter
    sr->_frameCounter++;
}

