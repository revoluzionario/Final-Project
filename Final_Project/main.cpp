#include <iostream>
#include "constants.h"
#include "inithelper.h"
#include "gMap.h"
#include "Menu.h"
#include "AboutMenu.h"
#include "Config.h"




int main (int argc, char* argv[])
{
    if (!init())
    {
        exit(-1);
    }
    else
    {
        gWindow = generateWindow();
        gRenderer = generateRenderer(gWindow);
        if (!loadMedia())
        {
            exit(-2);
        }
        else
        {
        while (!isQuit)
            {
                switch (state)
                {
                case MENU:
                    {
                        Menu menu;
                        menu.renderMenu();

                        while (state== MENU && !isQuit)
                        {
                            menu.handleEventMenu();
                        }
                        break;
                    }
                case ABOUT:
                    {
                        AboutMenu about;
                        about.renderAbout();
                        while (state == ABOUT)
                        {
                            about.handleEventAbout();
                        }
                        break;
                    }
                case CONFIG:
                    {
                        Config configMenu;
                        configMenu.renderConfig();
                        while (state == CONFIG)
                        {
                            configMenu.handleEventConfig();
                        }
                    }
                case PLAY:
                    gMap* board = new gMap (ROW_SIZE,COLUMN_SIZE,MINE_COUNT);
                    while ( !board->lose &&!isQuit && !board->win && state == PLAY)
                    {
                        //Handle events on queue
                        while( SDL_PollEvent( &e ) != 0 )
                        {
                            //User requests quit
                            if( e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
                            {
                                isQuit = true;
                            }

                            //Handle button events
                            board->handleEvent();
                            board->win = board->checkWinning();
                        }

                        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                        SDL_RenderClear( gRenderer );
                        SDL_Rect backgroundRect {0,0,640,640};
                        SDL_Rect optionRect {0,640,640,80};
                        //Render background
                        SDL_RenderCopy(gRenderer, gBackgroundTexture, NULL, &backgroundRect);
                        SDL_RenderCopy(gRenderer, gGraySurface, NULL,&optionRect);
                        //Render buttons
                        board->renderTable();
                        //Render mine/flag left
                        board->flagManager();

                        //Perform win/lose flag
                        board->endgameFlag();
                        //Update screen
                        SDL_RenderPresent( gRenderer );
                    }
                    board->playAgainManager();
                    delete board;
                    break;
                }
            }
        }
    }
    close();
}
