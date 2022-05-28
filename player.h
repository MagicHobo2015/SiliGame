/***********************************************************************************************************************
 *      Author: Joshua Land                                                                                            *
 *      Description: This is just a space Invaders ripoff, Im just trying to learn basic graphics and oop concepts.    *
 *      Contact:    Joshua.Land6@gmail.com                                                                             *
 *                             INVADERS!                                                                               *
 *  Big thanks to MillionthVector for posting this free spaceship, checkout his blog                                   *
 * @ http://millionthvector.blogspot.de                                                                                *
 **********************************************************************************************************************/
#ifndef SILIGAME_GAMEELEMENT_H
#define SILIGAME_GAMEELEMENT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


class Player
{
private:
    int points;
    SDL_Rect *personalBubble = nullptr;
    
public:
    Player();
    ~Player();
    // mutator
    void increasePoints(int increase);
    // accessor
    int getPoints();
    // this will draw the ship
    void draw(SDL_Surface *stage);
    // this will move the ship
    void movePlayer()
}
#endif SILIGAME_GAMEELEMENT_H