#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H
#include "scene.h"

typedef struct {
    int windowWidth;
    int windowHeight;
    const char* gameName;

    // scenes
    Scene* currentScene;    

} GameState;

// --------
// Struct methods

// initiate game resources
void GameState_InitGame(GameState* state);

// Cleanup game
void GameState_CloseGame(GameState* state);

// The main game loop entry point function
void GameState_RunGame(GameState* state);

#endif
