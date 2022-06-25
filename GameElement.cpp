#include "GameElement.h"

// a default constructor, its here but probably wont be used much as the default values dont mean anything.
GameElement::GameElement()
{
    this->personalSpace_ =  { SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, DEFAULT_SIZE, DEFAULT_SIZE };
}

// set just the starting position use a default size for the size
GameElement::GameElement( int x, int y )
{
    this->personalSpace_ = { x, y, DEFAULT_SIZE, DEFAULT_SIZE };
}

// set the starting pos and size of this element when you create it
GameElement::GameElement( int x, int y, int width, int height )
{
    this->personalSpace_ = { x, y, width, height };
}

// one lame destructor needs to do something, maybe just call out that it was called...
GameElement::~GameElement() 
{
    // TODO: Figure out what this should do
}

// ************************* SETTERS ***********************************************************

void GameElement::setX( int x )
{
    this->personalSpace_.x = x;
}

void GameElement::setY( int y )
{
    this->personalSpace_.y = y;
}

void GameElement::setIsActive( bool active )
{
    this->isAlive_ = active;
}

void GameElement::setXSpeed( int xSpeed )
{
    this->speedX = xSpeed;
}

void GameElement::setYSpeed( int ySpeed )
{
    this->speedY = ySpeed;
}

// ******************************************************** GETTERS ************************************************

int GameElement::getX() const
{
    return this->personalSpace_.x;
}

int GameElement::getY() const
{
    return this->personalSpace_.y;
}

int GameElement::getWidth() const
{
    return this->personalSpace_.w;
}

int GameElement::getHeight() const
{
    return this->personalSpace_.h;
}

bool GameElement::getIsActive() const
{
    return this->isAlive_;
}

SDL_Rect* GameElement::getRect()
{
    return &personalSpace_;
}