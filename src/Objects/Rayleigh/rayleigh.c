#include "collider.h"
#include "gameObject.h"
#include "scene.h"
#include "spriteRenderer.h"
#include "square.h"
#include "vector2.h"
#include <stdlib.h>
#include <string.h>
#include <raylib.h>
#include <stdio.h>
#include "rayleigh.h"

void samuraiCleanup(void* data, Scene* scene) {
    // QUALITY OF LIFE
    SamuraiRayleigh* samurai = (SamuraiRayleigh*) data;

    // free all the squares
    for (int i = 0; i < samurai->squaresLength; i++) {
        SquareObject* curr = samurai->squares[i];
        free(curr);
    }
}

void samuraiDefaultAnimation(SamuraiRayleigh* samurai) {
    // QUALITY OF LIFE
    GameObject* go = &samurai->gameObject;
    SpriteRenderer* sr = &samurai->spriteRenderer;

    if (samurai->blockingDefaultAnimation) {
        return;
    }

    if (go->velocity.x == 0.0f) {
        sr->currentAnimationIndex = SAMURAI_IDLE;
    } else {
        sr->currentAnimationIndex = SAMURAI_RUN;
    }
}

void samuraiOrientationLogic(SamuraiRayleigh* samurai) {
    // QUALITY OF LIFE
    GameObject* go = &samurai->gameObject;
    SpriteRenderer* sr = &samurai->spriteRenderer;

    if (go->velocity.x > 0) {
        sr->orientation = ORIENTATION_RIGHT;
    } else if (go->velocity.x < 0) {
        sr->orientation = ORIENTATION_LEFT;
    }
}

void samuraiBasicMovementLogic(SamuraiRayleigh* samurai) {
    // QUALITY OF LIFE
    GameObject* go = &samurai->gameObject;

    // Reset x velocity
    go->velocity.x = 0;
    // Reset movement delta
    Vector2 moveDelta = { 0, 0 };

    // Apply gravity
    moveDelta.y += 4;

    int speed = 10;
    if (IsKeyDown(KEY_RIGHT)) {
        moveDelta.x += speed;
    }

    if (IsKeyDown(KEY_LEFT)) {
        moveDelta.x -= speed;
    }

    if (IsKeyDown(KEY_UP)) {
        moveDelta.y -= speed;
    }

    // Freeze x component if dashing
    if (samurai->dashing) {
        moveDelta.x = 0;
    }

    // apply movement delta
    go->velocity = Vector2_Add(go->velocity, moveDelta);

}

void samuraiCollisionLogic(SamuraiRayleigh* samurai, Scene* scene) {
    // QUALITY OF LIFE
    SpriteRenderer* sr = &samurai->spriteRenderer;
    Collider* coll = &samurai->collider;
    GameObject* go = &samurai->gameObject;

    // Check if no clipping
    if (samurai->noClip) {
        Vector2_Add(go->position, go->velocity);
    }

    Collider* overlappingColls[10];
    int overlapLength;
    // Collision check
    // X COMPONENT
    go->position.x += go->velocity.x;
    overlapLength = Scene_GetOverlappingColliders(scene, coll, overlappingColls, 10); 
    for (int i = 0; i < overlapLength; i++) {
        GameObject* curr = overlappingColls[i]->gameObject;
        if (GameObject_HasTag(curr, "wall")) {
            // collision has happened
            go->position.x -= go->velocity.x;
            // reset velocity
            go->velocity.x = 0;
            break;
        }
    }
    // Y COMPONENT
    go->position.y += go->velocity.y;
    overlapLength = Scene_GetOverlappingColliders(scene, coll, overlappingColls, 10);
    for (int i = 0; i < overlapLength; i++) {
        GameObject* curr = overlappingColls[i]->gameObject;
        if (GameObject_HasTag(curr, "wall")) {
            // collision has happneed
            go->position.y -= go->velocity.y;
            // reset velocity
            go->velocity.y = 0;
            break;
        }
    }

    char buff[1000];
    strcpy(buff, "Overlapping objects\n");
    for (int i = 0; i < overlapLength; i++) {
        GameObject* collidingObject = overlappingColls[i]->gameObject;
        char b[250];
        sprintf(b, "%d: GameObject | type: %s | tags: ", i+1, collidingObject->parentType);
        for (int j = 0; j < collidingObject->tagsLength; j++) {
            char c[50]; 
            sprintf(c, "%s ", collidingObject->tags[j]);
            strcat(b, c);
        }
        strcat(buff, b);
    }

    Scene_EndCameraMode(scene);
    DrawText(buff, 25, 600, 12, BLACK);
    Scene_BeginCameraMode(scene);

}

void samuraiDashLogic(SamuraiRayleigh* samurai) {
    // QUALITY OF LIFE 
    SpriteRenderer* sr = &samurai->spriteRenderer;
    GameObject* go = &samurai->gameObject;
    // dash
    if (samurai->dashing) {
        printf("Frame: %d\n", sr->currentFrame);
        if (SpriteRenderer_IsLastFrame(sr)) {
            // End animation
            samurai->blockingDefaultAnimation = false;
            samurai->dashing = false;
        }
        if (sr->currentFrame >= 1 && sr->currentFrame < 4){
            // apply dash
            go->velocity.x += samurai->dashSpeed * sr->orientation;
        }
    } else if (IsKeyDown(KEY_LEFT_SHIFT)) {
        sr->currentAnimationIndex = SAMURAI_DASH;
        SpriteRenderer_ResetFrameDelay(sr);
        sr->currentFrame = 0;
        samurai->dashing = true;
        samurai->blockingDefaultAnimation = true;
    }
}

void samuraiUpdate(void* data, Scene* scene) {
    SamuraiRayleigh* samurai = (SamuraiRayleigh*) data;
    SpriteRenderer* sr = &samurai->spriteRenderer;
    Collider* coll = &samurai->collider;
    GameObject* go = &samurai->gameObject;



    // BASIC MOVEMENT
    samuraiBasicMovementLogic(samurai);
    // DASH
    samuraiDashLogic(samurai);
    // ORIENTATION
    samuraiOrientationLogic(samurai);
    // ANIMATION
    samuraiDefaultAnimation(samurai);
    // COLLISION
    samuraiCollisionLogic(samurai, scene);

    // DRAW CENTER POINT
    Vector2 centerPos = Vector2_Add(go->position, samurai->centerOffset);
    DrawCircleV(centerPos, 3.0f, BLACK);


    // Tomfoolery
    if (IsKeyPressed(KEY_SPACE)) {
        // Add square at current location
        if (samurai->squaresLength < 50) {
            samurai->squares[samurai->squaresLength] = (SquareObject*) malloc(sizeof(SquareObject));
            SquareObject* curr = samurai->squares[samurai->squaresLength];
            // init square
            SquareObject_Init(curr, centerPos.x, centerPos.y, 100, 100);
            Collider_SetDebug(&curr->collider, true);
            // Add to scene
            Scene_AddGameObject(scene, &curr->gameObject);
            samurai->squaresLength++;
        }
    }

    if (IsKeyPressed(KEY_C)) {
        if (samurai->noClip) {
            samurai->noClip = false;
        } else {
            samurai->noClip = true;
        }
    }

    char cb[100];
    sprintf(cb, "No clip: %d", samurai->noClip);
    Scene_EndCameraMode(scene);
    DrawText(cb, 25, 300, 12, BLACK);
    Scene_BeginCameraMode(scene);
}

void SamuraiRayleigh_Init(SamuraiRayleigh* s, int x, int y) {
    // RAYLEIGH DEFAULT VALUES
    s->squaresLength = 0;
    s->centerOffset = (Vector2) {250, 425};
    s->noClip = false;
    s->dashing = false;
    s->dashSpeed = 20;
    s->blockingDefaultAnimation = false;
    // GAME OBJECT INITIALIZATION
    s->gameObject = GameObject_From(x, y, (void*) s);
    s->gameObject.update = &samuraiUpdate;
    s->gameObject.cleanup = &samuraiCleanup;
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
            160
    );
    // ATTACH COMPONENTS
    s->gameObject._componentSpriteRenderer = &s->spriteRenderer;
    s->gameObject._componentCollider = &s->collider;
}

void SamuraiRayleigh_AttachScene(SamuraiRayleigh* samurai, Scene* scene) {
    Scene_AddGameObject(scene, &samurai->gameObject);
}
