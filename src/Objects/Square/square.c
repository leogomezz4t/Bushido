#include "collider.h"
#include <string.h>
#include "gameObject.h"
#include <raylib.h>
#include <stdlib.h>
#include "hitbox.h"
#include "rayleigh.h"
#include "scene.h"
#include "square.h"

void update(void* data) {
    SquareObject* sq = (SquareObject*) data;
    Collider* coll = &sq->collider;
    SamuraiRayleigh* samurai = sq->samuraiReference;

    bool overlapping = Hitbox_OverlappingWith(coll->hitboxes + 0, samurai->collider.hitboxes + 0);

    char buff[20];
    strcpy(buff, "Overlap: ");
    if (overlapping) {
        strcat(buff, "True\n");
    } else {
        strcat(buff, "False\n");
    }
    DrawText(buff, 25, 600, 12, BLACK);
}

void SquareObject_Init(SquareObject* sq, int x, int y, int width, int height) {
    // GAME OBJECT INITIALIZATION
    sq->gameObject = GameObject_From(x, y);
    sq->gameObject.update = &update;
    sq->gameObject.parentData = (void*) sq;

    // COLLIDER INITIALIZATION
    sq->collider = Collider_From(&sq->gameObject);
    Collider_AddHitbox(&sq->collider,
            0,
            0,
            width,
            height
    );
    sq->collider.hitboxes[0].debug = true;

    // ATTACH COMPONENTS
    sq->gameObject._componentCollider = &sq->collider;
}

