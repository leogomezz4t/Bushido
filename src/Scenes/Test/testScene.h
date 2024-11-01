#ifndef TEST_SCENE_H
#define TEST_SCENE_H

#include "rayleigh.h"
#include "gameState.h"
#include "scene.h"
#include "testMap.h"
#include "trackingCamera.h"
#include "parallaxBackground.h"

typedef struct {
    TestMap map;
    SamuraiRayleigh player;    
    TrackingCamera mainCamera;
    ParallaxBackground background;

    Scene* scene;
} TestScene;

TestScene TestScene_From(GameState* game);

void TestScene_Setup(TestScene* scene);
#endif
