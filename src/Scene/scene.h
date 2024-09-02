#ifndef SCENE_H
#define SCENE_H

#include "gameObject.h"
#include "spriteRenderer.h"
#include <stdbool.h>

#define MAX_GAME_OBJECTS_PER_SCENE 200
#define MAX_LAYER 5
#define MAX_LOADED_SPRITES 100
#define MAX_SPRITE_NAME 50

typedef struct {
    int id;

    // data
    bool isLoaded;

    // sprite loading
    Sprite loadedSprites[MAX_LOADED_SPRITES];
    int loadedSpritesLength;

    // collections
    GameObject* gameObjects[MAX_GAME_OBJECTS_PER_SCENE];
    int gameObjectsLength;

    SpriteRenderer* spriteRenderers[MAX_GAME_OBJECTS_PER_SCENE];
    int spriteRenderersLength;
} Scene;

Scene Scene_From(int id);

bool Scene_HasSprite(Scene* scene, const char* spriteName);

void Scene_LoadSprites(Scene* scene);

void Scene_UnloadSprites(Scene* scene);

Sprite* Scene_AddSprite(Scene* scene, const char* spriteName);

void Scene_AddGameObject(Scene* scene, GameObject* go);

void Scene_AddSpriteRenderer(Scene* scene, SpriteRenderer* sr);

void Scene_Update(Scene* scene);

#endif
