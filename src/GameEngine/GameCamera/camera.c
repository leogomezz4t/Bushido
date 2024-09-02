#include "camera.h"
#include "vector2.h"

GameCamera GameCamera_From(float worldX, float worldY, float scale) {
    GameCamera gc;
    
    gc.worldPosition = Vector2_From(worldX, worldY);

    gc.scale = scale;

    return gc;
}


float GameCamera_GetWidth(GameCamera* camera) {
    return GetScreenWidth() * camera->scale;
}

float GameCamera_GetHeight(GameCamera* camera) {
    return GetScreenHeight() * camera->scale;
}

Vector2 GameCamera_ToCameraCoordinates(GameCamera* camera, Vector2* position) {
    float cameraX = (position->x - (camera->worldPosition.x - GameCamera_GetWidth(camera)/2));
    float cameraY = (position->y - (camera->worldPosition.y - GameCamera_GetHeight(camera)/2));

    return Vector2_From(cameraX, cameraY);
}
