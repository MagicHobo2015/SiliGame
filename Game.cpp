/***********************************************************************************************************************
 *      Author: Joshua Land                                                                                            *
 *      Description: contains the game board and all the stuff that goes with it.                                      *
 *      Contact:    Joshua.Land6@gmail.com                                                                             *
 *                             INVADERS!                                                                               *
 **********************************************************************************************************************/
#include "Game.h"
#include <iostream>
#include <SDL2/SDL.h>

// define a couple constants
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

Graphics::Graphics() {};

bool Graphics::init()
{
    // attempt to initialize SDL
    // TODO: ADD AUDIO TO INIT
    if ( SDL_Init( SDL_INIT_VIDEO) == 0) {


        // DEBUGGING ONLY
        std::cout << "SDL init success \n";
        
        
        
        // init the window
        mainWindow = SDL_CreateWindow("INVADERS!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if ( mainWindow != 0 ) {
            // DEBUGGING ONLY
            std::cout << "Window creation success \n";
            gameRenderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if ( gameRenderer != 0 ) {

                // DEBUGGING ONLY
                std::cout << "Renderer creation success \n";

                SDL_SetRenderDrawColor(gameRenderer, basicColor.r, basicColor.g, basicColor.b, basicColor.a);
            }
            else
            {
                // tells you why it could not create a renderer.
                std::cout << "Renderer init failed, because: \n\t" << SDL_GetError() << std::endl;
                return false;
            }
        }
        else
        {
            // tells why the window could not be created.
            std::cout << "window init fail: \n\t" << SDL_GetError() << std::endl;
            return false;
        }
    }
    else
    {
        // DEBUGGING ONLY
        std::cout << "SDL init fail \n\t" << SDL_GetError() << std::endl;

        return false;
    }
    // DEBUGGING ONLY
    std::cout << "Init success" << std::endl;

    this->isRunning = true;
    return true;
}

void Graphics::render(SDL_Texture *gameScreen)
{
    // Clear the renderer to draw the draw color.
    SDL_RenderClear(gameRenderer);

    // apply the texture
   SDL_RenderCopy(gameRenderer, gameScreen, NULL, NULL);

    // Draw to the screen
    SDL_RenderPresent(gameRenderer);
}
// all this does is check for quit condition..
void Graphics::handleEvent()
{
    SDL_Event event;
    if ( SDL_PollEvent( &event ) )
    {
        switch ( event.type )
        {
            case SDL_QUIT:
                this->isRunning = false;
                break;

            default:
                break;
        }
    }
}
// this frees up memory
void Graphics::clean()
{
    // DEBUGGING ONLY
    std::cout << "cleaning game" << std::endl;
    // in reverse order here
    SDL_DestroyRenderer( gameRenderer );
    gameRenderer = nullptr;
    SDL_DestroyTexture( toBeRendered );
    toBeRendered = nullptr;
    SDL_DestroyWindow( mainWindow );
    mainWindow = nullptr;
    SDL_Quit();
}
