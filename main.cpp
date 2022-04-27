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
  GameBoard *game = new GameBoard();
  game->init();
  game->
 SDL_BlitSurface( game->getGameStage(), NULL, game->getGameSurface(), NULL);
  SDL_UpdateWindowSurface( game->getGameWindow() );
  SDL_Delay(2000);
  game->closeUp();

    return 0;
}

// https://github.com/dnivanthaka/sdl-game-development-lessons
