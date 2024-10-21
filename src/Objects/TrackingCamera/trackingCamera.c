#include "trackingCamera.h"
#include "gameObject.h"
#include <math.h>
#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>

void trackingUpdate(void* data, Scene* scene) {
    // QUALITY OF LIFE
    TrackingCamera* trackingCamera = (TrackingCamera*) data;
    GameObject* go = &trackingCamera->gameObject;
    Camera2D* camera2d = &trackingCamera->camera;
    GameObject* follow = trackingCamera->followTarget;

    // FOLLOW LOGIC
    float xDist = fabsf(camera2d->target.x - follow->position.x);
    float yDist = fabsf(camera2d->target.y - follow->position.y);

    // x component
    if (camera2d->target.x < follow->position.x) {
        camera2d->target.x += xDist * trackingCamera->dampingStrength;
    }
    if (camera2d->target.x > follow->position.x) {
        camera2d->target.x -= xDist * trackingCamera->dampingStrength;
    }

    // y component
    if (camera2d->target.y < follow->position.y) {
        camera2d->target.y += yDist * trackingCamera->dampingStrength;
    }
    if (camera2d->target.y < follow->position.y) {
        camera2d->target.y += yDist * trackingCamera->dampingStrength;
    }
}

void TrackingCamera_Init(TrackingCamera* cam, GameObject* target) {
    // TRACKING CAMERA DEFAULT VALUES
    cam->dampingStrength = 0.1f;
    // TRACKING CAMERA INITIALIZATION
    cam->followTarget = target;
    if (target == NULL) {
        printf("Warning: Passed a target of NULL to TrackingCamera_Init\n");
    }
    // GAME OBJECT INITIALIZATION
    cam->gameObject = GameObject_From(target->position.x, target->position.y, (void*) cam);
    cam->gameObject.update = trackingUpdate;

    // CAMERA2D INITIALIZATION
    cam->camera.zoom = 1.0f;
    cam->camera.rotation = 0.0f;
    cam->camera.offset = (Vector2) {0, 0};
    cam->camera.target = target->position;
}
