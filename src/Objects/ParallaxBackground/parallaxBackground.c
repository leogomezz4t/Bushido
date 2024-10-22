#include "parallaxBackground.h"
#include "gameObject.h"
#include "spriteRenderer.h"

void ParallaxBackground_Init(ParallaxBackground* bg, int x, int y) {
    // PARALLAX BACKGROUND INITIALIZATION
    bg->initialPosition = (Vector2) {x, y};

    // GAME OBJECT INITIALIZATION
    bg->gameObject = GameObject_From(x, y, (void*) bg);
}
