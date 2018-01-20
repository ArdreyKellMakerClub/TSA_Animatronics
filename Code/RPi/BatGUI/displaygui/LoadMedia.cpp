#include "displaygui.h"

int /*SDL_Surface* */ LoadMedia(SDL_Surface*& image, SDL_Surface* screen, string file, int flag){
    //load image
    SDL_Surface *temp = IMG_Load(file.c_str());
    if(temp == nullptr){
        cout<<"SDL_LoadBMP Error: "<<SDL_GetError()<<endl;
        SDL_Quit();
        return -1;
    }

    //optimize image
    image = SDL_ConvertSurface(temp, screen -> format, 0);
    if(image == NULL){
        cout<<"IMG_Load Error: "<<IMG_GetError()<<endl;
        return -2;
    }

    //blit image; delete later?
    switch(flag){
        case 0:
            SDL_BlitSurface(image, NULL, screen, NULL );
        case 1:
            SDL_Rect stretchRect;
            stretchRect.x = 0;
            stretchRect.y = 0;
            stretchRect.w = SCREEN_WIDTH;
            stretchRect.h = SCREEN_HEIGHT;
            SDL_BlitScaled(image, NULL, screen, &stretchRect );
            break;
        }

    SDL_FreeSurface(temp);

    return 0; /*return image;*/
}
