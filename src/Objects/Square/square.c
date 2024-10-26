#include "collider.h"
#include <stdio.h>
#include <string.h>
#include "gameObject.h"
#include <raylib.h>
#include <stdlib.h>
#include "hitbox.h"
#include "rayleigh.h"
#include "scene.h"
#include "square.h"

void draw(SquareObject* sq) {
    DrawRectangle(
            sq->gameObject.position.x,
            sq->gameObject.position.y,
            sq->width,
            sq->height,
            sq->color
    );
}

void squareUpdate(void* data, Scene* scene) {
    // QUALITY OF LIFE DECLARATIONS
    SquareObject* sq = (SquareObject*) data;
    Collider* coll = &sq->collider;
    // FUNCTION CALLS
    draw(sq);
    // UPDATE
}

void SquareObject_Init(SquareObject* sq, int x, int y, int width, int height) {
    // SQUARE OBJECT DEFAULT VALUES
    sq->color = BLACK;
    // SQUARE OBJECT INITIALIZATION
    sq->width = width;
    sq->height = height;
    // GAME OBJECT INITIALIZATION
    sq->gameObject = GameObject_From(x, y, (void*) sq);
    sq->gameObject.update = &squareUpdate;
    sq->gameObject.drawLayer = 1;
    GameObject_SetParentType(&sq->gameObject, SQUARE_TYPE);
    // COLLIDER INITIALIZATION
    sq->collider = Collider_From(&sq->gameObject);
    Collider_AddHitbox(&sq->collider,
            0,
            0,
            width,
            height
    );

    // ATTACH COMPONENTS
    sq->gameObject._componentCollider = &sq->collider;
}

