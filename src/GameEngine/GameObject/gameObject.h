#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H


#include <stdbool.h>
#include "vector2.h"

// CONSTANTS
#define MAX_DRAW_LAYER 6

#define MAX_TAG_LENGTH 10
#define MAX_TAGS 5

#define MAX_PARENT_TYPE_LENGTH 25

// forward declarations
struct scene_t;
typedef struct scene_t Scene;

struct sprite_renderer_t;
typedef struct sprite_renderer_t SpriteRenderer;

struct entity_t;
typedef struct entity_t Entity;

struct collider_t;
typedef struct collider_t Collider;

struct hitbox_t;
typedef struct hitbox_t Hitbox;

typedef struct GameObject {
    Vector2 position;
    // movement
    Vector2 velocity;
    // Parent struct
    void* parentData; 
    // Behaviour
    bool isActive;
    int drawLayer;
    // organizational data
    char tags[MAX_TAG_LENGTH+1][MAX_TAGS];
    int tagsLength;

    char parentType[MAX_PARENT_TYPE_LENGTH+1];
    // CALLBACK FUNCTIONS
    void (*update)(void*, Scene*);
    void (*onSceneAttach)(void*, Scene*);
    void (*cleanup)(void*, Scene*);

    // COMPONENTS
    SpriteRenderer* _componentSpriteRenderer; 
    Entity* _componentEntity;
    Collider* _componentCollider;
} GameObject;

GameObject GameObject_From(int x, int y, void* parentData);

void GameObject_AddTag(GameObject* go, const char* tag);

bool GameObject_HasTag(GameObject* go, const char* tag);

void GameObject_SetParentType(GameObject* go, const char* type);
#endif
