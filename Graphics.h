#include <SDL2/SDL.h>
#include <string>

class Graphics
{
private:
    // the main window
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    // a temp loading surface
    SDL_Surface *loadingSurface = nullptr;
    // this is used to return pointers
    SDL_Texture *toBeReturned = nullptr;
    // clear color may not be relevant when there is a background
    SDL_Color clearColor = { 0 , 187, 255, 0 };
public:
    Graphics( int screenWidth, int screenHeight );
    ~Graphics();
    void loop();
    void cleanUp();
    void showRenderer() const;
    SDL_Renderer *getRenderer() const;
    SDL_Texture* loadMedia( const char* path );
};
