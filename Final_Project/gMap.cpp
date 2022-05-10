#include "gMap.h"
using std::cout,std::endl,std::string;
bool isInside(const int posX, const int posY, SDL_Rect &rect)
{
    return (posX > rect.x && posY > rect.y && posX < rect.x + rect.w && posY < rect.y + rect.h);
}
gMap::gMap(int w, int h, int m): width(w), height(h), mines(m), remainTiles(w*h), remainFlags(m), win(false), lose(false)
{
    createBoard();
    createTableWithMines();
}
gMap::~gMap()
{
    destroyBoard();
}
void gMap::createBoard()
{
    sBoard = new int* [height];
    Board = new int* [height];
    for (int i=0;i<height;i++)
    {
        sBoard[i] = new int [width];
        Board[i] = new int [width];
        for (int j=0;j<width;j++)
        {

            sBoard[i][j] = 10;
            Board[i][j] = 0;
        }
    }
}
void gMap::destroyBoard()
{
    for (int i = 0; i < height; i++)
	{
		delete sBoard[i];
		delete Board[i];
	}
	delete sBoard;
    delete Board;
}
void gMap::createTableWithMines()
{
    srand(time(NULL));

	std::vector<int> notSelected;

	int temp = width * height;
	int pos;
	int _x, _y;

	for (int i = 0; i < temp; i++)
	{
		notSelected.push_back(i);
	}

	for (int i = 0; i < mines; i++)
	{
		pos = rand() % notSelected.size();
		_x = notSelected[pos] / height;
		_y = notSelected[pos] % height;
		Board[_x][_y] = 9;
		for (int a=-1;a<=1;a++)
            for (int b=-1;b<=1;b++)
            {
                if (b != 0 || a != 0)
                {
                    if (_y + b >= 0 && _y + b < width && _x + a >= 0 && _x + a < height && Board[_x+a][_y+b]!=9)
                    {
                        Board[_x+a][_y+b]++;
                    }
                }
            }
		notSelected.erase(notSelected.begin() + pos);
	}
}
void gMap::renderTable()
{
    for (int i=0;i<height;i++)
        {
            for (int j=0;j<width;j++)
            {
                SDL_Rect cell = {TILE_SIZE*j+DISTANCE_BETWEEN, TILE_SIZE*i+DISTANCE_BETWEEN, TILE_SIZE, TILE_SIZE};
                switch (sBoard[i][j])
                {
                    case 0:
                    SDL_RenderCopy(gRenderer,Tile_0,NULL,&cell);
                    break;
                    case 1:
                    SDL_RenderCopy(gRenderer,Tile_1,NULL,&cell);
                    break;
                    case 2:
                    SDL_RenderCopy(gRenderer,Tile_2,NULL,&cell);
                    break;
                    case 3:
                    SDL_RenderCopy(gRenderer,Tile_3,NULL,&cell);
                    break;
                    case 4:
                    SDL_RenderCopy(gRenderer,Tile_4,NULL,&cell);
                    break;
                    case 5:
                    SDL_RenderCopy(gRenderer,Tile_5,NULL,&cell);
                    break;
                    case 6:
                    SDL_RenderCopy(gRenderer,Tile_6,NULL,&cell);
                    break;
                    case 7:
                    SDL_RenderCopy(gRenderer,Tile_7,NULL,&cell);
                    break;
                    case 8:
                    SDL_RenderCopy(gRenderer,Tile_8,NULL,&cell);
                    break;
                    case 9:
                    SDL_RenderCopy(gRenderer,mineTile,NULL,&cell);
                    break;
                    case 10:
                    SDL_RenderCopy(gRenderer,uncoveredTile,NULL,&cell);
                    break;
                    case 11:
                    SDL_RenderCopy(gRenderer,flagTile,NULL,&cell);
                    break;
                }
            }
        }
}
void gMap::handleEvent()
{
    //If mouse event happened
	if( e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP )
	{
		if ( e.type == SDL_MOUSEBUTTONDOWN)
		{
            int posX, posY;
            SDL_GetMouseState( &posX, &posY );
            int i = (posY - DISTANCE_BETWEEN)/TILE_SIZE;
            int j = (posX - DISTANCE_BETWEEN)/TILE_SIZE;
            SDL_Rect cellRect = {TILE_SIZE*j+DISTANCE_BETWEEN, TILE_SIZE*i+DISTANCE_BETWEEN, TILE_SIZE, TILE_SIZE};
			if (isInside(posX,posY,cellRect))
            {
                //Play the sound effect

				Mix_PlayChannel(-1, click, 0);

				//Set mouse clicked
				switch (e.button.button)
				{
                    case SDL_BUTTON_LEFT:
                    {
                        reveal(i, j);
                        if (Board[i][j] == 9)
                        {
                            lose = true;
                        }
                        break;
                    }
                    case SDL_BUTTON_RIGHT:
                    {
                        if (sBoard[i][j] >= 10)
                        {
                            if (sBoard[i][j] == 10)
                            {
                                if (remainFlags == 0) break;
                                sBoard[i][j] = 11;
                                remainFlags--;
                            }
                            else
                            {
                                sBoard[i][j] = 10;
                                remainFlags++;
                            }
                        }
                        break;
                    }
				}
            }
		}
	}
}
void gMap::reveal(int i, int j)
{
    if (sBoard[i][j] == 10)
    {
        sBoard[i][j] = Board[i][j];
        remainTiles--;
        if (sBoard[i][j] == 0)
        {
            if (i < width - 1)
                reveal(i + 1, j);
            if (i > 0)
                reveal(i - 1, j);
            if (j < height - 1)
                reveal(i, j + 1);
            if (j > 0)
                reveal(i, j - 1);
            if (i > 0 && j > 0)
                reveal(i - 1, j - 1);
            if (i < width - 1 && j < height - 1)
                reveal(i + 1, j + 1);
            if (i > 0 && j < height - 1)
                reveal(i - 1, j + 1);
            if (i < width - 1 && j > 0)
                reveal(i + 1, j - 1);
        }
    }
}
bool gMap::checkWinning()
{
    bool win = false;
    if (remainTiles == MINE_COUNT)
    {
        win = true;
    }
    return win;
}
void gMap::flagManager()
{
    //Render text
    if ( !lose && !win )
    {
        //Set text color
        SDL_Color textColor = { 140, 140, 140, 255 };
        std::stringstream flagLeft;
        //Erase the buffer
        flagLeft.str ( "" );
        flagLeft << "Flag left: " << remainFlags;

        string mineStat = std::to_string(mines) + " mines";
        string widthStat = std::to_string(width) + " columns";
        string heightStat = std::to_string(height) + " rows";
        //Render text
        SDL_Color white {0xFF,0xFF,0xFF};
        SDL_Texture* flagManageTexture = loadTexture(gRenderer,gameFont,white,flagLeft.str().c_str());
        SDL_Texture* mineStatTexture = loadTexture(gRenderer,gameFont,white, mineStat.c_str());
        SDL_Texture* heightStatTexture = loadTexture(gRenderer,gameFont,white,heightStat.c_str());
        SDL_Texture* widthStatTexture = loadTexture(gRenderer,gameFont,white,widthStat.c_str());
        SDL_Rect flagManageRect = {640*2/3,645,640/3-30,30};
        SDL_Rect mineStatRect = {640*2/3+42,680,640/3-70,30};
        SDL_Rect heightStatRect = {640/3,645,640/3-75,30};
        SDL_Rect widthStatRect = {640/3,680,640/3-10,30};
        SDL_RenderCopy(gRenderer,flagManageTexture, NULL, &flagManageRect);
        SDL_RenderCopy(gRenderer,mineStatTexture, NULL, &mineStatRect);
        SDL_RenderCopy(gRenderer,heightStatTexture, NULL, &heightStatRect);
        SDL_RenderCopy(gRenderer,widthStatTexture, NULL, &widthStatRect);
    }
}
void gMap::endgameFlag()
{
    //Check if win
    if ( win && !lose )
    {
        //Update screen
        SDL_RenderPresent( gRenderer );

        //Delay loading screen
        SDL_Delay(500);

        //Play victory music
        Mix_PlayMusic(winner, 0);
        //Render winning scene
        SDL_Rect youWinRect = {640/3,645,640/3-30,30};
        SDL_Color white {0xFF,0xFF,0xFF};
        SDL_Texture* youWin = loadTexture(gRenderer,gameFont,white,"YOU WIN!");
        SDL_RenderCopy(gRenderer,youWin, NULL, &youWinRect);

        //Render playAgain
    }

    //Check if lose
    if ( lose )
    {
        //Play losing music
        Mix_PlayMusic(loser, 0);

        for( int i = 0; i < ROW_SIZE; i++ )
        {
            for ( int j = 0; j < COLUMN_SIZE; j++ )
            {
                sBoard[i][j] = Board[i][j];
                renderTable();
            }
        }
        SDL_Rect youLoseRect = {640/3,645,640/3-30,30};
        SDL_Color white {0xFF,0xFF,0xFF};
        SDL_Texture* youLose = loadTexture(gRenderer,gameFont,white,"YOU LOSE!");
        SDL_RenderCopy(gRenderer,youLose, NULL, &youLoseRect);
        //Render play again
    }
}
void gMap::playAgainManager()
{
                    while ((win || lose)&&!isQuit)
                    {
                        SDL_Rect playAgainRect = {80*2,80*3,80*4,80*2};
                        SDL_RenderCopy(gRenderer,playAgainGUI,NULL,&playAgainRect);
                        SDL_Rect yesRect = {28+160,79+240,120,36};
                        SDL_Rect noRect = {169+160,79+240,120,36};
                        SDL_RenderPresent(gRenderer);
                        while( SDL_PollEvent( &e ) != 0 )
                        {
                            if( e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP )
                            {
                                if ( e.type == SDL_MOUSEBUTTONDOWN)
                                {
                                    int posX, posY;
                                    SDL_GetMouseState( &posX, &posY );
                                    if (isInside(posX,posY,yesRect))
                                    {
                                        Mix_HaltMusic();
                                        isQuit = false;
                                        win = false;
                                        lose = false;
                                    }
                                    if (isInside(posX,posY,noRect))
                                    {
                                        state = MENU;
                                        Mix_HaltMusic();
                                        isQuit = false;
                                        win = false;
                                        lose = false;
                                    }
                                }

                            }
                            if (e.type == SDL_KEYDOWN)
                            {
                                if ( e.key.keysym.sym == SDLK_ESCAPE )
                                {
                                    isQuit = true;
                                }
                            }
                            if (e.type == SDL_QUIT)
                            {
                                isQuit = true;
                            }
                        }
                    }
}
