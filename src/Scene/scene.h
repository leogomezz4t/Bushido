#ifndef SCENE_H
#define SCENE_H

#include "gameObject.h"

#define MAX_GAME_OBJECTS_PER_SCENE 200
#define MAX_LAYER 5

typedef struct {
    int id;


    // collections
    GameObject gameObjects[MAX_GAME_OBJECTS_PER_SCENE];
    int gameObjectsLength;
} Scene;
#endif
