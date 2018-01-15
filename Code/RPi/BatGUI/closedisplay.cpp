#include "displaygui.h"

void closedisplay(SDL_Surface*& image, SDL_Window*& window){
    SDL_FreeSurface(image);
    image = NULL;

    SDL_DestroyWindow(window);
    window = NULL;

    SDL_Quit();
}
