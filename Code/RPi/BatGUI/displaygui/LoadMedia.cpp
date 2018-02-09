#include "displaygui.h"
SDL_Surface* LoadMedia(SDL_Surface* screen, string file){
    //load image
    SDL_Surface* image = NULL;
    SDL_Surface* temp = SDL_LoadBMP(file.c_str());
    if(temp == nullptr){
        cout<<"IMG_Load Error: "<<SDL_GetError()<<endl;
        SDL_Quit();
    }


    //optimize image
    image = SDL_ConvertSurface(temp, screen -> format, NULL);
    if(image == NULL){
        cout<<"SDL Error: "<<IMG_GetError()<<endl;
    }

    SDL_FreeSurface(temp);

    return image;
}
