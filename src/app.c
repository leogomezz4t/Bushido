#include <raylib.h>

int main(void) {
    InitWindow(GetScreenWidth(), GetScreenHeight(), "Bushido");

    // Game should be fullscreen
    SetWindowState(FLAG_FULLSCREEN_MODE);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE); 
        EndDrawing();
    }

    CloseWindow();
}
