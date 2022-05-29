/***********************************************************************************************************************
 *      Author: Joshua Land                                                                                            *
 *      Description: This is just a space Invaders ripoff, Im just trying to learn basic graphics and oop concepts.    *
 *      Contact:    Joshua.Land6@gmail.com                                                                             *
 *                             INVADERS!                                                                               *
 *  Big thanks to MillionthVector for posting this free spaceship, checkout his blog                                   *
 * @ http://millionthvector.blogspot.de                                                                                *
 **********************************************************************************************************************/
#ifndef SILIGAME_PLAYER_H
#define SILIGAME_PLAYER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


class Player
{
private:
    const char* pSpriteSheet = "./images/playerShip/fighter.png";
    bool alive = true;
    int lives = 3;
    int points = 0;
    SDL_Rect personalBubble = {600, 1000, 200, 200};
    SDL_Surface *pImage = nullptr;
    
public:
    // the constructor is going to load the sprite sheet
    Player();
    // this is going to release the memory of the player sprite sheet, maybe play a sound
    ~Player();
    // mutator
    void increasePoints(int increase);
    void setX(int deltaX);
    // accessor
    int getPoints() { return this->points; }
    SDL_Rect* getRect() { return &personalBubble; }
    // this will draw the ship
    void draw(SDL_Surface *stage);
    // this will move the ship
    void movePlayer();
};

#endif