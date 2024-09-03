#include "testScene.h"
#include "gameState.h"
#include "rayleigh.h"

TestScene TestScene_From(GameState* game) {
    TestScene ret;
    ret.scene = GameState_CreateScene(game, "test");

    return ret;
}

void TestScene_Setup(TestScene* scene) {
    // qol
    SamuraiRayleigh* player = &scene->player;
    // init player
    SamuraiRayleigh_Init(player, 500, 250);
    // attach it to scene
    SamuraiRayleigh_AttachScene(player, scene->scene);
}
