#include "Player.h"
#include <SDL2/SDL_image.h>
#include <iostream>


Player::Player() : GameElement()
{
    // activate the player
    this->setIsActive( true );
}

Player::Player( int x, int y ) : GameElement( x, y, 100, 100 )
{
    // set the starting pos, and activate the object
    this->setIsActive( true );
}

Player::Player( int x, int y, int width, int height ) : GameElement( x, y, width, height )
{
    // allows scaling and activates the object
    this->setIsActive( true );
}

void Player::setTexture( SDL_Texture *texture )
{
    this->playerTexture = texture;
}

void Player::draw( SDL_Renderer *board )
{
    // null is the src rectangle, TODO: update null with a src rect for sprite sheet
    SDL_RenderCopy( board, this->playerTexture, NULL, this->getRect() );
}

void Player::move() override
{
    // player movement is handled in the event section.
    std::cout << "Move" << std::endl;
    
}