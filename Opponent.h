// header guards
#ifndef OPPONENT_H
#define OPPONENT_H

#include <SDL2/SDL.h>
#include "GameElement.h"

class Opponent : public GameElement 
{
private:
    // this is where I will keep the enemy image
    SDL_Texture *opponentTexture = nullptr;

public:
    // Default constructor ( again probably not used much )
    Opponent();
    // non - Default change starting position
    Opponent( int x, int y );
    // non - Default change starting position /W scalling
    Opponent( int x, int y, int width, int height );

    void setTexture( SDL_Texture *texture );

    // the two overrides for elements
    void draw( SDL_Renderer *board ) override;
    void move( SDL_Surface *board ) override;
};

#endif

