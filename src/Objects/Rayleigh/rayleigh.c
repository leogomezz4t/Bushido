#include "collider.h"
#include "gameObject.h"
#include "scene.h"
#include "spriteRenderer.h"
#include <raylib.h>
#include <string.h>
#include <stdio.h>
#include "rayleigh.h"

void samuraiUpdate(void* data, Scene* scene) {
    SamuraiRayleigh* samurai = (SamuraiRayleigh*) data;
    SpriteRenderer* sr = &samurai->spriteRenderer;
    Collider* coll = &samurai->collider;
    GameObject* go = &samurai->gameObject;

    // movement
    if (IsKeyDown(KEY_RIGHT)) {
        go->velocity.x += 0.5;
    } else if (IsKeyDown(KEY_LEFT)) {
        go->velocity.x -= 0.5;
    }

    if (go->velocity.x > 0) {
        go->velocity.x -= 0.25;
    } else if (go->velocity.x < 0) {
        go->velocity.x += 0.25;
    }
    
    if (go->velocity.x > 0) {
        sr->orientation = ORIENTATION_RIGHT;
    } else if (go->velocity.x < 0) {
        sr->orientation = ORIENTATION_LEFT;
    }

    if (go->velocity.x == 0.0f) {
        sr->currentAnimationIndex = SAMURAI_IDLE;
    } else {
        sr->currentAnimationIndex = SAMURAI_RUN;
    }

    Collider* overlappingColls[10];
    int overlapLength = Scene_GetOverlappingColliders(scene, coll, overlappingColls, 10);
    

    char buff[200];
    strcpy(buff, "Overlapping objects\n");
    for (int i = 0; i < overlapLength; i++) {
        GameObject* collidingObject = overlappingColls[i]->gameObject;
        char b[50];
        sprintf(b, "%d: GameObject | type: %s\n", i+1, collidingObject->parentType);
        strcat(buff, b);
    }

    Scene_EndCameraMode(scene);
    DrawText(buff, 25, 600, 12, BLACK);
    Scene_BeginCameraMode(scene);

    // Tomfoolery
    if (IsKeyPressed(KEY_SPACE)) {

    }

    go->position = Vector2_Add(go->position, go->velocity);
}

void SamuraiRayleigh_Init(SamuraiRayleigh* s, int x, int y) {
    // GAME OBJECT INITIALIZATION
    s->gameObject = GameObject_From(x, y, (void*) s);
    s->gameObject.update = &samuraiUpdate;
    GameObject_SetParentType(&s->gameObject, RAYLEIGH_TYPE);
    // SPRITE RENDERER INITIALIZATION
    s->spriteRenderer = SpriteRenderer_From("samurai_1", &s->gameObject);
    s->spriteRenderer.scale = 5.0f;
    // COLLIDER INITIALIZATION
    s->collider = Collider_From(&s->gameObject);
    Collider_AddHitbox(&s->collider,
            190,
            370,
            100,
            175
    );
    // ATTACH COMPONENTS
    s->gameObject._componentSpriteRenderer = &s->spriteRenderer;
    s->gameObject._componentCollider = &s->collider;
}

void SamuraiRayleigh_AttachScene(SamuraiRayleigh* samurai, Scene* scene) {
    Scene_AddGameObject(scene, &samurai->gameObject);
}
