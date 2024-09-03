#include "gameObject.h"
#include "scene.h"
#include "spriteRenderer.h"
#include <stdio.h>
#include "rayleigh.h"

void samuraiUpdate(void* data) {
    SamuraiRayleigh* samurai = (SamuraiRayleigh*) data;
    SpriteRenderer* sr = &samurai->spriteRenderer;
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

    char buff[100];
    sprintf(buff, "Velocity: %f", go->velocity.x);
    DrawText(buff, 20, 100, 18, BLACK);

    go->position = Vector2_Add(go->position, go->velocity);
        
    // display the animation
    SpriteRenderer_Animate(sr);
}

void SamuraiRayleigh_Init(SamuraiRayleigh* s, int x, int y) {
    s->gameObject = GameObject_From(x, y);
    s->gameObject.update = &samuraiUpdate;
    s->gameObject.parentData = (void*) s;
    
    s->spriteRenderer = SpriteRenderer_From("samurai_1", &s->gameObject);
    s->spriteRenderer.scale = 5.0f;
}

void SamuraiRayleigh_AttachScene(SamuraiRayleigh* samurai, Scene* scene) {
    Scene_AddGameObject(scene, &samurai->gameObject);
    Scene_AddSpriteRenderer(scene, &samurai->spriteRenderer);
}
