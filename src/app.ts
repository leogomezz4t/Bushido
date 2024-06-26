// Optimizations for p5
// @ts-ignore
p5.disableFriendlyErrors = true;

// Game manager stuff
const game: GameEngine = new GameEngine();
// Assets
const fonts = {
  "bushido": null,
  "bushidob": null,
  "bushidobi": null,
  "bushidobl": null,
  "bushidoi": null,
  "bushidol": null,
  "bushidos": null,
  "bushidosi": null
}

// refs
let whs: Samurai;

// SCENE SETUP || BEFORE PRELOAD
const testScene: Scene = new Scene(game, "test");
setupTestScene(testScene);
// DEATH SCENE SETUP
const deathScene: Scene = new Scene(game, "death");
setupDeathScene(deathScene);
// MAIN MENU SCENE
const mainScene: Scene = new Scene(game, "main_menu");
setupMainMenuScene(mainScene);
// CONTROLS SCENE
const controlsScene: Scene = new Scene(game, "controls");
setupControlsScene(controlsScene);
// end test scene
game.switchScene("main_menu");

// END SCENE SETUP

function preload() {
  // font loading
  fonts["bushido"] = loadFont("../fonts/bushido/bushido.ttf");
  fonts["bushidob"] = loadFont("../fonts/bushido/bushidob.ttf");
  fonts["bushidobi"] = loadFont("../fonts/bushido/bushidobi.ttf");
  fonts["bushidobl"] = loadFont("../fonts/bushido/bushidobl.ttf");
  fonts["bushidoi"] = loadFont("../fonts/bushido/bushidoi.ttf");
  fonts["bushidol"] = loadFont("../fonts/bushido/bushidol.ttf");
  fonts["bushidos"] = loadFont("../fonts/bushido/bushidos.ttf");
  fonts["bushidosi"] = loadFont("../fonts/bushido/bushidosi.ttf");

  game.fonts = fonts;
  game.preload();
}

function setup() {
  let sketch = createCanvas(CANVAS_WIDTH, CANVAS_HEIGHT);
  sketch.parent("mycanvas");
  // Game setup
  game.setup();
}//end setup

function draw() {
  background("#2a2f4e");
  // Set frame rate
  frameRate(60);
  // Run game
  game.loopPrelude();
  game.drawCurrentScene();
 
  // HUD
  fill("red")
  strokeWeight(0.5);
  stroke("black")
  textSize(16);
  text(`FPS: ${frameRate().toFixed(2)}`, CANVAS_WIDTH-90, 15);
  // Detect framerate drops
  if (frameRate() < 45) {
    console.warn("Low frame rate");
  }


}//end draw

// Scene setups
function setupTestScene(scene: Scene) { // within preload 
  // player
  const player = new Player(CANVAS_WIDTH/2, 100, 10);
  player.debug = false;
  // HUD
  const health = new HealthBar(20, 20, 150, 25, player.maxHitpoints);
  health.tracker = player;
  scene.addHUDObject(health);
  // Floors
  const floor = new WorldObject(0, CANVAS_HEIGHT-50, 2, "artwork/world/level1.png", false);
  floor.drawLayer = 3;
  floor.addHitbox((w, h) => {
    return new Hitbox(0, 200, w, h, CollisionType.Colliding, floor)
  })
  floor.addTag("floor");

  // enemy
  for (let i = 1; i < 6; i++) {
    const whiteHat: WhiteHatSamurai = new WhiteHatSamurai(player.position.x + (650 * i), 100);
    whiteHat.drawLayer = 5;
    scene.addGameObject(whiteHat);
  }

  const playerCam = new TrackingCamera(1, player);
  scene.addCamera(playerCam);

  scene.setCurrentCamera(playerCam);
  // background
  const background = new ParallaxBackground(-200, 0, 4, 20, playerCam,
    "artwork/world/Background/3.png",
    "artwork/world/Background/2.png",
    "artwork/world/Background/1.png");
  scene.addGameObject(background);

  // Game Manager
  const manager: GameManager = new GameManager();
  manager.playerReference = player;
  scene.setGameManager(manager);

  scene.addGameObject(floor)
  scene.addGameObject(player);
}

function setupDeathScene(scene: Scene) {
  const background = new GameObject(0, 0, CANVAS_WIDTH, CANVAS_HEIGHT, false);
  background.color = "black";
  scene.addGameObject(background);
  // camera
  const cam = new Camera(CANVAS_WIDTH/2, CANVAS_HEIGHT/2, 1);
  scene.addCamera(cam);
  scene.setCurrentCamera(cam);
  // Text
  const deathText = new TextObject(
    CANVAS_WIDTH/2,
    CANVAS_HEIGHT/2,
    "You died honorably",
    "bushidobl",
    64,
    "black",
    "red");
  deathText.strokeThickness = 2;

  scene.addGameObject(deathText);
}

function setupMainMenuScene(scene: Scene) {
  // camera
const mainCam = new Camera(CANVAS_WIDTH/2, 450, 1);
  scene.addCamera(mainCam);
  scene.setCurrentCamera(mainCam);

  // Background
  const background = new ParallaxBackground(0, 0, 4, 1, mainCam,
    "artwork/world/Background/3.png",
    "artwork/world/Background/2.png",
    "artwork/world/Background/1.png"
  );
  scene.addGameObject(background);

  // floor
  const floor = new WorldObject(-50, CANVAS_HEIGHT-100, 2, "../artwork/world/main_menu.png", false);
  floor.drawLayer = 4;
  scene.addGameObject(floor);

  // Title
  const title = new TextObject(CANVAS_WIDTH/2, 250, "Bushido", "bushidob", 125, "white", "black");
  title.strokeThickness = 5;
  scene.addGameObject(title);

  // Play button
  const play = new PlayButton(400, 400);
  scene.addGameObject(play);

  // Controls buttons
  const controls = new ControlsButton(400, 475);
  scene.addGameObject(controls);
}

function setupControlsScene(scene: Scene) {
  // cam
  const mainCam = new Camera(CANVAS_WIDTH/2, CANVAS_HEIGHT/2, 1);
  scene.addCamera(mainCam);
  scene.setCurrentCamera(mainCam);
  // outer box
  const outerRect = new GameObject(100, 80, 760, 380, false);
  outerRect.drawLayer = 0;
  outerRect.draw = (cameraX: number, cameraY: number) => {
    const INSIDE_COLOR = "#779eb2";
    const OUTSIDE_COLOR = "#446879";

    fill(INSIDE_COLOR);
    stroke(OUTSIDE_COLOR);
    strokeWeight(5);
    rect(cameraX, cameraY, outerRect.width, outerRect.height);
  }
  scene.addGameObject(outerRect);

  // esc 
  const escText = new TextObject(110, 95, "Esc...", "bushidoi", 24, "white", "black");
  escText.strokeThickness = 0.5;
  escText.horizontalAlignType = "left"
  // add escaping logic
  escText.update = () => {
    if (keyIsDown(KEYBOARD_MAP.indexOf("ESCAPE"))) {
      game.switchScene("main_menu");
    }
  }
  scene.addGameObject(escText);

  // title Text
  const title = new TextObject(CANVAS_WIDTH/2, 125, "Controls", "bushidob", 76, "white", "black");
  title.drawLayer = 1;
  scene.addGameObject(title);

  // inner box
  const innerRect = new GameObject(200, 200, 550, 225, false);
  innerRect.drawLayer = 2;
  innerRect.draw = (cameraX: number, cameraY: number) => {
    const INSIDE_COLOR = "#c8dfea";
    const OUTSIDE_COLOR = "#acc8d7";

    fill(INSIDE_COLOR);
    stroke(OUTSIDE_COLOR);
    strokeWeight(3);
    rect(cameraX, cameraY, innerRect.width, innerRect.height);
  }

  scene.addGameObject(innerRect);

  // Controls
  // loop through the controls
  let currentPos = new Vector2(210, 215);
  for (const control in KBM_CONTROLS) {
    const controlText = new TextObject(currentPos.x, currentPos.y, control, "bushido", 18, "white", "black");
    controlText.strokeThickness = 0.5;
    controlText.drawLayer = 3;
    controlText.horizontalAlignType = "left";
    scene.addGameObject(controlText);
    // key 
    const DARK_GRAY = "#A9A9A9";
    const keyName = KEYBOARD_MAP[KBM_CONTROLS[control]];
    const keyText = new TextObject(currentPos.x + 150, currentPos.y, keyName, "bushidob", 18, DARK_GRAY, "black");
    keyText.drawLayer = 5;
    keyText.horizontalAlignType = "left";
    scene.addGameObject(keyText);
   
    // key box
    const keyBoxWidth = (0.625 * keyText.fontSize * keyText.text.length) + 5;
    const keyBox = new GameObject(keyText.position.x - 5, currentPos.y - 10, keyBoxWidth, 25, false);
    keyBox.drawLayer = 4;
    keyBox.color = "#393d42";
    scene.addGameObject(keyBox);


    // change current pos
    currentPos.y += 40;
    if (currentPos.y > 410) {
      currentPos.y = 215;
      currentPos.x += 250;
    }
  }
}

function keyPressed() {
  if (key === 'l') {
    loop();
  }
  if (key === ';') {
    noLoop();
  }
}

function mousePressed() {
  console.log(`X: ${mouseX} Y: ${mouseY}`);
}
// classes
