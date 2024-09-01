#include "spriteRenderer.h"
#include "stdlib.h"
#include <raylib.h>
#include <string.h>
#include "vector2.h"

#define BUSHIDO_FRAME_DELAY 7

SpriteRenderer SpriteRenderer_From(const char* spriteName, GameObject* go) {
    SpriteRenderer ret;

    ret.gameObject = go;

    strcpy(ret.spriteName, spriteName);

    ret.currentFrame = 0;
    ret.currentAnimation = NULL;

    ret.frameDelay = BUSHIDO_FRAME_DELAY;
    ret._frameCounter = 0;

    ret.positionOffset = Vector2_From(0, 0);

    ret.scale = 1.0f;

    return ret;
}

Vector2 SpriteRenderer_GetPosition(SpriteRenderer* sr) {
    return Vector2_Add(sr->gameObject->position, sr->positionOffset); 
}

Texture2D SpriteRenderer_GetCurrentFrame(SpriteRenderer* sr) {
    return sr->currentAnimation->loadedTextures[sr->currentFrame];
}

void SpriteRenderer_NextFrame(SpriteRenderer* sr) {
    sr->currentFrame++;

    if (sr->currentFrame >= sr->currentAnimation->loadedTexturesLength) {
        sr->currentFrame = 0;
    }
}

void SpriteRenderer_Animate(SpriteRenderer* sr) {
    // Check the frame delay
    if (sr->_frameCounter >= sr->frameDelay) {
        // reset frame counter
        sr->_frameCounter = 0;
        // go to the next frame
        SpriteRenderer_NextFrame(sr);
    }

    // Draw the texture
    DrawTextureEx(
            SpriteRenderer_GetCurrentFrame(sr),
            SpriteRenderer_GetPosition(sr),
            0.0f,
            5.0f,
            WHITE
    );

    // increment frame delay counter
    sr->_frameCounter++;
}

