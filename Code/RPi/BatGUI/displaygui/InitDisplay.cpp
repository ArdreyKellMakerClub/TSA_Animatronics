#include "displaygui.h"

using namespace std;

int InitDisplay(SDL_Window*& window, SDL_Surface*& screen, SDL_Renderer*& renderer){
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        cout<<"SDL_Init Error: "<<SDL_GetError()<<endl;
        return -1;
    }
    cout<<"SDL_Video initialized!"<<nl;
    int imgFlags = IMG_INIT_PNG;
    if( !(IMG_Init( imgFlags ) & imgFlags ) ){
        cout<<"SDL_Init Error: "<<SDL_GetError()<<endl;
        return -2;
    }


    window = SDL_CreateWindow("Bat Gui", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr){
        cout<<"SDL_CreateWindow Error: "<<SDL_GetError()<<endl;
        SDL_Quit();
        return -3;
    }

    screen = SDL_GetWindowSurface(window);

    if (screen == nullptr){
        cout<<"SDL_GetWindowSurface Error: "<<SDL_GetError()<<endl;
        SDL_Quit();
        return -4;
    }

    return 0;
}
