#include "gameObject.h"
#include "vectors.h"

GameObject GameObjectFrom(int x, int y, int width, int height) {
    // initialize the default object
    GameObject go;

    // set the position
    go.position = Vector2From(x, y);

    // set the transform
    go.width = width;
    go.height = height;

    return go;
}
