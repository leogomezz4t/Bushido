class GameEngine {
    // Define properties
    // Scene variables
    scenes = [];
    currentSceneIndex = 0;
    // image paths
    animationPaths = {};
    // image loading references;
    requestedSprites = [];
    loadedImages = {};
    // instantiate animations
    animations = {};
    // fonts
    fonts = {};
    // preload callbacks
    // animation methods
    requestSprite(sprite, callback) {
        this.requestedSprites.push({
            sprite: sprite,
            callback: callback
        });
    }
    // Scene methods
    addScene(scene) {
        scene.game = this;
        this.scenes.push(scene);
    }
    switchScene(scene) {
        let i;
        if ((typeof scene) === 'string') {
            i = this.scenes.findIndex(x => x.id === scene);
        }
        else if (scene instanceof Scene) {
            i = this.scenes.indexOf(scene);
        }
        if (i === -1) {
            throw new Error("Tried to switch to scene that does not exist");
        }
        this.currentSceneIndex = i;
    }
    get currentScene() {
        return this.scenes[this.currentSceneIndex];
    }
    // End scene methods
    // P5 js required functions
    preload() {
        for (const scene of this.scenes) {
            scene.preload();
        }
        this.animationPaths = loadJSON("data/animationPaths.json", () => {
            // Iterate through all images and load them
            for (const sprite in this.animationPaths) {
                this.loadedImages[sprite] = {};
                this.animations[sprite] = {};
                // iterate through the animations
                for (const ani in this.animationPaths[sprite]) {
                    this.loadedImages[sprite][ani] = {};
                    // iterate through the images
                    for (const img of this.animationPaths[sprite][ani]) {
                        this.loadedImages[sprite][ani][img] = loadImage(img);
                    }
                    // Add this animation
                    this.animations[sprite][ani] = {
                        framesPath: `${sprite}/${ani}`,
                        game: this
                    };
                }
            }
            // Iterate through requested animations
            for (const req of this.requestedSprites) {
                const anis = {};
                // iterate through the animations of that sprite
                for (const ani in this.animationPaths[req.sprite]) {
                    anis[ani] = new SpriteAnimation(`${req.sprite}/${ani}`, this);
                }
                req.callback(anis);
            }
            console.log(this.loadedImages);
        });
    }
    setup() {
        this.currentScene.setup();
    }
    loopPrelude() {
        noSmooth();
    }
    drawCurrentScene() {
        this.currentScene.update();
    }
}
