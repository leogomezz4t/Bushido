#ifndef RAYLEIGH_H
#define RAYLEIGH_H

#include "gameObject.h"
#include "spriteRenderer.h"
#include "collider.h"
#include "scene.h"
#include "square.h"

#define SAMURAI_IDLE 8
#define SAMURAI_RUN 2

#define RAYLEIGH_TYPE "rayleigh"

typedef struct {
    // VALUES
    Vector2 centerOffset;
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
