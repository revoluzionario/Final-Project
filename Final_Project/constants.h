#ifndef CONSTANTS_H_INCLUDED
#define CONSTANTS_H_INCLUDED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern int ROW_SIZE;
extern int COLUMN_SIZE;
extern int DISTANCE_BETWEEN;
extern int MINE_COUNT;
extern const int TILE_SIZE;
extern bool isQuit;
extern SDL_Event e;
enum gameState
{
    MENU, ABOUT, PLAY, CONFIG
};
enum Difficulty
{
    DEFAULT,EASY,NORMAL,HARD
};
extern gameState state;
extern Difficulty difficulty;
//The window we'll be rendering to
extern SDL_Window* gWindow;

//The window renderer
extern SDL_Renderer* gRenderer;
// GUI Button
extern SDL_Texture* aboutButton;
extern SDL_Texture* playButton;
extern SDL_Texture* returnButton;
extern SDL_Texture* playAgainGUI;
extern SDL_Texture* easyDifButton;
extern SDL_Texture* normalDifButton;
extern SDL_Texture* hardDifButton;

//Global font
extern TTF_Font* gameFont;
//The sound effects that will be used
extern Mix_Music *winner;
extern Mix_Music *loser;
extern Mix_Chunk *click;
extern Mix_Music *backgroundMusic;

//Mouse button texture
extern SDL_Texture* mineTile;
extern SDL_Texture* flagTile;
extern SDL_Texture* uncoveredTile;
extern SDL_Texture* Tile_0;
extern SDL_Texture* Tile_1;
extern SDL_Texture* Tile_2;
extern SDL_Texture* Tile_3;
extern SDL_Texture* Tile_4;
extern SDL_Texture* Tile_5;
extern SDL_Texture* Tile_6;
extern SDL_Texture* Tile_7;
extern SDL_Texture* Tile_8;

//Screen texture
extern SDL_Texture* gBackgroundTexture;
extern SDL_Texture* gAboutTexture;
extern SDL_Texture* gGraySurface;
extern SDL_Texture* logo;


#endif // CONSTANTS_H_INCLUDED
