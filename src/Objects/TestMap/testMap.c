#include "collider.h"
#include "gameObject.h"
#include "testMap.h"
#include "scene.h"
#include <raylib.h>

void testMapScene(void* data, Scene* scene) {
    // QUALITY OF LIFE
    TestMap* testMap = (TestMap*) data;
    //
    testMap->imageTexture = Scene_AddTexture(scene, testMap->filePath);
}

void testMapUpdate(void* data, Scene* scene) {
    // QUALITY OF LIFE
    TestMap* testMap = (TestMap*) data;
    //
    DrawTextureEx(*testMap->imageTexture, testMap->gameObject.position, 0.0f, testMap->scale, WHITE);
}

void TestMap_Init(TestMap* testMap, int x, int y, const char* filepath) {
    // TEST MAP DEFAULT VALUES
    testMap->scale = 3;
    // TEST MAP INITIALIZATION
    testMap->filePath = filepath;
    // GAME OBJECT INITIALIZATION
    testMap->gameObject = GameObject_From(x, y, (void*) testMap);
    testMap->gameObject.update = testMapUpdate;
    testMap->gameObject.onSceneAttach = testMapScene;
    // COLLIDER INITIALIZATION
    testMap->collider = Collider_From(&testMap->gameObject);
    // ATTACH COMPONENTS
    testMap->gameObject._componentCollider = &testMap->collider;
}
