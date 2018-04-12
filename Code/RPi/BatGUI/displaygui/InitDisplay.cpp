#include "displaygui.h"

using namespace std;

int InitDisplay(SDL_Window*& window, SDL_Surface*& screen, SDL_Renderer*& renderer){
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0){
        cout<<"SDL_Init Error: "<<SDL_GetError()<<endl;
        return -1;
    }
    cout<<"SDL_Video initialized!"<<nl;

    window = SDL_CreateWindow("Bat Gui", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr){
        cout<<"SDL_CreateWindow Error: "<<SDL_GetError()<<endl;
        SDL_Quit();
        return -2;
    }
    cout<<"Window Created!"<<nl;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == nullptr){
        cout<<"SDL_CreateRenderer Error: "<<SDL_GetError()<<endl;
        return -3;
    }

    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    cout<<"Renderer created!"<<nl;

    screen = SDL_GetWindowSurface(window);
    if (screen == nullptr){
        cout<<"SDL_GetWindowSurface Error: "<<SDL_GetError()<<endl;
        SDL_Quit();
        return -4;
    }
    cout<<"Got window!"<<nl;

    int imgFlags = IMG_INIT_PNG;
    if( !(IMG_Init( imgFlags ) & imgFlags ) ){
        cout<<"SDL_Init Error: "<<SDL_GetError()<<endl;
        return -5;
    }
    cout<<"PNG loading enabled!"<<nl;

    if( Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0){
        cout<<"SDL_Mixer init error"<<nl;
    }

    if( TTF_Init() == -1 ){
        printf( "SDL_ttf error! SDL_ttf Error: %s\n", TTF_GetError() );
        return -6;
    }
    cout<<"TTF initialized!"<<nl;

    cout<<"SDL Initialized!"<<endl;

    return 0;
}
