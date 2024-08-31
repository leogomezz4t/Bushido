#ifndef SPRITE_ANIMATION_H
#define SPRITE_ANIMATION_H

#include <raylib.h>
#include <stdbool.h>

#define BASE_ROOT_PATH "artwork/sprites/"

#define FILE_ROOT "tile"
#define FILE_EXT ".png"
#define MAX_FILE_PATH_LENGTH 400
#define MAX_FRAME_LENGTH 30

typedef char FRAME_PATHS_T[MAX_FRAME_LENGTH][MAX_FILE_PATH_LENGTH];

typedef struct {
    char animationName[256];
    const char* spriteName;
    char rootFilePath[MAX_FILE_PATH_LENGTH]; 

    // frames
    char framePaths[MAX_FRAME_LENGTH][MAX_FILE_PATH_LENGTH];
    int frameLength;

    // loaded textures
    Texture2D loadedTextures[MAX_FRAME_LENGTH]; 
    int loadedTexturesLength;
} SpriteAnimation;

SpriteAnimation SpriteAnimation_From(const char* animationName, const char* spriteName);

int SpriteAnimation_GetFrameLength(SpriteAnimation* ani);

void SpriteAnimation_GetFramePaths(SpriteAnimation* ani, FRAME_PATHS_T framePaths);

void SpriteAnimation_LoadTextures(SpriteAnimation* ani);

void SpriteAnimation_UnloadTextures(SpriteAnimation* ani);

bool SpriteAnimation_AreTexturesReady(SpriteAnimation* ani);
#endif
