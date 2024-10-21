#include "gameObject.h"
#include "componentUpdates.h"
#include "hitbox.h"
#include "spriteRenderer.h"
#include "collider.h"
#include "scene.h"
#include <raylib.h>
#include <stdio.h>

void _Scene_DoAllComponentUpdates(Scene* scene, GameObject* go) {
    if (go->_componentSpriteRenderer != NULL) {
        _Scene_SpriteRendererUpdate(scene, go->_componentSpriteRenderer);
    }
    if (go->_componentCollider != NULL) {
        _Scene_ColliderUpdate(scene, go->_componentCollider);
    }
}

void _Scene_SpriteRendererUpdate(Scene* scene, SpriteRenderer* sr) {
    // Camera prelude
    SpriteRenderer_Animate(sr);
}

void _Scene_ColliderUpdate(Scene* scene, Collider* coll) {
    // iterate through hitboxes
    for (int i = 0; i < coll->hitboxesLength; i++) {
        if (coll->hitboxes[i].debug) {
            Vector2 hbPos = Hitbox_GetPosition(&(coll->hitboxes[i]));
            // draw hitbox
            DrawRectangleLines(
                    hbPos.x,
                    hbPos.y,
                    coll->hitboxes[i].width,
                    coll->hitboxes[i].height, 
                    GREEN
            );

            DrawCircle(hbPos.x, hbPos.y, 2, BLUE);
        }        
    }
}

