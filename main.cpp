/***********************************************************************************************************************
 *      Author: Joshua Land                                                                                            *
 *      Description: This is just a space Invaders ripoff, Im just trying to learn basic graphics and oop concepts.    *
 *      Contact:    Joshua.Land6@gmail.com                                                                             *
 *                             INVADERS!                                                                               *
 *  Big thanks to MillionthVector for posting this free spaceship, checkout his blog                                   *
 * @ http://millionthvector.blogspot.de                                                                                *
 **********************************************************************************************************************/
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "Game.h"

int main( int argC, char** argV)
{
  const char* file = "./images/backGrounds/two.jpg";
  SDL_Texture *background = nullptr;
  SDL_Surface *holder = nullptr;

  Game *game = new Game();
  game->init();

  holder = IMG_Load( file );
  background = SDL_CreateTextureFromSurface( game->getRenderer(), holder ); 
  
  
  game->render( backgorund );
  
  
  while(game->running())
  {
    game->handleEvent();
  }
  game->clean();
    return 0;
}

// https://github.com/dnivanthaka/sdl-game-development-lessons
