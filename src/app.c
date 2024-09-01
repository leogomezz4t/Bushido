#include <raylib.h>
#include <stdio.h>
#include "gameObject.h"
#include "scene.h"
#include "spriteAnimation.h"
#include "gameEngine.h"
#include "spriteRenderer.h"
#include "sprite.h"
#include "vector2.h"

typedef struct {
    GameObject gameObject;
    SpriteRenderer spriteRenderer;
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
    } else {
        if (go->velocity.x > 0) {
            go->velocity.x -= 0.25;
        } else {
            go->velocity.x += 0.25;
        }
    }

    go->position = Vector2_Add(go->position, go->velocity);
}

int main(void) {
    GameState game;
    game.windowWidth = GetScreenWidth();
    game.windowHeight = GetScreenHeight();
    game.gameName = "Bushido";

    Scene main = Scene_From(1);

    Sprite samuraiSprite = Sprite_From("samurai_1");

    Samurai_1 s;
    s.gameObject = GameObject_From(500, 250);
    s.gameObject.parentData = (void*) &s;
    s.gameObject.update = &samuraiUpdate;
    
    s.spriteRenderer = SpriteRenderer_From("samurai_1", &s.gameObject);
    s.spriteRenderer.scale = 5;
    s.spriteRenderer.currentAnimation = samuraiSprite.spriteAnimations + 2;

    Scene_AddGameObject(&main, &s.gameObject);

    GameState_InitGame(&game);
    Sprite_LoadAnimations(&samuraiSprite);

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
