#include "hitbox.h"
#include "vector2.h"
#include <stdbool.h>

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

bool Hitbox_OverlappingWith(Hitbox* hb, Hitbox* target) {
    Vector2 hbPos = Hitbox_GetPosition(hb);
    Vector2 targetPos = Hitbox_GetPosition(target);
    
    return (
            (hbPos.x < targetPos.x + target->width) &&
            (hbPos.x + hb->width > targetPos.x) &&
            (hbPos.y < targetPos.y + target->height) &&
            (hbPos.y + hb->height > targetPos.y)
            );
}
