#include "Menu.h"
#include "gMap.h"
#include "inithelper.h"
#include "constants.h"
Menu::Menu()
{
    difficulty = DEFAULT;
}
Menu::~Menu()
{
}
Menu::renderMenu()
{
    SDL_RenderCopy(gRenderer,gBackgroundTexture,NULL,NULL);
    SDL_Rect aboutButtonRect = {80*3,80*6,160,80};
    SDL_Rect playButtonRect = {80*3,80*4,160,80};
    SDL_Rect logoRect = {80*2-40,80-40,320+80,160+40};
    SDL_Rect musicRect = {40,40,40,40};
    SDL_Rect SFXRect = {20,100,80,40};
    SDL_RenderCopy(gRenderer,logo,NULL,&logoRect);
    SDL_RenderCopy(gRenderer,aboutButton,NULL,&aboutButtonRect);
    SDL_RenderCopy(gRenderer,playButton,NULL,&playButtonRect);
    SDL_RenderCopy(gRenderer,(music?musicButtonOn:musicButtonOff),NULL,&musicRect);
    SDL_RenderCopy(gRenderer,(SFX?SFXButtonOn:SFXButtonOff),NULL,&SFXRect);
    SDL_RenderPresent(gRenderer);
}
Menu::handleEventMenu()
    {
        SDL_Rect aboutButtonRect = {80*3,80*6,160,80};
        SDL_Rect playButtonRect = {80*3,80*4,160,80};
        SDL_Rect musicRect = {40,40,40,40};
        SDL_Rect SFXRect = {20,100,80,40};
                        while( SDL_PollEvent( &e ) != 0 )
                        {
                            if( e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP )
                            {
                                if ( e.type == SDL_MOUSEBUTTONDOWN)
                                {
                                    int posX, posY;
                                    SDL_GetMouseState( &posX, &posY );
                                    if (isInside(posX,posY,aboutButtonRect))
                                    {
                                        if (SFX) Mix_PlayChannel(-1, click, 0);
                                       state = ABOUT;
                                    }
                                    if (isInside(posX,posY,playButtonRect))
                                    {
                                        if (SFX) Mix_PlayChannel(-1, click, 0);
                                        state = CONFIG;
                                    }
                                    if (isInside(posX,posY,musicRect))
                                    {
                                        if (SFX) Mix_PlayChannel(-1, click, 0);
                                        if (music)
                                        {
                                            Mix_HaltMusic();
                                            music = false;
                                            SDL_RenderCopy(gRenderer,musicButtonOff,NULL,&musicRect);
                                            SDL_RenderPresent(gRenderer);
                                        }
                                        else
                                        {
                                            music = true;
                                            Mix_PlayMusic(backgroundMusic,0);
                                            SDL_RenderCopy(gRenderer,musicButtonOn,NULL,&musicRect);
                                            SDL_RenderPresent(gRenderer);
                                        }
                                    }
                                    if (isInside(posX,posY,SFXRect))
                                    {
                                        Mix_PlayChannel(-1, click, 0);
                                        if (SFX)
                                        {
                                            SFX = false;
                                            SDL_RenderCopy(gRenderer,SFXButtonOff,NULL,&SFXRect);
                                            SDL_RenderPresent(gRenderer);
                                        }
                                        else
                                        {
                                            SFX = true;
                                            SDL_RenderCopy(gRenderer,SFXButtonOn,NULL,&SFXRect);
                                            SDL_RenderPresent(gRenderer);
                                        }
                                    }

                                }
                            }
                            if (e.type == SDL_KEYDOWN)
                            {
                                if ( e.key.keysym.sym == SDLK_ESCAPE )
                                {
                                    isQuit = true;
                                    cout<<isQuit;
                                }
                            }
                            if (e.type == SDL_QUIT)
                            {
                                isQuit = true;
                            }
                        }

}
