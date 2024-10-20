#include "testScene.h"
#include "gameState.h"
#include "rayleigh.h"
#include "scene.h"
#include "square.h"

TestScene TestScene_From(GameState* game) {
    TestScene ret;
    ret.scene = GameState_CreateScene(game, "test");

    return ret;
}

void TestScene_Setup(TestScene* scene) {
    // qol
    SamuraiRayleigh* player = &scene->player;
    SquareObject* square = &scene->testSquare;

    // init player
    SamuraiRayleigh_Init(player, 500, 250);
    SquareObject_Init(square, 200, 550, 100, 100);
    // Define values
    square->gameObject.drawLayer = 1;

    // Attach references
    square->samuraiReference = player;
    // attach it to scene
    SamuraiRayleigh_AttachScene(player, scene->scene);
    Scene_AddGameObject(scene->scene, &square->gameObject);
}
