/***********************************************************************************************************************
 *      Author: Joshua Land                                                                                            *
 *      Description: This is just a space Invaders ripoff, Im just trying to learn basic graphics and oop concepts.    *
 *      Contact:    Joshua.Land6@gmail.com                                                                             *
 *                             INVADERS!                                                                               *
 *  Big thanks to MillionthVector for posting this free spaceship, checkout his blog                                   *
 * @ http://millionthvector.blogspot.de                                                                                *
 **********************************************************************************************************************/
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Player.h"
// DEBUGGING ONLY
#include <iostream>

// the constructor loads the sprite sheet
Player::Player()
{
    // load the sprite sheet to the surface
    this->pImage = IMG_Load( pSpriteSheet );
    
    // check if it was done correctly
    if ( this->pImage != nullptr )
    {
        // DEBUGGING ONLY
        std::cout << "Player Sprite sheet init successful" << std::endl;

    } else
    {
        std::cout << "Something went wrong with the player SpriteSheet " << std::endl;
    }

}

Player::~Player()
{
    // DEBUGGING ONLY
    std::cout << "Cleaning up the player" << std::endl;

    SDL_FreeSurface( this->pImage );
    this->pImage = nullptr;
}

void Player::increasePoints(int points)
{
    this->points += points;
}

void Player::setX(int deltaX)
{
    this->personalBubble.x += deltaX;
}

// this draws the player on a surface.
void Player::draw(SDL_Surface *stage)
{
    SDL_BlitSurface( this->pImage, NULL, stage, &personalBubble );
}