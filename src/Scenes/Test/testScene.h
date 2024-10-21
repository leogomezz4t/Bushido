#ifndef TEST_SCENE_H
#define TEST_SCENE_H

#include "rayleigh.h"
#include "gameState.h"
#include "scene.h"
#include "square.h"
#include "trackingCamera.h"

typedef struct {
    SamuraiRayleigh player;    
    SquareObject testSquare;
    TrackingCamera mainCamera;

    Scene* scene;
} TestScene;

TestScene TestScene_From(GameState* game);

void TestScene_Setup(TestScene* scene);
#endif
