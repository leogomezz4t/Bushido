#ifndef SCENE_H
#define SCENE_H

#include "vector2.h"

typedef struct {
    Vector2 worldPosition;
    float scale;
} GameCamera;

GameCamera GameCamera_From(float worldX, float worldY, float scale);

float GameCamera_GetWidth(GameCamera* camera);

float GameCamera_GetHeight(GameCamera* camera);

Vector2 GameCamera_ToCameraCoordinates(GameCamera* camera, Vector2* position);

#endif
