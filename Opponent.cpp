#include "Opponent.h"
#include <SDL2/SDL_image.h>

// This just calls the default super constructor and loads the image
// TODO: LOAD ONCE PER ALL ENEMIES and share pointers
Opponent::Opponent() : GameElement()
{
    SDL_Surface *loadingSurface = nullptr;
    loadingSurface = IMG_Load( "./alien.png" );

}

// This allows you change the starting position of the opponent
Opponent::Opponent( int x, int y ) : GameElement( x, y )
{
    SDL_Surface *loadingSurface = nullptr;
    loadingSurface = IMG_Load( "./alien.png" );
}

// This allows you to change the starting position and size
Opponent::Opponent( int x, int y, int width, int height ) : GameElement( x, y, width, height )
{
    // this allows scaling
    SDL_Surface *loadingSurface = nullptr;
    loadingSurface = IMG_Load( "./alien.png" );
}

void Opponent::setTexture( SDL_Texture *texture )
{
    this->opponentTexture = texture;
}

// this will draw the opponents image on an sdl surface
void Opponent::draw( SDL_Renderer *board )
{
    SDL_RenderCopy( board, this->opponentTexture, NULL, this->getRect() );    

}

// this will move the opponents around
void Opponent::move( SDL_Surface *board )
{
    // this is gonna do alot
        this->setX( this->getX() + 2 );
        this->setY( this->getY() + 2 );
}

