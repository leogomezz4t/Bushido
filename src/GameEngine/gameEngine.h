typedef struct {
    int windowWidth;
    int windowHeight;
    const char* gameName;
} GameState;

void GameState_InitGame(GameState* state);

void GameState_CloseGame(GameState* state);
