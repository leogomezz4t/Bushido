#ifndef SQUARE_H
#define SQUARE_H

#include "gameObject.h"
#include "collider.h"
#include "rayleigh.h"

typedef struct {
    GameObject gameObject;
    Collider collider;

    // references
    SamuraiRayleigh* samuraiReference;
} SquareObject;

void SquareObject_Init(SquareObject* sq, int x, int y, int width, int height);

#endif

