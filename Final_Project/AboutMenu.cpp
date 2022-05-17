#include "AboutMenu.h"
AboutMenu::AboutMenu()
{
    page = 1;
}
AboutMenu::~AboutMenu()
{
}
AboutMenu::renderAbout()
{
    if (page == 1)
    {
        SDL_RenderCopy(gRenderer,gAboutTexture,NULL,NULL);
        SDL_Rect returnButtonRect = {20,20,40,40};
        SDL_Rect forwardButtonRect = {70,20,40,40};
        SDL_RenderCopy(gRenderer,returnButton,NULL,&returnButtonRect);
        SDL_RenderCopy(gRenderer,forwardButton,NULL,&forwardButtonRect);
        SDL_RenderPresent(gRenderer);
    }
    else
    {
        SDL_RenderCopy(gRenderer,gTutorialTexture,NULL,NULL);
        SDL_Rect returnButtonRect = {20,20,40,40};
        SDL_RenderCopy(gRenderer,returnButton,NULL,&returnButtonRect);
        SDL_RenderPresent(gRenderer);
    }
}
AboutMenu::handleEventAbout()
    {
        if (page == 1)
        {
                        SDL_Rect returnButtonRect = {20,20,40,40};
                        SDL_Rect forwardButtonRect = {70,20,40,40};
                        while( SDL_PollEvent( &e ) != 0 )
                        {
                            if( e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP )
                            {
                                if ( e.type == SDL_MOUSEBUTTONDOWN)
                                {
                                    int posX, posY;
                                    SDL_GetMouseState( &posX, &posY );
                                    if (isInside(posX,posY,returnButtonRect))
                                    {
                                        if (SFX) Mix_PlayChannel(-1, click, 0);
                                       state = MENU;
                                    }
                                    if (isInside(posX,posY,forwardButtonRect))
                                    {
                                        if (SFX) Mix_PlayChannel(-1, click, 0);
                                       page = 2;
                                       renderAbout();
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
                                exit(-1);
                            }
                        }
        }
        else
        {
                        SDL_Rect returnButtonRect = {20,20,40,40};
                        while( SDL_PollEvent( &e ) != 0 )
                        {
                            if( e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP )
                            {
                                if ( e.type == SDL_MOUSEBUTTONDOWN)
                                {
                                    int posX, posY;
                                    SDL_GetMouseState( &posX, &posY );
                                    if (isInside(posX,posY,returnButtonRect))
                                    {
                                        if (SFX) Mix_PlayChannel(-1, click, 0);
                                       page = 1;
                                       renderAbout();
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
                                exit(-1);
                            }
                        }

        }
}
