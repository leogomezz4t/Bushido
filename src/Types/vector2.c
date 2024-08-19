#include "vector2.h"
#include <stdlib.h>
#include <math.h>

Vector2 Vector2From(int x, int y) {
    return (Vector2) { x, y };
}

double Vector2Dist(Vector2 a, Vector2 b) {
    double xLen = fabs(a.x - b.x);
    double yLen = fabs(a.y - b.y);

    double xSquare = xLen * xLen;
    double ySquare = yLen * yLen;

    return sqrt(xSquare + ySquare);
}
