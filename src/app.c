#include <raylib.h>
#include <stdio.h>
#include "scene.h"
#include "testScene.h"
#include "gameState.h"

int main() {
    GameState game = GameState_From(
            GetScreenWidth(),
            GetScreenHeight(),
            "Bushido"
    );

    TestScene test = TestScene_From(&game);
    TestScene_Setup(&test);

    GameState_SetCurrentScene(&game, "test");

    GameState_InitGame(&game);

    while (!WindowShouldClose()) {
        GameState_RunGame(&game);
    }

    GameState_CloseGame(&game);
}
