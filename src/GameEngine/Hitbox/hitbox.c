#include "hitbox.h"
#include "vector2.h"

Hitbox Hitbox_From(float xOffset, float yOffset, int width, int height) {
    Hitbox ret;
    ret.offset = Vector2_From(xOffset, yOffset);
    ret.width = width;
    ret.height = height;

    return ret;
}

Vector2 Hitbox_GetPosition(Hitbox* hb) {
    return Vector2_Add(hb->offset, hb->gameObject->position);
}
