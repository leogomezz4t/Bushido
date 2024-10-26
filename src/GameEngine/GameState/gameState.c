#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "gameState.h"
#include "raylib.h"
#include "scene.h"

#define NULL_SCENE_INDEX -1

GameState GameState_From(int windowWidth, int windowHeight, const char* gameName) {
    GameState ret;
    ret.windowWidth = windowWidth;
    ret.windowHeight = windowHeight;
    ret.gameName = gameName;

    ret.allScenes = (Scene*) malloc(sizeof(Scene) * MAX_SCENES);
    ret.currentSceneIndex = NULL_SCENE_INDEX;
    ret.allScenesLength = 0;

    return ret;
}

// initiate game resources
void GameState_InitGame(GameState* state) {
    // Load game resources    
    InitWindow(state->windowWidth, state->windowHeight, state->gameName);    
    // Toggle fullscreen
    SetWindowState(FLAG_FULLSCREEN_MODE);
    // FPS
    SetTargetFPS(60);

    // Load resources with OpenGL context
    Scene_Load(
            GameState_GetCurrentScene(state)
    );
}

Scene* GameState_GetCurrentScene(GameState* state) {
    if (state->currentSceneIndex == NULL_SCENE_INDEX) {
        return NULL;
    }

    return state->allScenes + state->currentSceneIndex;
}

Scene* GameState_CreateScene(GameState* state, const char * sceneName) {
    if (state->allScenesLength >= MAX_SCENES) {
        printf("GameState_CreateScene(): Tried to create scene and exceeded MAX_SCENES\n");
    }

    state->allScenes[state->allScenesLength] = Scene_From(sceneName);

    // increment length
    state->allScenesLength++;

    //return reference
    
    return state->allScenes + (state->allScenesLength-1);
}

void GameState_SetCurrentScene(GameState* state, const char* sceneName) {
    // check the length
    if (strlen(sceneName) >= ID_STRING_SIZE) {
        printf("GameState_SetCurrentScene(): Scene name provided is longer than the max id size\n");
        return;
    }

    for (int i = 0; i < state->allScenesLength; i++) {
        Scene* iterScene = state->allScenes + i;
        if (strcmp(iterScene->id, sceneName) == 0) {
            // set the current scene
            state->currentSceneIndex = i;
            return;
        }
    }

    printf("GameState_SetCurrentScene(): Failed to switch to scene with id: %s\n", sceneName);
}

// Cleanup game
void GameState_CloseGame(GameState* state) {
    // Clean up resources
    Scene* currentScene = GameState_GetCurrentScene(state);
    Scene_Unload(currentScene);

    // Free scenes array
    free(state->allScenes);
    CloseWindow();
}

// The main game loop entry point function
void GameState_RunGame(GameState* state) {
    // Raylib boilerplate
    BeginDrawing();
    ClearBackground(RAYWHITE);         
    // qol
    Scene* currentScene = GameState_GetCurrentScene(state);
    // update the current scene
    Scene_Update(currentScene);

    DrawFPS(30, 30);

    // raylib boilerplate
    EndDrawing();
}

// Render and update the current scene
void GameState_DrawCurrentScene(GameState* state) {
    
}
