#include "TexWrap.h"


TexWrap::TexWrap(){ //default ctor
    width = 0;
    height = 0;
    texture = nullptr;
}


int TexWrap::load(string path, SDL_Renderer* ren){
    free();
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

int TexWrap::loadText(string text,TTF_Font* font, SDL_Color color, int ppt, SDL_Renderer* ren){
    //Get rid of preexisting texture
    free();

    //Render text surface
    SDL_Surface* textSurface = TTF_RenderText_Solid( font, text.c_str(), color );
    if( textSurface == NULL )
    {
        printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
        return -1;
    }
    else
    {
        //Create texture from surface pixels
        texture = SDL_CreateTextureFromSurface( ren, textSurface );

        if( texture == NULL )
            cout<<"Unable to create texture from rendered text! SDL Error: "<<SDL_GetError()<<endl;
        else{
            //Get image dimensions
            width = textSurface->w;
            height = textSurface->h;
        }

        //Get rid of old surface
        SDL_FreeSurface( textSurface );
    }

    //Return success
    return 0;
}


TexWrap::~TexWrap()
{
    free();//dtor
}

void TexWrap::free(){
    if(texture != nullptr){
        SDL_DestroyTexture( texture );
        width = 0;
        height = 0;
    }
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
