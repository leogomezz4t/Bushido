#include "gameObject.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

GameObject GameObject_From(int x, int y, void* parentData) {
    // INITIALIZE OBJECT
    GameObject go;
    // DEFAULT COMPONENTS
    go._componentSpriteRenderer = NULL;
    go._componentEntity = NULL;
    go._componentCollider = NULL;
    // DEFAULT VALUES
    go.isActive = true;
    go.parentData = parentData;

    go.update = NULL;
    go.onSceneAttach = NULL;
    go.cleanup = NULL;

    go.velocity = Vector2_From(0, 0);
    go.drawLayer = MAX_DRAW_LAYER - 1;
    go.tagsLength = 0;
    go.parentType[0] = '\0';
    // CONSTRUCTOR VALUES
    go.position = Vector2_From(x, y);

    return go;
}

void GameObject_AddTag(GameObject* go, const char* tag) {
    // check bounds first
    if (go->tagsLength >= MAX_TAGS) {
        printf("GameObject_AddTag(): Tried to add a tag when the maximum number of tags has been reached\n");
        return;
    }

    // check length of tag
    if (strlen(tag) >= MAX_TAG_LENGTH) {
        printf("GameObject_AddTag(): Tried to add a tag that surpasses the tag character limit of %d\n", MAX_TAG_LENGTH);
        return;
    }

    // Add tag at length index
    strcpy(go->tags[go->tagsLength], tag);
}

bool GameObject_HasTag(GameObject* go, const char* tag) {
    // check length of tag
    if (strlen(tag) >= MAX_TAG_LENGTH) {
        printf("GameObject_HasTag(): Tried to compare a tag that surpasses the tag character limit of %d\n", MAX_TAG_LENGTH);
        return false;
    }

    for (int i = 0; i < go->tagsLength; i++) {
        if (strcmp(tag, go->tags[i]) == 0) {
            return true;
        }
    }

    return false;
}

void GameObject_SetParentType(GameObject* go, const char* type) {
    if (strlen(type) >= MAX_PARENT_TYPE_LENGTH) {
        printf("GameObject_SetParentType(): Tried to set a parentType that surpasses the character limit of %d\n", MAX_TAG_LENGTH);
        return;
    }

    // set the type
    strcpy(go->parentType, type);
}
