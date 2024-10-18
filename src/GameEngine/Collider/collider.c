#include "collider.h"
#include "stdio.h"
#include "hitbox.h"

Collider Collider_From(GameObject* go) {
    Collider col;
    col.gameObject = go;

    // defaults
    col.hitboxesLength = 0;

    return col;
}

void Collider_AddHitbox(Collider* col, float offsetX, float offsetY, int width, int height) {
    if (col->hitboxesLength >= 10) {
        printf("Collider_AddHitbox(): Tried to add a hitbox exceeding the MAX_HITBOX\n");
        return;
    }

    col->hitboxes[col->hitboxesLength] = Hitbox_From(offsetX, offsetY, width, height);    
    // attach game object
    col->hitboxes[col->hitboxesLength].gameObject = col->gameObject;
    col->hitboxesLength++;
}
