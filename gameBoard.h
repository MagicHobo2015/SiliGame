/***********************************************************************************************************************
 *      Author: Joshua Land                                                                                            *
 *      Description: contains the gamebord and all the stuff that goes with it.                                        *
 *      Contact:    Joshua.Land6@gmail.com                                                                             *
 *                             TODO: Add game name here                                                                *
 **********************************************************************************************************************/
#ifndef SILIGAME_GAMEBOARD_H
#define SILIGAME_GAMEBOARD_H

// region includes
#include <SDL2/SDL.h>
#include <iostream>
// endregion includes

class GameBoard {
private:
    // width and height of the gamescreen
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;
    SDL_Window* gameWindow = nullptr;
    // surface in the window
    SDL_Surface* gameSurface = nullptr;
    // Surface that I draw on
    SDL_Surface* gameStage = nullptr;

public:
    // initializes SDL and creates a window
    bool init();
    bool loadMedia();
    void closeUp();
    // some getters
    [[nodiscard]] int getScreenWidth() const;
    [[nodiscard]] int getScreenHeight() const;
    SDL_Window* getGameWindow();
    SDL_Surface* getGameSurface();
    SDL_Surface* getGameStage();
        };

#endif //SILIGAME_GAMEBOARD_H
