#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H
#include "scene.h"

#define MAX_SCENE 20

typedef struct {
    int windowWidth;
    int windowHeight;
    const char* gameName;

    // scenes
    int currentSceneIndex;    
    Scene* allScenes;
    int allScenesLength;
} GameState;

// --------
// Struct methods

GameState GameState_From(int windowWidth, int windowHeight, const char* gameName);

// initiate game resources
void GameState_InitGame(GameState* state);

// Cleanup game
void GameState_CloseGame(GameState* state);

// The main game loop entry point function
void GameState_RunGame(GameState* state);

Scene* GameState_CreateScene(GameState* state, const char * sceneName);

Scene* GameState_GetCurrentScene(GameState* state);

void GameState_SetCurrentScene(GameState* state, const char* sceneName);
#endif
