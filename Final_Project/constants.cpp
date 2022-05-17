#include "constants.h"
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 720;
int ROW_SIZE = 10;
int COLUMN_SIZE = 10;
int DISTANCE_BETWEEN = (SCREEN_WIDTH - ROW_SIZE * TILE_SIZE) / 2;
int MINE_COUNT = 3;
const int TILE_SIZE = 32;
bool isQuit = false;
bool SFX = true;
bool music = true;
SDL_Event e;

 gameState state = MENU;
 Difficulty difficulty = DEFAULT;
//The window we'll be rendering to
 SDL_Window* gWindow = NULL;

//The window renderer
 SDL_Renderer* gRenderer = NULL;

//The sound effects that will be used
 Mix_Music *winner = NULL;
 Mix_Chunk *loser = NULL;
 Mix_Chunk *click = NULL;
 Mix_Music *backgroundMusic = NULL;
//Globally used font
TTF_Font* gameFont = NULL;
//Mouse button texture
 SDL_Texture* mineTile = NULL;
 SDL_Texture* flagTile = NULL;
 SDL_Texture* uncoveredTile = NULL;
 SDL_Texture* Tile_0 = NULL;
 SDL_Texture* Tile_1 = NULL;
 SDL_Texture* Tile_2 = NULL;
 SDL_Texture* Tile_3 = NULL;
 SDL_Texture* Tile_4 = NULL;
 SDL_Texture* Tile_5 = NULL;
 SDL_Texture* Tile_6 = NULL;
 SDL_Texture* Tile_7 = NULL;
 SDL_Texture* Tile_8 = NULL;

//Screen texture
 SDL_Texture* gWinningTexture= NULL;
 SDL_Texture* gBackgroundTexture= NULL;
 SDL_Texture* gAboutTexture= NULL;
 SDL_Texture* gTutorialTexture = NULL;
 SDL_Texture* gGraySurface = NULL;
 SDL_Texture* logo = NULL;

 SDL_Texture* aboutButton = NULL;
 SDL_Texture* playButton = NULL;
 SDL_Texture* returnButton = NULL;
 SDL_Texture* forwardButton = NULL;
 SDL_Texture* playAgainGUI = NULL;
 SDL_Texture* easyDifButton = NULL;
 SDL_Texture* normalDifButton = NULL;
 SDL_Texture* hardDifButton = NULL;
 SDL_Texture* musicButtonOn = NULL;
 SDL_Texture* musicButtonOff = NULL;
 SDL_Texture* SFXButtonOn = NULL;
 SDL_Texture* SFXButtonOff = NULL;
