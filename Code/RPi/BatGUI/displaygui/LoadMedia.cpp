#include "displaygui.h"

SDL_Surface* LoadMedia(SDL_Surface* screen, string file){
    //load image
    SDL_Surface *temp = IMG_Load(file.c_str());
    if(temp == nullptr){
        cout<<"SDL_LoadBMP Error: "<<SDL_GetError()<<endl;
        SDL_Quit();
    }

    //optimize image
    SDL_Surface* image = SDL_ConvertSurface(temp, screen -> format, 0);
    if(image == NULL){
        cout<<"IMG_Load Error: "<<IMG_GetError()<<endl;
    }

    SDL_FreeSurface(temp);

    return image;
}
