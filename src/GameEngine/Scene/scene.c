#include "scene.h"
#include "collider.h"
#include "sprite.h"
#include "stdio.h"
#include "spriteRenderer.h"
#include "gameObject.h"
#include "componentUpdates.h"

#include <raylib.h>
#include <stdbool.h>
#include <string.h>

Scene Scene_From(const char * name) {
    Scene ret;

    // DEFAULT VALUES
    ret.customUpdate = NULL;

    ret.loadedTexturesLength = 0;
    ret.loadedSpritesLength = 0;
    ret.gameObjectsLength = 0;
    ret.spriteRenderersLength = 0;
    ret.collidersLength = 0;

    ret.isLoaded = false;

    // SCENE CONSTRUCTOR
    // check the name length
    if (strlen(name) >= ID_STRING_SIZE) {
        printf("Scene_From(): Tried using a name the exceed the max id size. Used name %s\n", name);
    } else {
        strcpy(ret.id, name);
    }
    
    return ret;
}

void Scene_Load(Scene* scene) {
    Scene_LoadTextures(scene);
    Scene_LoadSprites(scene);
}

void Scene_SetGameCamera(Scene* scene, Camera2D* cam) {
    if (cam == NULL) {
        printf("WARNING: Set scene game camera to NULL\n");
    }
    
    scene->currentCamera = cam;
}

void Scene_BeginCameraMode(Scene* scene) {
    if (scene->currentCamera == NULL) {
        printf("Cannot use camera mode if no camera is set\n");
        return;
    }
    BeginMode2D(*scene->currentCamera);
}

void Scene_EndCameraMode(Scene* scene) {
    EndMode2D();
}

bool Scene_HasSprite(Scene* scene, const char* spriteName) {
    for (int i = 0; i < scene->loadedSpritesLength; i++) {
        if (strcmp(spriteName, scene->loadedSprites[i].spriteName) == 0) {
            return true;
        }
    }

    return false;
}

Sprite* Scene_AddSprite(Scene* scene, const char* spriteName) {
    // check for bounds
    if (scene->loadedSpritesLength >= MAX_LOADED_SPRITES) {
        printf("Scene_AddLoadedSprite(): Can't add more sprite. Exceeding MAX_LOADED_SPRITES limit\n");
        return NULL;
    }

    Sprite* newSprite = scene->loadedSprites + scene->loadedSpritesLength;

    *newSprite = Sprite_From(spriteName);

    // increment length
    scene->loadedSpritesLength++;

    return newSprite;
}

void Scene_AddGameObject(Scene* scene, GameObject* go) {
    if (scene->gameObjectsLength >= MAX_GAME_OBJECTS_PER_SCENE) {
        printf("Scene_AddGameObject(): Tried to add more than %d GameObjects\n", MAX_GAME_OBJECTS_PER_SCENE);
    }

    scene->gameObjects[scene->gameObjectsLength] = go;
    scene->gameObjectsLength++;

    // add all components
    if (go->_componentSpriteRenderer != NULL) {
        Scene_AddSpriteRenderer(scene, go->_componentSpriteRenderer);
    }
    if (go->_componentCollider != NULL) {
        Scene_AddCollider(scene, go->_componentCollider);
    }

    // Run callback
    if (go->onSceneAttach != NULL) {
        go->onSceneAttach(go->parentData, scene);
    }
}
void Scene_AddCollider(Scene* scene, Collider* coll) {
    if (scene->collidersLength >= MAX_GAME_OBJECTS_PER_SCENE) {
        printf("Scene_AddCollider(): Tried add more than %d Colliders\n", MAX_GAME_OBJECTS_PER_SCENE);
        return;
    }

    scene->colliders[scene->collidersLength] = coll;
    scene->collidersLength++;
}

int Scene_GetOverlappingColliders(Scene* scene, Collider* coll, Collider** results, int resultsLength) {
    // check for zero length results length
    if (resultsLength == 0) {
        printf("Scene_GetOverlappingObjects(): Passed in results array of length 0\n");
        return 0;
    }
    int resultsIndex = 0;
    // iterate through the scenes colliders
    for (int i = 0; i < scene->collidersLength; i++) {
        Collider* currentColl = scene->colliders[i];
        // Dont test against self
        if (currentColl == coll) {
            continue;
        }

        // Check for overlap
        if (Collider_OverlappingWith(coll, currentColl)) {
            // assign result element
            results[resultsIndex] = currentColl;
            // increment index
            resultsIndex++;
            // Make sure we dont go over bounds of results
            if (resultsIndex >= resultsLength) {
                printf("Scene_GetOverlappingObjects(): Results array to small to contain all results\n");
                return resultsIndex;
            }
        }
    }

    return resultsIndex;
}

void Scene_AddSpriteRenderer(Scene* scene, SpriteRenderer* sr) {
    if (scene->spriteRenderersLength >= MAX_GAME_OBJECTS_PER_SCENE) {
        printf("Scene_AddSpriteRenderer(): Tried to add more than %d SpriteRenderers\n", MAX_GAME_OBJECTS_PER_SCENE);
        return;
    }

    scene->spriteRenderers[scene->spriteRenderersLength] = sr;
    scene->spriteRenderersLength++;

    // Check if sprite referenced is loaded
    if (!Scene_HasSprite(scene, sr->spriteName)) {
       // add load sprites 
       Sprite* newSprite = Scene_AddSprite(scene, sr->spriteName);
       // attach sprite reference to sprite renderer
       sr->sprite = newSprite;
    }
}

void Scene_LoadSprites(Scene* scene) {
    for (int i = 0; i < scene->loadedSpritesLength; i++) {
        Sprite* currentSprite = scene->loadedSprites + i;
        if (!Sprite_AreAllAnimationsLoaded(currentSprite)) {
            Sprite_LoadAnimations(currentSprite);
        }
    }
}

void Scene_UnloadSprites(Scene* scene) {
    for (int i = 0; i < scene->loadedSpritesLength; i++) {
        Sprite* currentSprite = scene->loadedSprites + i;
        if (Sprite_AreAllAnimationsLoaded(currentSprite)) {
            Sprite_UnloadAnimations(currentSprite);
        }
    }
}

Texture2D* Scene_AddTexture(Scene* scene, const char* filepath) {
    // Test for bounds
    if (scene->loadedTexturesLength == MAX_LOADED_TEXTURES) {
        printf("Scene_AddTexture(): Tried to add more than the max loaded textures of %d\n", MAX_LOADED_TEXTURES);
        return NULL;
    }

    // Add filepath to textures
    scene->texturesToLoad[scene->loadedTexturesLength] = filepath;    
    // save position
    int pos = scene->loadedTexturesLength;
    // increment length
    scene->loadedTexturesLength++;

    // return the equivalent pointer
    return scene->loadedTextures + pos;
}

void Scene_LoadTextures(Scene* scene) {
    for (int i = 0; i < scene->loadedTexturesLength; i++) {
        const char* filepathToLoad = scene->texturesToLoad[i];
        scene->loadedTextures[i] = LoadTexture(filepathToLoad);
    }
}

void Scene_UnloadTexture(Scene* scene) {
    for (int i = 0; i < scene->loadedTexturesLength; i++) {
        UnloadTexture(scene->loadedTextures[i]);
    }
}

void Scene_Update(Scene* scene) {
    // Camera prelude
    Scene_BeginCameraMode(scene);
    // iterate through the draw layers
    for (int i = 0; i < MAX_DRAW_LAYER; i++) {
        for (int j = 0; j < scene->gameObjectsLength; j++) {
            // QUALITY OF LIFE
            GameObject* go = scene->gameObjects[j];

            // Filter by draw layer
            if (go->drawLayer != i) {
                continue;
            }
            // dont update if not active
            if (!go->isActive) {
                continue;
            }
            // Main object update
            if (go->update != NULL) { // Watch for the case where the update doesnt exist.
                go->update(go->parentData, scene); 
            }

            // Update all components
            _Scene_DoAllComponentUpdates(scene, go);
        } 
    }

    // Run the user update
    if (scene->customUpdate != NULL) {
        scene->customUpdate(scene);
    }

    // Camera postlude
    Scene_EndCameraMode(scene);
}
