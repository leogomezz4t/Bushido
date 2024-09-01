#include <raylib.h>
#include <stdio.h>
#include "gameObject.h"
#include "orientation.h"
#include "scene.h"
#include "spriteAnimation.h"
#include "gameEngine.h"
#include "spriteRenderer.h"
#include "sprite.h"
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
        
    // display the animation
    SpriteRenderer_Animate(sr);

    // movement
    if (IsKeyDown(KEY_RIGHT)) {
        go->velocity.x += 1;
    } else if (IsKeyDown(KEY_LEFT)) {
        go->velocity.x -= 1;
    }

    if (go->velocity.x > 0) {
        go->velocity.x -= 0.25;
    } else {
        go->velocity.x += 0.25;
    }
    
    if (go->velocity.x > 0) {
        sr->orientation = ORIENTATION_RIGHT;
    } else if (go->velocity.x < 0) {
        sr->orientation = ORIENTATION_LEFT;
    }

    printf("Velocity: %f\n", go->velocity.x);
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
    sprintf(buff, "Index: %d", samurai->x);
    DrawText(buff, 20, 100, 18, BLACK);

    go->position = Vector2_Add(go->position, go->velocity);
}

Samurai_1 Samurai_1_From(int x, int y, Sprite* spriteRef) {
    Samurai_1 s;
    s.x = 0;

    s.gameObject = GameObject_From(x, y);
    s.gameObject.update = &samuraiUpdate;
    
    s.spriteRenderer = SpriteRenderer_From("samurai_1", &s.gameObject);
    s.spriteRenderer.scale = 5.0f;
    s.spriteRenderer.sprite = spriteRef;

    return s;
}

int main(void) {
    GameState game;
    game.windowWidth = GetScreenWidth();
    game.windowHeight = GetScreenHeight();
    game.gameName = "Bushido";

    Scene main = Scene_From(1);

    Sprite samuraiSprite = Sprite_From("samurai_1");

    Samurai_1 s = Samurai_1_From(500, 250, &samuraiSprite);
    s.gameObject.parentData = (void*) &s;
    s.spriteRenderer.gameObject = &s.gameObject;
    Scene_AddGameObject(&main, &s.gameObject);

    GameState_InitGame(&game);
    Sprite_LoadAnimations(&samuraiSprite);

    printf("Animation length: %d\n", samuraiSprite.spriteAnimationsLength);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);         
        DrawFPS(30, 30);

        Scene_Update(&main);

        EndDrawing();
    }

    Sprite_UnloadAnimations(&samuraiSprite);
    GameState_CloseGame(&game);
}
