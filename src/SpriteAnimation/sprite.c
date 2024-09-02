#include "sprite.h"
#include "spriteAnimation.h"
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

#define ROOT_FILE_PATH "artwork/sprites/"

Sprite Sprite_From(const char* name) {
    Sprite ret;
    ret.spriteName = name;
    ret.spriteAnimationsLength = 0;

    // setup file path
    char spriteDirectory[1024];
    strcpy(spriteDirectory, ROOT_FILE_PATH);
    strcat(spriteDirectory, name);


    // crawl artwork for animation names 
    DIR* dir;
    struct dirent* entry;
    int count = 0;

    dir = opendir(spriteDirectory);
    if (dir == NULL) {
        printf("Sprite_From(): Failed to open sprite directory\n");
        perror("opendir");
        return ret;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            // ignore directories such as . and ..
            if (strcmp(entry->d_name, ".") == 0) {
                continue;
            }
            if (strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            // Create animation
            Sprite_AddAnimation(&ret, entry->d_name);            
        }
    }

    closedir(dir);

    return ret;
}

bool Sprite_AreAllAnimationsLoaded(Sprite* s) {
    for (int i = 0; i < s->spriteAnimationsLength; i++) {
        SpriteAnimation* ani = s->spriteAnimations + i;
        if (!SpriteAnimation_AreTexturesReady(ani)) {
            return false;
        }
    }
    
    return true;
}

void Sprite_AddAnimation(Sprite* s, const char* name) {
    SpriteAnimation* ani = s->spriteAnimations + s->spriteAnimationsLength;  

    *ani = SpriteAnimation_From(name, s->spriteName);

    s->spriteAnimationsLength++;
}

void Sprite_LoadAnimations(Sprite* s) {
    for (int i = 0; i < s->spriteAnimationsLength; i++) {
        SpriteAnimation* ani = s->spriteAnimations + i;
        SpriteAnimation_LoadTextures(ani);
    }
}

void Sprite_UnloadAnimations(Sprite* s) {
    for (int i = 0; i < s->spriteAnimationsLength; i++) {
        SpriteAnimation* ani = s->spriteAnimations + i;
        SpriteAnimation_UnloadTextures(ani);
    }
}
