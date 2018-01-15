#include "displaygui.h"

int loadmedia(SDL_Window* window, SDL_Surface*& image, string file){
    image = SDL_LoadBMP(file.c_str());
    if(image == nullptr){
        SDL_DestroyWindow(window);
        cout<<"SDL_LoadBMP Error: "<<SDL_GetError()<<endl;
        SDL_Quit();
        return -1;
    }

    return 0;
}
