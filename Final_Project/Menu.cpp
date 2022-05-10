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
    SDL_RenderCopy(gRenderer,logo,NULL,&logoRect);
    SDL_RenderCopy(gRenderer,aboutButton,NULL,&aboutButtonRect);
    SDL_RenderCopy(gRenderer,playButton,NULL,&playButtonRect);
    SDL_RenderPresent(gRenderer);
}
Menu::handleEventMenu()
    {
        SDL_Rect aboutButtonRect = {80*3,80*6,160,80};
        SDL_Rect playButtonRect = {80*3,80*4,160,80};
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
                                       state = ABOUT;
                                    }
                                    if (isInside(posX,posY,playButtonRect))
                                    {
                                        state = CONFIG;
                                    }
                                }
                            }
                            if (e.type == SDL_KEYDOWN)
                            {
                                if ( e.key.keysym.sym == SDLK_ESCAPE )
                                {
                                    cout<<"escape!";
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
