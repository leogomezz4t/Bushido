#include "spriteAnimation.h"
#include <raylib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>

SpriteAnimation SpriteAnimation_From(const char* animationName, const char* spriteName) {
    SpriteAnimation ani;
    // Animation name
    strcpy(ani.animationName, animationName);

    // copy root first
    strcpy(ani.rootFilePath, BASE_ROOT_PATH);
    // add the desired path
    strcat(ani.rootFilePath, spriteName);
    strcat(ani.rootFilePath, "/");
    // add the animation name
    strcat(ani.rootFilePath, animationName);
    // Make sure it has a trailing slash
    strcat(ani.rootFilePath, "/");

    ani.frameLength = SpriteAnimation_GetFrameLength(&ani);
    SpriteAnimation_GetFramePaths(&ani, ani.framePaths);

    ani.loadedTexturesLength = 0;

    return ani;
}

int SpriteAnimation_GetFrameLength(SpriteAnimation* ani) {
    DIR* dir;
    struct dirent* entry;
    int count = 0;

    dir = opendir(ani->rootFilePath);
    if (dir == NULL) {
        perror("opendir");
        return -1;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            count++;
        }
    }

    closedir(dir);
    return count;
}

void SpriteAnimation_GetFramePaths(SpriteAnimation* ani, FRAME_PATHS_T framePaths) {
    for (int i = 0; i < ani->frameLength; i++) {
        // copy root
        strcpy(framePaths[i], ani->rootFilePath);
        strcat(framePaths[i], FILE_ROOT);
        
        // pad the index
        char paddedIndex[12];
        sprintf(paddedIndex, "%03d", i);
        strcat(framePaths[i], paddedIndex);
        // copy the extension
        strcat(framePaths[i], FILE_EXT);
    }
}

void SpriteAnimation_LoadTextures(SpriteAnimation* ani) {
    // This function must be run with an OpenGL content after the Raylib InitWindow()

    // iter through frame paths
    for (int i = 0; i < ani->frameLength; i++) {
        ani->loadedTextures[i] = LoadTexture(ani->framePaths[i]);
    }

    // set new length for textures
    ani->loadedTexturesLength = ani->frameLength;
}

void SpriteAnimation_UnloadTextures(SpriteAnimation* ani) {
    // iter through textures
    for (int i = 0; i < ani->loadedTexturesLength; i++) {
        UnloadTexture(ani->loadedTextures[i]);
    }

    // update
    ani->loadedTexturesLength = 0;
}

bool SpriteAnimation_AreTexturesReady(SpriteAnimation* ani) {
    for (int i = 0; i < ani->loadedTexturesLength; i++) {
        if (!IsTextureReady(ani->loadedTextures[i])) {
            return false;
        }
    }
    return true;
}
