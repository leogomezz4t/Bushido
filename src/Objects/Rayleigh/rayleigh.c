#include "collider.h"
#include "gameObject.h"
#include "scene.h"
#include "spriteRenderer.h"
#include "square.h"
#include "vector2.h"
#include <stdlib.h>
#include <raylib.h>
#include <string.h>
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

void samuraiUpdate(void* data, Scene* scene) {
    SamuraiRayleigh* samurai = (SamuraiRayleigh*) data;
    SpriteRenderer* sr = &samurai->spriteRenderer;
    Collider* coll = &samurai->collider;
    GameObject* go = &samurai->gameObject;

    // movement
    // reset
    go->velocity = (Vector2) {0, 0};
    int speed = 10;
    if (IsKeyDown(KEY_RIGHT)) {
        go->velocity.x += speed;
    }

    if (IsKeyDown(KEY_LEFT)) {
        go->velocity.x -= speed;
    }

    if (IsKeyDown(KEY_UP)) {
        go->velocity.y -= speed;
    }

    if (IsKeyDown(KEY_DOWN)) {
        go->velocity.y += speed;
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

    // DRAW CENTER POINT
    Vector2 centerPos = Vector2_Add(go->position, samurai->centerOffset);
    DrawCircleV(centerPos, 3.0f, BLACK);

    Collider* overlappingColls[10];
    int overlapLength;

    // Collision check
    // X COMPONENT
    if (!samurai->noClip) {
        go->position.x += go->velocity.x;
        overlapLength = Scene_GetOverlappingColliders(scene, coll, overlappingColls, 10); 
        for (int i = 0; i < overlapLength; i++) {
            GameObject* curr = overlappingColls[i]->gameObject;
            if (GameObject_HasTag(curr, "wall")) {
                // collision has happened
                go->position.x -= go->velocity.x;
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
                break;
            }
        }
    } else {
        go->position = Vector2_Add(go->position, go->velocity);
    }
    /*
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
    */


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
            175
    );
    // ATTACH COMPONENTS
    s->gameObject._componentSpriteRenderer = &s->spriteRenderer;
    s->gameObject._componentCollider = &s->collider;
}

void SamuraiRayleigh_AttachScene(SamuraiRayleigh* samurai, Scene* scene) {
    Scene_AddGameObject(scene, &samurai->gameObject);
}
