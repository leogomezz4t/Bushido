#ifndef SQUARE_H
#define SQUARE_H

#include "gameObject.h"
#include "collider.h"
#include <raylib.h>

#define SQUARE_TYPE "square_object"

typedef struct {
    // VALUES
    int width;
    int height;

    Color color;
    // COMPONENTS
    GameObject gameObject;
    Collider collider;
} SquareObject;

void SquareObject_Init(SquareObject* sq, int x, int y, int width, int height);

#endif

