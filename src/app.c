#include <raylib.h>
#include <stdio.h>
#include "gameObject.h"
#include "orientation.h"
#include "scene.h"
#include "gameEngine.h"
#include "spriteRenderer.h"
#include "vector2.h"

#define SAMURAI_IDLE 8
#define SAMURAI_RUN 2

typedef struct {
    GameObject gameObject;
    SpriteRenderer spriteRenderer;
    int x;
} Samurai_1;


void samuraiUpdate(void* data) {
    Samurai_1* samurai = (Samurai_1*) data;
    SpriteRenderer* sr = &samurai->spriteRenderer;
    GameObject* go = &samurai->gameObject;

    // movement
    if (IsKeyDown(KEY_RIGHT)) {
        go->velocity.x += 0.5;
    } else if (IsKeyDown(KEY_LEFT)) {
        go->velocity.x -= 0.5;
    }

    if (go->velocity.x > 0) {
        go->velocity.x -= 0.25;
    } else if (go->velocity.x < 0) {
        go->velocity.x += 0.25;
    }
    
    if (go->velocity.x > 0) {
        sr->orientation = ORIENTATION_RIGHT;
    } else if (go->velocity.x < 0) {
        sr->orientation = ORIENTATION_LEFT;
    }

    if (go->velocity.x == 0.0f) {
        sr->currentAnimationIndex = SAMURAI_IDLE;
    } else {
        sr->currentAnimationIndex = SAMURAI_RUN;
    }

    if (IsKeyPressed(KEY_UP)) {
        samurai->x++;
    }
    if (IsKeyPressed(KEY_DOWN)) {
        samurai->x--;
    }

    char buff[100];
    sprintf(buff, "Velocity: %f", go->velocity.x);
    DrawText(buff, 20, 100, 18, BLACK);

    go->position = Vector2_Add(go->position, go->velocity);
        
    // display the animation
    SpriteRenderer_Animate(sr);
}

void Samurai_1_Init(Samurai_1* s, int x, int y) {
    s->x = 0;

    s->gameObject = GameObject_From(x, y);
    s->gameObject.update = &samuraiUpdate;
    s->gameObject.parentData = (void*) s;
    
    s->spriteRenderer = SpriteRenderer_From("samurai_1", &s->gameObject);
    s->spriteRenderer.scale = 5.0f;
}

int main() {
    GameState game = GameState_From(
            GetScreenWidth(),
            GetScreenHeight(),
            "Bushido"
    );

    Scene* main = GameState_CreateScene(&game, "main");
    GameState_SetCurrentScene(&game, "main");

    Samurai_1 s;
    Samurai_1_Init(&s, 500, 250);

    Scene_AddGameObject(main, &s.gameObject);
    Scene_AddSpriteRenderer(main, &s.spriteRenderer);

    GameState_InitGame(&game);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);         
        DrawFPS(30, 30);

        GameState_RunGame(&game);

        EndDrawing();
    }

    GameState_CloseGame(&game);
}
