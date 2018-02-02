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
    cout<<"SDL Initialized!"<<nl;

    window = SDL_CreateWindow("Bat Gui", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr){
        cout<<"SDL_CreateWindow Error: "<<SDL_GetError()<<endl;
        SDL_Quit();
        return -3;
    }
    cout<<"Window Created!"<<nl;

    screen = SDL_GetWindowSurface(window);

    if (screen == nullptr){
        cout<<"SDL_GetWindowSurface Error: "<<SDL_GetError()<<endl;
        SDL_Quit();
        return -4;
    }
    cout<<"Got window!"<<nl;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == nullptr){
        cout<<"SDL_CreateRenderer Error: "<<SDL_GetError()<<endl;
        return -5;
    }

    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    cout<<"Renderer created!"<<nl;

    return 0;
}
