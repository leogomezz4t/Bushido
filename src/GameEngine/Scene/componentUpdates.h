#ifndef COMPONENT_UPDATES_H
#define COMPONENT_UPDATES_H

#include "spriteRenderer.h"

void _Scene_DoAllComponentUpdates(GameObject* go);

void _Scene_SpriteRendererUpdate(SpriteRenderer* sr);

void _Scene_ColliderUpdate(Collider* coll);

#endif
