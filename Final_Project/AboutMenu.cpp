#include "AboutMenu.h"
AboutMenu::AboutMenu()
{
}
AboutMenu::~AboutMenu()
{
}
AboutMenu::renderAbout()
{
    SDL_RenderCopy(gRenderer,gAboutTexture,NULL,NULL);
    SDL_Rect returnButtonRect = {20,20,40,40};
    SDL_RenderCopy(gRenderer,returnButton,NULL,&returnButtonRect);
    SDL_RenderPresent(gRenderer);
}
AboutMenu::handleEventAbout()
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
                                       state = MENU;
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
