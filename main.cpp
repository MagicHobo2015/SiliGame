/************************************************************************************************************
*   Author:     Joshua Land                                                                                 *
*   Description:    This is just a game that is heavily inspired by SPACE INVADERS and pitifully executed   *
*   FYI:    my first game without a tutorial, just using the sdl2 documentation and other references..      *
*              SPACE INVADERS LIKE GAME-----> SILIGAME                                                      *
*************************************************************************************************************/
#include <iostream>
#include "Graphics.h"
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

int main( int argC, char** argV )
{
    // stop the game flag
    bool quit = false;
    SDL_Event event;
    Graphics graphic = Graphics( SCREEN_WIDTH, SCREEN_HEIGHT );
    
    while( !quit )
    {
        // this clears the renderer
        graphic.loop();
        graphic.showRenderer();


        while( SDL_PollEvent( &event ) != 0 )
        {
            if( event.type == SDL_QUIT )
            {
                quit = true;
            }
        }

    }

    graphic.cleanUp();
    return 0;
}