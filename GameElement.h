// some header guards
#ifndef GAME_ELEMENT_H
#define GAME_ELEMENT_H

#include <SDL2/SDL.h>

class GameElement
{
private:
    // this is here so i can change the size of these easily
    const int DEFAULT_SIZE = 150;
    // a flag to delete? or not to delete?
    bool isAlive_;
    // TODO: PIXLE PERFECT Colision 
    SDL_Rect personalSpace_;
    int speedX;
    int speedY;
    int directionX;
    int directionY;

public:
    GameElement();
    GameElement( int x, int y );
    GameElement( int x, int y, int width, int height );
    ~GameElement();
    // setters
    void setX( int x );
    void setY( int y );
    void setXSpeed( int xSpeed );
    void setYSpeed( int ySpeed );
    void setHorDir( int direction );
    void setIsActive( bool active );
    // getters
    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;
    bool getIsActive() const;
    int getSpeedX() const;
    int getSpeedY() const;
    int getDirectionX() const;
    int getDirectionY() const;
    SDL_Rect* getRect();
    // virtual stuff
    virtual void draw( SDL_Renderer *board ) = 0;

};
#endif