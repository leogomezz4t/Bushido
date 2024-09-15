#include "gameObject.h"
#include "stdlib.h"

GameObject GameObject_From(int x, int y) {
    // initialize the default object
    GameObject go;

    // set the position
    go.position = Vector2_From(x, y);
    // init velocity
    go.velocity = Vector2_From(0, 0);

    // default values
    go.isActive = true;
    go.parentData = NULL;
    go.update = NULL;

    // default component values
    go._componentSpriteRenderer = NULL;

    return go;
}

