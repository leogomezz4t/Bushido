#include "testScene.h"
#include "collider.h"
#include "gameState.h"
#include "rayleigh.h"
#include "scene.h"
#include "square.h"
#include "trackingCamera.h"
#include <raylib.h>

TestScene TestScene_From(GameState* game) {
    TestScene ret;
    ret.scene = GameState_CreateScene(game, "test");

    return ret;
}

void TestScene_Setup(TestScene* scene) {
    // qol
    SamuraiRayleigh* player = &scene->player;
    SquareObject* square = &scene->testSquare;
    TrackingCamera* mainCam = &scene->mainCamera;

    // init player
    SamuraiRayleigh_Init(player, 500, 250);
    SquareObject_Init(square, 200, 550, 100, 100);
    TrackingCamera_Init(mainCam, &player->gameObject);
    // Define values
    square->gameObject.drawLayer = 1;
    Collider_SetDebug(&player->collider, true);
    Collider_SetDebug(&square->collider, true);


    // Attach references
    square->samuraiReference = player;
    // attach it to scene
    SamuraiRayleigh_AttachScene(player, scene->scene);
    Scene_AddGameObject(scene->scene, &square->gameObject);

    Scene_AddGameObject(scene->scene, &mainCam->gameObject);
    Scene_SetGameCamera(scene->scene, &mainCam->camera);
}
