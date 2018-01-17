#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "arduinoserial/arduinoserial.h"
#include "displaygui/displaygui.h"

#define nl "\n"

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
    //StreamSetup(STREAM , rpi_stream);
    //Heartbeat(rpi_stream); //check connection
    cout<<"init status: "<<InitDisplay(win, scr)<<nl;
    cout<<"load status: "<<LoadMedia(win, img, "images/output.bmp")<<nl;

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

    CloseDisplay(img, win);
    //rpi_stream.Close();

    return 0;
}
