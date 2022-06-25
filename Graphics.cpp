#include "Graphics.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

Graphics::Graphics( int screenWidth, int screenHeight )
{
    // attempt to initialize SDL
    // TODO: ADD AUDIO TO INIT
    if ( SDL_Init( SDL_INIT_VIDEO) == 0) {


        // DEBUGGING ONLY
        std::cout << "SDL init success \n";
        
        // init the window
        this->window = SDL_CreateWindow("INVADERS!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
        if ( this->window != 0 ) {
            // DEBUGGING ONLY
            std::cout << "Window creation success \n";
            this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if ( this->renderer != 0 ) {

                // DEBUGGING ONLY
                std::cout << "Renderer creation success \n";

                SDL_SetRenderDrawColor(this->renderer, clearColor.r, clearColor.g, clearColor.b, clearColor.a);
            }
            else
            {
                // tells you why it could not create a renderer.
                std::cout << "Renderer init failed, because: \n\t" << SDL_GetError() << std::endl;
            }
        }
        else
        {
            // tells why the window could not be created.
            std::cout << "window init fail: \n\t" << SDL_GetError() << std::endl;
        }
    }
    else
    {
        // DEBUGGING ONLY
        std::cout << "SDL init fail \n\t" << SDL_GetError() << std::endl;
    }
    // DEBUGGING ONLY
    std::cout << "Init success" << std::endl;
}

Graphics::~Graphics()
{
    // nothing to do here
    std::cout << "Graphics object dead" << std::endl;
}

// creates textures from file you give it
SDL_Texture* Graphics::loadMedia( const char* path )
{
    // load the image
    this->loadingSurface = IMG_Load( path );

    // convert image to texture
    this->toBeReturned = SDL_CreateTextureFromSurface( this->renderer, this->loadingSurface );

    // clean up loading surface
    SDL_FreeSurface( this->loadingSurface );
    // clean it more
    loadingSurface = nullptr;
    // return the pointer to the image
    return toBeReturned;

}

// this frees up memory and un-initializes SDL
void Graphics::cleanUp()
{
    if ( this->loadingSurface != nullptr )
    {
        SDL_FreeSurface( this->loadingSurface );
    }
    if ( this->toBeReturned != nullptr )
    {
        SDL_DestroyTexture( toBeReturned );
        toBeReturned = nullptr;
    }

    SDL_DestroyRenderer( this->renderer );
    this->renderer = nullptr;
    SDL_DestroyWindow( this->window );
    this->window = nullptr;
    SDL_Quit();
}

void Graphics::loop()
{
    SDL_SetRenderDrawColor( this->renderer, this->clearColor.r, this->clearColor.g, this->clearColor.b, this->clearColor.a );
    SDL_RenderClear( this-> renderer );
}

SDL_Renderer* Graphics::getRenderer() const
{
    return this->renderer;
}

void Graphics::showRenderer() const
{
    SDL_RenderPresent( this->renderer );
}