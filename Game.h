/***********************************************************************************************************************
 *      Author: Joshua Land                                                                                            *
 *      Description: Should bring it all together. all the things a game needs.                                        *
 *      Contact:    Joshua.Land6@gmail.com                                                                             *
 *                             TODO: Add game name here                                                                *
 **********************************************************************************************************************/

#ifndef SILIGAME_GAME_H
#define SILIGAME_GAME_H

#include <SDL2/SDL.h>

class Game
{
private:
    bool bRunning;
    SDL_Window* mPWindow;
    SDL_Renderer* mPRenderer;

public:
    Game();
    ~Game();

    void init();
    void render();
    void update();
    void handleEvent();
    void clean();
    bool running() { return this->bRunning; }
};
#endif //SILIGAME_GAME_H