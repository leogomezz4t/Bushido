#ifndef COMPONENT_UPDATES_H
#define COMPONENT_UPDATES_H

#include "spriteRenderer.h"
#include "scene.h"

void _Scene_DoAllComponentUpdates(Scene* scene, GameObject* go);

void _Scene_SpriteRendererUpdate(Scene* scene, SpriteRenderer* sr);

void _Scene_ColliderUpdate(Scene* scene, Collider* coll);

#endif
