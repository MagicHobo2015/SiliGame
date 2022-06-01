/***********************************************************************************************************************
 *      Author: Joshua Land                                                                                            *
 *      Description: contains the game board and all the stuff that goes with it.                                      *
 *      Contact:    Joshua.Land6@gmail.com                                                                             *
 *                             INVADERS!                                                                               *
 **********************************************************************************************************************/
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "Player.h"
#include "Game.h"

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
    return true;
}

void Graphics::render(SDL_Surface *gameScreen)
{
    SDL_Texture *temp = SDL_CreateTextureFromSurface( this->gameRenderer, gameScreen);
    // Clear the renderer to draw the draw color.
    SDL_SetRenderDrawColor(gameRenderer, basicColor.r, basicColor.g, basicColor.b, basicColor.a);
    SDL_RenderClear(gameRenderer);

    // apply the texture
   SDL_RenderCopy(this->gameRenderer, temp, NULL, NULL);

    // Draw to the screen
    SDL_RenderPresent(gameRenderer);
}

// this frees up memory
void Graphics::clean()
{
    // DEBUGGING ONLY
    std::cout << "cleaning game" << std::endl;
    // in reverse order here
    SDL_DestroyRenderer( gameRenderer );
    gameRenderer = nullptr;
    SDL_DestroyWindow( mainWindow );
    mainWindow = nullptr;
    SDL_Quit();
}

// Constructor will init a graphics object
Game::Game()
{
    // create a graphics object.
    this->graphics = new Graphics();
    // init the graphics objects
    this->graphics->init();

    // load background
    this->stage = IMG_Load( file );
}

// this will create the player, and the enemies.
void Game::init()
{
    this->pOne = new Player();
}

Game::~Game()
{
    // clean up the graphics object
    graphics->clean();
    // TODO: clean the heap

    // clean up the texture
    SDL_DestroyTexture( optimizedStage );
    optimizedStage = nullptr;

    // clean up surface, i think the heap still has the surface TODO: figure this out
    stage = nullptr;
}

// all this does is check for quit condition..
void Game::handleEvent()
{
    SDL_Event event;
    if ( SDL_PollEvent( &event ) )
    {
        std::cout << event.type << std::endl;
        switch ( event.type )
        {
            case 768:
                pOne->setX(-10);
                std::cout << "pressed" << std::endl;
                break;

            case SDL_QUIT:
                this->stopRunning();
                break;

            default:
                break;
        }
    }
}

void Game::animationStep() 
{
    /*
    this function needs to move what needs moving, then draw everything to the surface, then call render from graphics to optimize and
    present. 
    */
    // TODO: some background stuff

    // draw the player to the surface
    this->pOne->draw( this->stage );

    // finally render it all.
    graphics->render( this->stage );

}