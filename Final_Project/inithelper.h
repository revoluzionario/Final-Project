#ifndef INTHELPER_H_INCLUDED
#define INTHELPER_H_INCLUDED

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>
using std::string, std::cout, std::endl;
extern const int SCREEN_HEIGHT;
extern const int SCREEN_WIDTH;
bool init();
bool loadMedia();
void close();
SDL_Window* generateWindow();
SDL_Renderer* generateRenderer(SDL_Window* window);
TTF_Font* loadFont(string path, const int fontSize);
SDL_Texture* loadTexture(SDL_Renderer* renderer, TTF_Font* font, SDL_Color& colour, const char* text);
SDL_Texture* loadTexture(SDL_Renderer* renderer, string path);




#endif // INTHELPER_H_INCLUDED
