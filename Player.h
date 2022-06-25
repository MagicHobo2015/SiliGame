// header guards
#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include "GameElement.h"

class Player : public GameElement
{
private:
    const char* playerPNG = "./assets/player_ship.png";
    SDL_Texture *playerTexture = nullptr;

public:
    // Default constructor
    Player();
    // create and set the position
    Player( int x, int y );
    // non-default w/ scaling
    Player( int x, int y, int width, int height );
    // set the image for the player
    void setTexture( SDL_Texture *texture );
    // the two over-rides
    void draw( SDL_Renderer *board ) override;
    void move() override;
};

#endif