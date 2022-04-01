/***********************************************************************************************************************
 *      Author: Joshua Land                                                                                            *
 *      Description: contains the game board and all the stuff that goes with it.                                      *
 *      Contact:    Joshua.Land6@gmail.com                                                                             *
 *                             TODO: Add game name here                                                                *
 **********************************************************************************************************************/
#include "Game.h"
#include <iostream>

Game::Game() {};

bool Game::init(const char* title, int xPos, int yPos, int width, int height, int flags)
{
    // attempt to initialize SDL
    if ( SDL_Init( SDL_INIT_EVERYTHING ) == 0 ) {
        std::cout << "SDL init success \n";
        // init the window
        mPWindow = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
        if ( mPWindow != 0 ) {
            // window success
            std::cout << "Window creation success \n";
            mPRenderer = SDL_CreateRenderer(mPWindow, -1, 0);
            if ( mPRenderer != 0 ) {
                // renderer success
                std::cout << "Renderer creation success \n";
                SDL_SetRenderDrawColor(mPRenderer, 255, 255, 255, 255);
            }
            else
            {
                std::cout << "Renderer init fail \n";
                return false;
            }
        }
        else
        {
            std::cout << "window init fail \n";
            return false;
        }
    }
    else
    {
        std::cout << "SDL init fail \n";
        return false;
    }
    std::cout << "Init success" << std::endl;
    bRunning = true;

    SDL_Surface* tempSurface = SDL_LoadBMP("../images/rider.bmp");
    mPTexture = SDL_CreateTextureFromSurface(mPRenderer, tempSurface);
}

void Game::render()
{
    // Clear the renderer to draw the draw color.
    SDL_RenderClear(mPRenderer);

    // Draw to the screen
    SDL_RenderPresent(mPRenderer);
}

void Game::handleEvent()
{
    SDL_Event event;
    if ( SDL_PollEvent( &event ) )
    {
        switch ( event.type )
        {
            case SDL_QUIT:
                bRunning = false;
                break;

            default:
                break;
        }
    }
}

void Game::clean()
{
    std::cout << "cleaning game" << std::endl;
    SDL_DestroyWindow( mPWindow );
    SDL_DestroyRenderer( mPRenderer );
    SDL_Quit();
}

void Game::update() {};