#ifndef GMAP_H_INCLUDED
#define GMAP_H_INCLUDED
#include <SDL2/SDL.h>
#include "constants.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "inithelper.h"
bool isInside(const int posX, const int posY, SDL_Rect &rect);

class gMap
{
    public:
    gMap(int w, int h, int m);
    ~gMap();
    int width; int height; int mines;
    bool win, lose;
    bool pause;
    int remainFlags, remainTiles;
    int** sBoard;
    int** Board;
    void createBoard();
    void destroyBoard();
    void createTableWithMines();
    void renderTable();
    void handleEvent();
    void reveal(int i, int j);
    bool checkWinning();
    void flagManager();
    void endgameFlag();
    void playAgainManager();
};

#endif // GMAP_H_INCLUDED
