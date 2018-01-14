#include "displaygui.h"

using namespace std;

/*char n;

int initdisplay(){
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        cout<<"SDL_Init Error: "<<SDL_GetError()<<endl;
        return 1;
    }

    SDL_Window*win = SDL_CreateWindow("Hello World!", 100, 100, 480, 297, SDL_WINDOW_SHOWN);
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

    string imagePath = "images/output.bmp";
    SDL_Surface *bmp = SDL_LoadBMP(imagePath.c_str());
    if (bmp == nullptr){
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        cout<<"SDL_LoadBMP Error: "<<SDL_GetError()<<endl;
        SDL_Quit();
        return 3;
    }

    SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, bmp);
    SDL_FreeSurface(bmp);
    if (tex == nullptr){
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        cout << "SDL_CreateTextureFromSurface Error: "<<SDL_GetError()<<endl;
        SDL_Quit();
        return 4;
    }

    SDL_RenderCopy(ren, tex, NULL, NULL);
    SDL_RenderPresent(ren);

    while(n != 'n'){cin>>n;}

    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}
*/
