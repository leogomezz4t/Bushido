#include "gameObject.h"
#include "stdlib.h"

GameObject GameObject_From(int x, int y) {
    // initialize the default object
    GameObject go;

    // set the position
    go.position = Vector2_From(x, y);

    go.isActive = true;

    go.parentData = NULL;

    // init velocity
    go.velocity = Vector2_From(0, 0);

    go.update = NULL;

    return go;
}

