#include "gameObject.h"
#include "stdlib.h"

GameObject GameObject_From(int x, int y, void* parentData) {
    // INITIALIZE OBJECT
    GameObject go;
    // DEFAULT COMPONENTS
    go._componentSpriteRenderer = NULL;
    go._componentEntity = NULL;
    go._componentCollider = NULL;
    // DEFAULT VALUES
    go.isActive = true;
    go.parentData = parentData;
    go.update = NULL;
    go.velocity = Vector2_From(0, 0);
    go.drawLayer = MAX_DRAW_LAYER - 1;
    // CONSTRUCTOR VALUES
    go.position = Vector2_From(x, y);

    return go;
}

