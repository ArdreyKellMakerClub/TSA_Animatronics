#include <SDL2/SDL.h>
#include <iostream>
using namespace std;

int display(){
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        cout<<"SDL_Init Error: "<<SDL_GetError()<<endl;
        return 1;
    }

    SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    if (win == nullptr){
        cout<<"SDL_CreateWindow Error: "<<SDL_GetError()<<endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == nullptr){
        SDL_DestroyWindow(win);
        cout<<"SDL_CreateRenderer Error: "<<SDL_GetError()<<endl;
        SDL_Quit();
        return 2;
    }

    SDL_Quit();
    return 0;
}
