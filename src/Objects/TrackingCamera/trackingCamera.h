#ifndef TRACKING_CAMERA_H
#define TRACKING_CAMERA_H

#include "gameObject.h"
#include "raylib.h"

struct tracking_camera_t {
    // VALUES
    float dampingStrength;
    // REFERENCES
    GameObject* followTarget;
    // COMPONENTS
    GameObject gameObject;
    Camera2D camera;
};

typedef struct tracking_camera_t TrackingCamera;

void TrackingCamera_Init(TrackingCamera* cam, GameObject* target);
#endif
