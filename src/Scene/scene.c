#include "scene.h"
#include "stdio.h"
#include "spriteRenderer.h"
#include "gameObject.h"

Scene Scene_From(int id) {
    return (Scene) { id };
}

void Scene_AddGameObject(Scene* scene, GameObject* go) {
    if (scene->gameObjectsLength >= MAX_GAME_OBJECTS_PER_SCENE) {
        printf("Scene_AddGameObject(): Tried to add more than %d GameObjects\n", MAX_GAME_OBJECTS_PER_SCENE);
    } else {
        scene->gameObjects[scene->gameObjectsLength] = go;
        scene->gameObjectsLength++;
    }
}
void Scene_AddSpriteRenderer(Scene* scene, SpriteRenderer* sr) {
    if (scene->spriteRenderersLength >= MAX_GAME_OBJECTS_PER_SCENE) {
        printf("Scene_AddSpriteRenderer(): Tried to add more than %d SpriteRenderers\n", MAX_GAME_OBJECTS_PER_SCENE);
    } else {
        scene->spriteRenderers[scene->spriteRenderersLength] = sr;
        scene->spriteRenderersLength++;
    }
}

void Scene_Update(Scene* scene) {
    // iterate through the layers
    for (int j = 0; j < scene->gameObjectsLength; j++) {
        GameObject* go = scene->gameObjects[j];
        // dont update if not active
        if (!go->isActive) {
            continue;
        }

        go->update(go->parentData); 
    } 
}
