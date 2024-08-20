#include "gameEngine.h"
#include "raylib.h"

void GameState_InitGame(GameState* state) {
    InitWindow(state->windowWidth, state->windowHeight, state->gameName);    

    // Toggle fullscreen
    SetWindowState(FLAG_FULLSCREEN_MODE);
}

void GameState_CloseGame(GameState* state) {
    CloseWindow();
}
