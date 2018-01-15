#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "heartbeat.h"
#include "streamsetup.h"
#include "displaygui.h"

#define STREAM "/dev/ttyACM0" //change in rpi

using namespace std;
using namespace LibSerial;

SerialStream rpi_stream;

char n;

SDL_Window* win = NULL;
SDL_Surface* scr, *img = NULL;
SDL_Renderer* ren = NULL;
SDL_Texture* tex = NULL;

int main(){
    //setup(STREAM , rpi_stream);
    //heartbeat(rpi_stream); //check connection
    cout<<"init status: "<<initdisplay(win, scr)<<endl;
    cout<<"load status: "<<loadmedia(win, img, "images/output.bmp")<<endl;

    SDL_BlitSurface(img, NULL, scr, NULL );
    SDL_UpdateWindowSurface(win);

    bool quit = false;
    SDL_Event e;

    while(!quit){
        while(SDL_PollEvent(&e) !=0){
            if (e.type == SDL_QUIT)
                quit = true;
            SDL_BlitSurface(img, NULL, scr, NULL );
            SDL_UpdateWindowSurface(win);

        }
    }
    closedisplay(img, win);
    //rpi_stream.Close();

    return 0;
}
