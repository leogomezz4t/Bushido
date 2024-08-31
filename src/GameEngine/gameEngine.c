#include "gameEngine.h"
#include "raylib.h"

// initiate game resources
void GameState_InitGame(GameState* state) {
    // Load game resources
    
    
    InitWindow(state->windowWidth, state->windowHeight, state->gameName);    

    // Toggle fullscreen
    SetWindowState(FLAG_FULLSCREEN_MODE);

    // FPS
    SetTargetFPS(60);
}

// Cleanup game
void GameState_CloseGame(GameState* state) {
    CloseWindow();
}

// The main game loop entry point function
void GameState_RunGame(GameState* state) {

}

// Render and update the current scene
void GameState_DrawCurrentScene(GameState* state) {

}
