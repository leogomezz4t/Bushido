#ifndef SCENE_H
#define SCENE_H

#include "gameObject.h"
#include "collider.h"
#include "spriteRenderer.h"
#include <stdbool.h>

#define MAX_GAME_OBJECTS_PER_SCENE 200
#define MAX_LAYER 5
#define MAX_LOADED_SPRITES 20
#define MAX_SPRITE_NAME 50
#define ID_STRING_SIZE 11
#define MAX_LOADED_TEXTURES 20

struct scene_t {
    char id[ID_STRING_SIZE];
    // data
    bool isLoaded;

    void (*customUpdate) (struct scene_t*);

    // image loading
    const char* texturesToLoad[MAX_LOADED_TEXTURES];
    Texture2D loadedTextures[MAX_LOADED_TEXTURES];
    int loadedTexturesLength;

    // sprite loading
    Sprite loadedSprites[MAX_LOADED_SPRITES];
    int loadedSpritesLength;

    // Camera
    Camera2D* currentCamera;

    // collections
    GameObject* gameObjects[MAX_GAME_OBJECTS_PER_SCENE];
    int gameObjectsLength;

    SpriteRenderer* spriteRenderers[MAX_GAME_OBJECTS_PER_SCENE];
    int spriteRenderersLength;

    Collider* colliders[MAX_GAME_OBJECTS_PER_SCENE];
    int collidersLength;
};

typedef struct scene_t Scene;

Scene Scene_From(const char * name);

void Scene_Load(Scene* scene);

void Scene_SetGameCamera(Scene* scene, Camera2D* cam);

void Scene_BeginCameraMode(Scene* scene);

void Scene_EndCameraMode(Scene* scene);

bool Scene_HasSprite(Scene* scene, const char* spriteName);

void Scene_LoadSprites(Scene* scene);

void Scene_UnloadSprites(Scene* scene);

Sprite* Scene_AddSprite(Scene* scene, const char* spriteName);

void Scene_AddGameObject(Scene* scene, GameObject* go);

void Scene_AddCollider(Scene* scene, Collider* coll);

int Scene_GetOverlappingColliders(Scene* scene, Collider* coll, Collider** results, int resultsLength);

void Scene_AddSpriteRenderer(Scene* scene, SpriteRenderer* sr);

Texture2D* Scene_AddTexture(Scene* scene, const char* filepath);

void Scene_LoadTextures(Scene* scene);

void Scene_UnloadTexture(Scene* scene);

void Scene_Update(Scene* scene);

#endif
