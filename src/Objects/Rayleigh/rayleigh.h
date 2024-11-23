#ifndef RAYLEIGH_H
#define RAYLEIGH_H

#include "gameObject.h"
#include "spriteRenderer.h"
#include "collider.h"
#include "scene.h"
#include "square.h"
#include <stdbool.h>

#define SAMURAI_IDLE 8
#define SAMURAI_DASH 5
#define SAMURAI_RUN 2

#define RAYLEIGH_TYPE "rayleigh"

typedef struct {
    // VALUES
    Vector2 centerOffset;
    bool noClip;

    bool dashing;
    float dashSpeed;
    // animation values
    bool blockingDefaultAnimation;
    // COLLECTIONS
    SquareObject* squares[50];
    int squaresLength;
    // COMPONENTS
    GameObject gameObject;
    SpriteRenderer spriteRenderer;
    Collider collider; 
} SamuraiRayleigh;

void SamuraiRayleigh_Init(SamuraiRayleigh* s, int x, int y);

void SamuraiRayleigh_AttachScene(SamuraiRayleigh* samurai, Scene* scene);

#endif
