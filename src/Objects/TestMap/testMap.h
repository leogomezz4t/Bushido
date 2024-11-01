#ifndef TESTMAP_H
#define TESTMAP_H

#include "gameObject.h"
#include "collider.h"
#include <raylib.h>

struct test_map_t {
    // VALUES
    const char* filePath;
    Texture2D* imageTexture;

    float scale;
    // COMPONENTS
    GameObject gameObject;
    Collider collider;
};

typedef struct test_map_t TestMap;

void TestMap_Init(TestMap* testMap, int x, int y, const char* filepath);

#endif
