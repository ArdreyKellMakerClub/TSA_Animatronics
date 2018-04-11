#include "TexWrap.h"


TexWrap::TexWrap(){ //default ctor
    width = 0;
    height = 0;
    texture = nullptr;
}


int TexWrap::load(string path, SDL_Renderer* ren){
    SDL_Surface* temp = IMG_Load(path.c_str());
    SDL_Texture* tempTex = nullptr;
    if(temp == nullptr){
        cout<<"Unable to load image %s! SDL_image Error: %s\n"<<path.c_str()<<IMG_GetError()<<nl;
        return -1;
    }
    else{//set colour cey
        SDL_SetColorKey(temp, SDL_TRUE, SDL_MapRGB(temp->format, 0xFF, 0xAA, 0xFF));
        tempTex = SDL_CreateTextureFromSurface(ren, temp);
        if( tempTex == NULL ){
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
            return -2;
        }
        else{
            width = temp->w;
            height = temp->h;

        }
        SDL_FreeSurface( temp );
    }
    texture = tempTex;

    return 1;
}

int TexWrap::loadText(string path, SDL_Color color, SDL_Renderer* ren){
    return 0;
}

TexWrap::~TexWrap()
{
    free();//dtor
}

void TexWrap::free(){

}

void TexWrap::render(int x, int y, SDL_Renderer* ren){
    SDL_Rect box = { x, y, width, height };
    SDL_RenderCopy( ren, texture, NULL, &box );
}

void TexWrap::setDim(int w, int h){
    width = w;
    height = h;

}

int TexWrap::getHeight(){
    return height;
}

int TexWrap::getWidth(){
    return width;
}
