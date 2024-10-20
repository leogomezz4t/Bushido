#ifndef SQUARE_H
#define SQUARE_H

#include "gameObject.h"
#include "collider.h"
#include "rayleigh.h"
#include <raylib.h>

typedef struct {
    // VALUES
    int width;
    int height;

    Color color;
    // COMPONENTS
    GameObject gameObject;
    Collider collider;

    // REFERENCES
    SamuraiRayleigh* samuraiReference;
} SquareObject;

void SquareObject_Init(SquareObject* sq, int x, int y, int width, int height);

#endif

