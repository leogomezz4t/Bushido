#include "spriteRenderer.h"
#include "stdlib.h"
#include <raylib.h>

#define BUSHIDO_FRAME_DELAY 7

SpriteRenderer SpriteRenderer_From(int x, int y) {
    SpriteRenderer ret;
    ret.currentFrame = 0;
    ret.currentAnimation = NULL;

    ret.frameDelay = BUSHIDO_FRAME_DELAY;
    ret._frameCounter = 0;

    ret.position.x = x;
    ret.position.y = y;

    return ret;
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
    DrawTextureEx(SpriteRenderer_GetCurrentFrame(sr), sr->position, 0.0f, 5.0f, WHITE);

    // increment frame delay counter
    sr->_frameCounter++;
}

