/***********************************************************************************************************************
 *      Author: Joshua Land                                                                                            *
 *      Description: The source file for  gameBoard Class. contains the game.                                          *
 *      Contact:    Joshua.Land6@gmail.com                                                                             *
 *                             TODO: Add game name here                                                                *
 **********************************************************************************************************************/
#include "gameBoard.h"
#include <iostream>
// Getters
int GameBoard::getScreenWidth() const { return this-> SCREEN_WIDTH; }
int GameBoard::getScreenHeight() const { return this-> SCREEN_HEIGHT; }
SDL_Window* GameBoard::getGameWindow() { return this->gameWindow; }
SDL_Surface *GameBoard::getGameSurface() { return SDL_GetWindowSurface(getGameWindow()); }
SDL_Surface *GameBoard::getGameStage() { return this->gameStage; }
// some real stuff
bool GameBoard::init()
{
    //Initialization flag
    bool success = true;
    // SDL_Window* gWindow = getGameWindow();
    // SDL_Surface* gScreenSurface = getGameSurface();

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Create window
        this->gameWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                    SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( getGameWindow() == nullptr )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Bind surface to window
            this->gameSurface = SDL_GetWindowSurface( getGameWindow() );
        }
    }

    return success;
}

// loads one image to stage, TODO: make it load whatever i want
bool GameBoard::loadMedia()
{
    bool success = true;
    // load the image to the stage
    this->gameStage = SDL_LoadBMP( "images/rider.bmp" );
    if( getGameStage() == nullptr ){
        // something went wrong print the error message.
        std::cout << "Unable to load image! sdl_error: " << SDL_GetError() << std::endl;
        success = false;
    }
    // img is loaded
    return success;
}

// cleans up the memory for stage and window
void GameBoard::closeUp()
{
    // free up stage
    SDL_FreeSurface(getGameStage() );
    this->gameStage = nullptr;
    // free up window
    SDL_DestroyWindow( this->gameWindow );
    this->gameWindow = nullptr;
    SDL_Quit();
}
