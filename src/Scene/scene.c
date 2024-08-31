#include "scene.h"
#include "gameObject.h"

Scene Scene_From(int id) {
    return (Scene) { id };
}

void Scene_Update(Scene* scene) {
    // iterate through the layers
    for (int i = 0; i < MAX_LAYER+1; i++) {
        for (int j = 0; j < scene->gameObjectsLength; j++) {
            GameObject* go = scene->gameObjects + j;
            // filter out for the correct draw layer
            if (go->drawLayer != i) {
                continue;
            }

            // dont update if not active
            if (!go->isActive) {
                continue;
            }

            // draw the game object

        } 
    } 
}
