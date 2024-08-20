#include <raylib.h>
#include "gameEngine.h"

int main(void) {
    GameState game;
    game.windowWidth = GetScreenWidth();
    game.windowHeight = GetScreenHeight();
    game.gameName = "Bushido";

    GameState_InitGame(&game);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE); 
        EndDrawing();
    }
    
    GameState_CloseGame(&game);
}
