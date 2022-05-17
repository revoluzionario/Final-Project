#include "inithelper.h"
#include "constants.h"
bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 )
	{
	    cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << endl;
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{

			cout << "Warning: Linear texture filtering not enabled!";
		}

            //Initialize PNG loading
            int imgFlags = IMG_INIT_PNG;
            if( !( IMG_Init( imgFlags ) & imgFlags ) )
            {
                cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
                success = false;
            }
            //Initialize SDL_mixer
            if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
            {
                cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << endl;
                success = false;
            }
            //Initialize SDL_ttf
            if( TTF_Init() == -1 )
            {
                cout << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << endl;
                success = false;
            }
		}

    return success;
}
SDL_Window* generateWindow()
{
        SDL_Window* gWindow = SDL_CreateWindow( "Minesweeper", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        SDL_Surface* windowIcon = IMG_Load("icon.ico");
        SDL_SetWindowIcon(gWindow,windowIcon);
        SDL_FreeSurface(windowIcon);
        windowIcon = NULL;
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			exit(-1);
		}
		return gWindow;
}
SDL_Renderer* generateRenderer(SDL_Window* window)
{
        SDL_Renderer* gRenderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if( gRenderer == NULL )
        {
            printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
            exit(-1);
        }
        return gRenderer;
}
/*
*
*
*
*
*/
TTF_Font* loadFont(string path, const int fontSize)
{
    TTF_Font* gFont = TTF_OpenFont(path.c_str(), fontSize);
    return gFont;
}
//Load texture for text
SDL_Texture* loadTexture(SDL_Renderer* renderer, TTF_Font* font, SDL_Color& colour, const char* text)
{
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text, colour);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface);
    textSurface = NULL;
    return textTexture;
}

//Load texture from image (function overriding)
SDL_Texture* loadTexture(SDL_Renderer* renderer, string path)
{
    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
    {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface );
        if( newTexture == NULL )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    return newTexture;
}
bool loadMedia()
{
	//Loading success flag
	bool success = true;

    gBackgroundTexture = loadTexture(gRenderer,"res/background/background.png");
    gAboutTexture = loadTexture(gRenderer,"res/background/about.png");
    gTutorialTexture = loadTexture(gRenderer,"res/background/aboutTutorial.png");
    gGraySurface = loadTexture(gRenderer,"res/background/graysurface.png");
    logo = loadTexture(gRenderer,"res/background/logo.png");
	//Load sprites

	mineTile = loadTexture(gRenderer,"res/tiles/mine.jpg");
    flagTile = loadTexture(gRenderer,"res/tiles/flag.jpg");
    uncoveredTile = loadTexture(gRenderer,"res/tiles/uncovered.jpg");
    Tile_0 = loadTexture(gRenderer,"res/tiles/0.jpg");
    Tile_1 = loadTexture(gRenderer,"res/tiles/1.jpg");
    Tile_2 = loadTexture(gRenderer,"res/tiles/2.jpg");
    Tile_3 = loadTexture(gRenderer,"res/tiles/3.jpg");
    Tile_4 = loadTexture(gRenderer,"res/tiles/4.jpg");
    Tile_5 = loadTexture(gRenderer,"res/tiles/5.jpg");
    Tile_6 = loadTexture(gRenderer,"res/tiles/6.jpg");
    Tile_7 = loadTexture(gRenderer,"res/tiles/7.jpg");
    Tile_8 = loadTexture(gRenderer,"res/tiles/8.jpg");
    playAgainGUI = loadTexture(gRenderer,"res/gui/playAgain.png");
    aboutButton = loadTexture(gRenderer,"res/gui/aboutButton.png");
    playButton = loadTexture(gRenderer,"res/gui/playButton.png");
    returnButton = loadTexture(gRenderer,"res/gui/returnButton.png");
    forwardButton = loadTexture(gRenderer,"res/gui/forwardButton.png");
    easyDifButton = loadTexture(gRenderer,"res/gui/Easy.png");
    normalDifButton = loadTexture(gRenderer,"res/gui/Normal.png");
    hardDifButton = loadTexture(gRenderer,"res/gui/Hard.png");
    SFXButtonOff = loadTexture(gRenderer,"res/gui/SFX_off.png");
    SFXButtonOn = loadTexture(gRenderer,"res/gui/SFX_on.png");
    musicButtonOff = loadTexture(gRenderer,"res/gui/muted.png");
    musicButtonOn = loadTexture(gRenderer,"res/gui/unmuted.png");
    gameFont = loadFont("res/font/DTM-Sans.ttf",20);
	//Load sound effects
	winner = Mix_LoadMUS( "res/sounds/winner.wav" );
	if( winner == NULL )
	{
		cout << "Failed to load winner sound effect! SDL_mixer Error: " << Mix_GetError() << endl;
		success = false;
	}

	loser = Mix_LoadWAV( "res/sounds/loser.wav" );
	if( loser == NULL )
	{
		cout << "Failed to load loser sound effect! SDL_mixer Error: " << Mix_GetError() << endl;
		success = false;
	}

	click = Mix_LoadWAV( "res/sounds/click.wav" );
	if( click == NULL )
	{
		cout << "Failed to load click sound effect! SDL_mixer Error: " << Mix_GetError() << endl;
		success = false;
	}
	backgroundMusic = Mix_LoadMUS("res/sounds/mainmusic.mp3");
	if( backgroundMusic == NULL )
	{
		cout << "Failed to load background music! SDL_mixer Error: " << Mix_GetError() << endl;
		success = false;
	}
	return success;
}
void close()
{
    SDL_DestroyTexture(gBackgroundTexture);
    SDL_DestroyTexture(gAboutTexture);
    SDL_DestroyTexture(gGraySurface);
	//Load sprites

	SDL_DestroyTexture(mineTile);
    SDL_DestroyTexture(flagTile);
    SDL_DestroyTexture(uncoveredTile);
    SDL_DestroyTexture(Tile_0);
    SDL_DestroyTexture(Tile_1);
    SDL_DestroyTexture(Tile_2);
    SDL_DestroyTexture(Tile_3);
    SDL_DestroyTexture(Tile_4);
    SDL_DestroyTexture(Tile_5);
    SDL_DestroyTexture(Tile_6);
    SDL_DestroyTexture(Tile_7);
    SDL_DestroyTexture(Tile_8);
    SDL_DestroyTexture(playAgainGUI);
    SDL_DestroyTexture(aboutButton);
    SDL_DestroyTexture(playButton);
    SDL_DestroyTexture(returnButton);
    SDL_DestroyTexture(easyDifButton);
    SDL_DestroyTexture(normalDifButton);
    SDL_DestroyTexture(hardDifButton);
    SDL_DestroyTexture(musicButtonOn);
    SDL_DestroyTexture(musicButtonOff);
    SDL_DestroyTexture(SFXButtonOn);
    SDL_DestroyTexture(SFXButtonOff);
    gBackgroundTexture = NULL;
    gAboutTexture = NULL;
    gGraySurface = NULL;
	mineTile = NULL;
    flagTile = NULL;
    uncoveredTile = NULL;
    Tile_0 = NULL;
    Tile_1 = NULL;
    Tile_2 = NULL;
    Tile_3 = NULL;
    Tile_4 = NULL;
    Tile_5 = NULL;
    Tile_6 = NULL;
    Tile_7 = NULL;
    Tile_8 = NULL;
    playAgainGUI = NULL;
    aboutButton = NULL;
    playButton = NULL;
    returnButton = NULL;
    easyDifButton = NULL;
    normalDifButton = NULL;
    hardDifButton = NULL;
    musicButtonOff = NULL;
    musicButtonOn = NULL;
    SFXButtonOff = NULL;
    SFXButtonOn = NULL;
    logo = NULL;
    Mix_FreeMusic( winner );
	Mix_FreeChunk( loser );
	Mix_FreeChunk( click );
	Mix_FreeMusic(backgroundMusic);
	winner = NULL;
	loser = NULL;
	click = NULL;
	backgroundMusic = NULL;
    TTF_CloseFont( gameFont );
    gameFont = NULL;
    SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;
    Mix_Quit();
	IMG_Quit();
	SDL_Quit();
}
