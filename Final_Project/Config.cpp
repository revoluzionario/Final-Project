#include "Config.h"
Config::Config()
{

}
Config::~Config()
{

}
void Config::renderConfig()
{
    SDL_RenderCopy(gRenderer,gBackgroundTexture,NULL,NULL);
    SDL_Rect EasyButtonRect = {80*3,80*1,160,80};
    SDL_Rect NormalButtonRect = {80*3,80*3,160,80};
    SDL_Rect HardButtonRect = {80*3,80*5,160,80};
    SDL_Rect PlayButtonRect = {80*3,80*7,160,80};
    SDL_RenderCopy(gRenderer,easyDifButton,NULL,&EasyButtonRect);
    SDL_RenderCopy(gRenderer,normalDifButton,NULL,&NormalButtonRect);
    SDL_RenderCopy(gRenderer,hardDifButton,NULL,&HardButtonRect);
    SDL_RenderCopy(gRenderer,playButton,NULL,&PlayButtonRect);
    SDL_RenderPresent(gRenderer);
}
void Config::modifyStat()
{
    switch (difficulty)
    {
    case EASY:
        ROW_SIZE = 10;
        COLUMN_SIZE = 10;
        MINE_COUNT = 12;
        DISTANCE_BETWEEN = (SCREEN_WIDTH - ROW_SIZE * TILE_SIZE) / 2;
        break;
    case NORMAL:
        ROW_SIZE = 15;
        COLUMN_SIZE = 15;
        MINE_COUNT = 36;
        DISTANCE_BETWEEN = (SCREEN_WIDTH - ROW_SIZE * TILE_SIZE) / 2;
        break;
    case HARD:
        ROW_SIZE = 20;
        COLUMN_SIZE = 20;
        MINE_COUNT = 82;
        DISTANCE_BETWEEN = (SCREEN_WIDTH - ROW_SIZE * TILE_SIZE) / 2;
        break;
    case DEFAULT:
        break;

    }
}
void Config::handleEventConfig()
{
    SDL_Rect EasyButtonRect = {80*3,80*1,160,80};
    SDL_Rect NormalButtonRect = {80*3,80*3,160,80};
    SDL_Rect HardButtonRect = {80*3,80*5,160,80};
    SDL_Rect PlayButtonRect = {80*3,80*7,160,80};
                        while( SDL_PollEvent( &e ) != 0 )
                        {
                            if( e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP )
                            {
                                if ( e.type == SDL_MOUSEBUTTONDOWN)
                                {
                                    int posX, posY;
                                    SDL_GetMouseState( &posX, &posY );
                                    if (isInside(posX,posY,EasyButtonRect))
                                    {
                                       difficulty = EASY;
                                    }
                                    if (isInside(posX,posY,NormalButtonRect))
                                    {
                                       difficulty = NORMAL;
                                    }
                                    if (isInside(posX,posY,HardButtonRect))
                                    {
                                       difficulty = HARD;
                                    }
                                    if (isInside(posX,posY,PlayButtonRect)&&difficulty!=DEFAULT)
                                    {
                                        modifyStat();
                                        state = PLAY;
                                    }
                                }
                            }
                            if (e.type == SDL_KEYDOWN)
                            {
                                if ( e.key.keysym.sym == SDLK_ESCAPE )
                                {
                                    state = MENU;
                                }
                            }
                            if (e.type == SDL_QUIT)
                            {
                                isQuit = true;
                            }
                        }

}
