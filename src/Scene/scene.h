#ifndef SCENE_H
#define SCENE_H

#include "gameObject.h"
#include "spriteRenderer.h"
#include <stdbool.h>

#define MAX_GAME_OBJECTS_PER_SCENE 200
#define MAX_LAYER 5

typedef struct {
    int id;

    // data
    bool isLoaded;

    // collections
    GameObject* gameObjects[MAX_GAME_OBJECTS_PER_SCENE];
    int gameObjectsLength;

    SpriteRenderer* spriteRenderers[MAX_GAME_OBJECTS_PER_SCENE];
    int spriteRenderersLength;
} Scene;

Scene Scene_From(int id);

void Scene_AddGameObject(Scene* scene, GameObject* go);

void Scene_AddSpriteRenderer(Scene* scene, SpriteRenderer* sr);

void Scene_Update(Scene* scene);

#endif
