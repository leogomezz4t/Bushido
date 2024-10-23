#include "parallaxBackground.h"
#include "gameObject.h"
#include "scene.h"
#include <raylib.h>

#define BACK_FILEPATH "artwork/world/Background/3.png"
#define MID_FILEPATH "artwork/world/Background/2.png"
#define FORE_FILEPATH "artwork/world/Background/1.png"

void parallaxBackgroundScene(void* data, Scene* scene) {
    ParallaxBackground* bg = (ParallaxBackground*) data;

    bg->backLayerTexture = Scene_AddTexture(scene, BACK_FILEPATH);
    bg->midLayerTexture = Scene_AddTexture(scene, MID_FILEPATH);
    bg->foreLayerTexture = Scene_AddTexture(scene, FORE_FILEPATH);
}

void parallaxBackgroundUpdate(void* data, Scene* scene) {
    ParallaxBackground* bg = (ParallaxBackground*) data;
    
    // Draw all the copies
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < bg->numCopies; i++) {
            Vector2 baseInitialPos = {bg->initialPosition.x + (i * bg->backLayerTexture->width * bg->scale), bg->initialPosition.y};
            int baseDist = scene->currentCamera->target.x - baseInitialPos.x;
            // Draw each layer
            if (j == 0) {
                // BACK LAYER
                DrawTextureEx(*bg->backLayerTexture,
                        (Vector2) {baseInitialPos.x + baseDist * 0.2, baseInitialPos.y},
                        0.0f,
                        bg->scale,
                        WHITE);
            } else if (j == 1) {
                // MID LAYER
                DrawTextureEx(*bg->midLayerTexture,
                        (Vector2) {baseInitialPos.x + baseDist * 0.3, baseInitialPos.y},
                        0.0f,
                        bg->scale,
                        WHITE);
            }
            if (j == 2) {
                // FORE LAYER
                DrawTextureEx(*bg->foreLayerTexture,
                        (Vector2) {baseInitialPos.x + baseDist * 0.4, baseInitialPos.y},
                        0.0f,
                        bg->scale,
                        WHITE);
            }
        }
    }
}

void ParallaxBackground_Init(ParallaxBackground* bg, int x, int y) {
    // PARALLAX BACKGROUND DEFAULT VALUES
    bg->numCopies = 3;
    bg->offset = (Vector2) {0, 0};
    bg->scale = 6;
    // PARALLAX BACKGROUND INITIALIZATION
    bg->initialPosition = (Vector2) {x, y};

    // GAME OBJECT INITIALIZATION
    bg->gameObject = GameObject_From(x, y, (void*) bg);
    bg->gameObject.drawLayer = 0;
    bg->gameObject.update = parallaxBackgroundUpdate;
    bg->gameObject.onSceneAttach = parallaxBackgroundScene;
}
