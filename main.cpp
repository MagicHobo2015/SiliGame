/***********************************************************************************************************************
 *      Author: Joshua Land                                                                                            *
 *      Description: This is just a space Invaders ripoff, Im just trying to learn basic graphics and oop concepts.    *
 *      Contact:    Joshua.Land6@gmail.com                                                                             *
 *                             INVADERS!                                                                               *
 *  Big thanks to MillionthVector for posting this free spaceship, checkout his blog                                   *
 * @ http://millionthvector.blogspot.de                                                                                *
 **********************************************************************************************************************/
#include <iostream>
#include "Game.h"

int main( int argC, char** argV)
{

  Game *game = new Game();
  
  game->init();

  while( game->isRunning() )
  {
    game->handleEvent();
    game->animationStep();
  }
    return 0;
}

