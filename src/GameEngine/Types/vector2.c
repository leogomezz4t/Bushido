#include "vector2.h"
#include <math.h>

Vector2 Vector2_From(float x, float y) {
    return (Vector2) { x, y };
}

double Vector2_Dist(Vector2 a, Vector2 b) {
    double xLen = fabs(a.x - b.x);
    double yLen = fabs(a.y - b.y);

    double xSquare = xLen * xLen;
    double ySquare = yLen * yLen;

    return sqrt(xSquare + ySquare);
}

Vector2 Vector2_Add(Vector2 a, Vector2 b) {
    Vector2 c;
    c.x = a.x + b.x;
    c.y = a.y + b.y;

    return c;
}
