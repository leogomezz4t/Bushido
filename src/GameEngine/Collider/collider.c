#include "collider.h"
#include "gameObject.h"
#include "stdio.h"
#include "hitbox.h"
#include <stdbool.h>

Collider Collider_From(GameObject* go) {
    Collider col;
    col.gameObject = go;

    // defaults
    col.hitboxesLength = 0;

    return col;
}

void Collider_AddHitbox(Collider* coll, float offsetX, float offsetY, int width, int height) {
    if (coll->hitboxesLength >= 10) {
        printf("Collider_AddHitbox(): Tried to add a hitbox exceeding the MAX_HITBOX\n");
        return;
    }

    coll->hitboxes[coll->hitboxesLength] = Hitbox_From(offsetX, offsetY, width, height);    
    // attach game object
    coll->hitboxes[coll->hitboxesLength].gameObject = coll->gameObject;
    coll->hitboxesLength++;
}


bool Collider_OverlappingWith(Collider* coll, Collider* target) {
    // iterate through our hitboxes
    for (int i = 0; i < coll->hitboxesLength; i++) {
        Hitbox* currentHitbox = coll->hitboxes + i;

        // iterate through the target hitboxes
        for (int j = 0; j < target->hitboxesLength; j++) {
            Hitbox* targetHitbox = target->hitboxes + j;

            if (Hitbox_OverlappingWith(currentHitbox, targetHitbox)) {
                return true;
            }
        }
    }

    return false;
}

/*
 * Sets whether or not debug outlines are drawn
 */
void Collider_SetDebug(Collider* coll, bool state) {
    // iterate through all hitboxes
    for (int i = 0; i < coll->hitboxesLength; i++) {
        Hitbox* current = coll->hitboxes + i;

        current->debug = state;
    }
}
