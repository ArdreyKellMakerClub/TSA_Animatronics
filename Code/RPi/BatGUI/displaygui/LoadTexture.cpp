#include "displaygui.h"


SDL_Texture* LoadTexture(SDL_Renderer* renderer, string path){
    SDL_Texture* texture = NULL;

    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if(loadedSurface == nullptr){
        cout<<"Unable to load image "<<path.c_str()<<" : "<<IMG_GetError()<<nl;
    }

    texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    if(texture == nullptr){
        cout<<"Unable to create texture"<<path.c_str()<<" : "<<SDL_GetError()<<nl;
    }
    return texture;
}
