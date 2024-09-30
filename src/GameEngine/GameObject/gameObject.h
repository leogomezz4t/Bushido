#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H


#include <stdbool.h>
#include "vector2.h"

// forward declarations
struct sprite_renderer_t;
typedef struct sprite_renderer_t SpriteRenderer;

struct entity_t;
typedef struct entity_t Entity;

struct collider_t;
typedef struct collider_t Collider;

typedef struct GameObject {
    Vector2 position;
    // movement
    Vector2 velocity;
    // Parent struct
    void* parentData; 
    // behaviour
    void (*update)(void*);
    bool isActive;

    // All components
    SpriteRenderer* _componentSpriteRenderer; 
    Entity* _componentEntity;
    Collider* _componentCollider;
} GameObject;

GameObject GameObject_From(int x, int y);

#endif
