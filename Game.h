/***********************************************************************************************************************
 *      Author: Joshua Land                                                                                            *
 *      Description: Responsible for the renderer and nuts and bolts of init                                           *
 *      Contact:    Joshua.Land6@gmail.com                                                                             *
 *                             INVADERS!                                                                               *
 **********************************************************************************************************************/

#ifndef SILIGAME_GAME_H
#define SILIGAME_GAME_H

#include <SDL2/SDL.h>

class Game
{
private:

    // a flag for the game loop
    bool isRunning = true;
    // a default screen color
    SDL_Color basicColor = { 0, 187, 255, 0 };
    // this is the main window
    SDL_Window *mainWindow = nullptr;
    // the renderer that everything will use to get drawn.
    SDL_Renderer *gameRenderer = nullptr;
    // the stage surface 
    SDL_Surface *mainStage = nullptr;
    // off to render render land
    SDL_Texture *toBeRendered = nullptr;

public:
    // constructor and destructor just so i remember they are here.
    Game();
    ~Game();

    // this will initialize the window and renderer not the game elements.
    bool init();
    // this will draw the texture you give it.
    void render( SDL_Texture *gameScreen);
    // this just looks for quit condition right now.
    void handleEvent();
    // this frees up all the memory..Probably,
    void clean();
    // getter
    bool running() { return this->isRunning; }
    SDL_Texture* getGameScreen() { return this->gameScreen; }
    SDL_Renderer* getRenderer() { return this->gameRenderer; }
};
#endif //SILIGAME_GAME_H
