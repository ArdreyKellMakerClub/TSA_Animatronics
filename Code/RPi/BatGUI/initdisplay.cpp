#include "displaygui.h"

using namespace std;

int initdisplay(SDL_Window* window, SDL_Surface* screen){
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        cout<<"SDL_Init Error: "<<SDL_GetError()<<endl;
        return -1;
    }

    window = SDL_CreateWindow("Bat Gui", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL){
        cout<<"SDL_CreateWindow Error: "<<SDL_GetError()<<endl;
        SDL_Quit();
        return -2;
    }
    screen = SDL_GetWindowSurface(window);

    return 0;
}
