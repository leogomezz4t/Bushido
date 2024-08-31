#include <raylib.h>
#include <stdio.h>
#include "spriteAnimation.h"
#include "gameEngine.h"
#include "spriteRenderer.h"
#include "spriteAnimation.h"
#include "sprite.h"

int main(void) {
    GameState game;
    game.windowWidth = GetScreenWidth();
    game.windowHeight = GetScreenHeight();
    game.gameName = "Bushido";

    // test animation struct

    GameState_InitGame(&game);

    Sprite samurai_1 = Sprite_From("samurai_1");
    Sprite_LoadAnimations(&samurai_1);

    SpriteRenderer renderer = SpriteRenderer_From(500, 250);
    renderer.currentAnimation = samurai_1.spriteAnimations + 0;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);         
        DrawFPS(30, 30);
        
        SpriteRenderer_Animate(&renderer);

        if (IsKeyPressed(KEY_SPACE)) {
            renderer.currentAnimation++;
        }

        EndDrawing();
    }

    Sprite_UnloadAnimations(&samurai_1);
    GameState_CloseGame(&game);
}
