/***********************************************************************************************************************
 *      Author: Joshua Land                                                                                            *
 *      Description: Two classes here, graphics class inits sdl and creates a texture for every thing else to use      *
 *                      The game class will bring all the elements of the game together                                *
 *      Contact:    Joshua.Land6@gmail.com                                                                             *
 *                             INVADERS!                                                                               *
 **********************************************************************************************************************/

#ifndef SILIGAME_GAME_H
#define SILIGAME_GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Player.h"

// this creates all the stuff sdl2 needs for rendering, other classes only the texture from here.
class Graphics
{
private:
    SDL_Color basicColor = { 0, 187, 255, 0 };
    // this is the main window
    SDL_Window *mainWindow = nullptr;
    // the renderer that everything will use to get drawn.
    SDL_Renderer *gameRenderer = nullptr;

public:
    // constructor and destructor just so i remember they are here.
    Graphics();
    ~Graphics();
    // this will initialize the window and renderer not the game elements.
    bool init();
    // this will draw the texture you give it.
    void render( SDL_Surface *gameScreen);
    
    // this frees up all the memory..Probably,
    void clean();
    // getter
    SDL_Renderer* getRenderer() { return this->gameRenderer; }
};


class Game
{
private:
    const char* file = "./images/backGrounds/two.jpg";
    // flag to tell if we should keep going
    bool running = true;
    // clear color, probably never see it.
    SDL_Color clearColor = { 0, 187, 255, 0 };
    
    // this is the surface that everything will be drawn on
    SDL_Surface *stage = nullptr;
    // after everything that needs to be is blited we can optimize
    SDL_Texture *optimizedStage = nullptr;

    // this is where all the sdl stuff resides
    Graphics *graphics = nullptr; 

    // One player object
    Player *pOne = nullptr;

public:

    // this will get the game ready
    Game();
    // this should free up the memory
    ~Game();

    void init();
    
    // setters
    void stopRunning() { this->running = false; }
    
    // getter
    bool isRunning() { return this->running; }
    // this just looks for quit condition right now.
    void handleEvent();
    // animation loop
    void animationStep();

};
#endif //SILIGAME_GAME_H
