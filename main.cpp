/***********************************************************************************************************************
 *      Author: Joshua Land                                                                                            *
 *      Description: TODO; Figure out what goes here..                                                                 *
 *      Contact:    Joshua.Land6@gmail.com                                                                             *
 *                             TODO: Add game name here                                                                *
 **********************************************************************************************************************/
#include <SDL2/SDL.h>
#include <iostream>
#include "gameBoard.h"

int main( int argC, char** argV)
{
    GameBoard game = GameBoard();
    if ( !game.init() ) {
        std::cout << "Failed to Initialize" << std::endl;
    }
    else {
        // load the image, to the stage
        if ( !game.loadMedia() ) {
            std::cout << "Failed to load Media" << std::endl;
        } else {
            // apply the img
            SDL_BlitSurface( game.getGameStage(), nullptr, game.getGameSurface(), nullptr);
            // Update the surface on the window
            SDL_UpdateWindowSurface( game.getGameWindow() );
            // wait
            SDL_Delay( 10000);
        }
    }
}
