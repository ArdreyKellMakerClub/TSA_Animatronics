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
SDL_Rect stretchRect;

int main(){
    stretchRect.x = 0;
    stretchRect.y = 0;
    stretchRect.w = SCREEN_WIDTH;
    stretchRect.h = SCREEN_HEIGHT;

    StreamSetup(STREAM , rpi_stream);
    cout<<"are we connected?"<<nl;
    cout<<"connection status: "<<Heartbeat(rpi_stream)<<endl; //check connection

    InitDisplay(win, scr, ren);

    SDL_Surface* background = LoadMedia(scr, "images/background_placeholder.bmp");

    SDL_BlitScaled(background, NULL, scr, &stretchRect );
    SDL_UpdateWindowSurface(win);

    tex = LoadTexture(ren, "images/button/button_unpressed.bmp");

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

    CloseDisplay(scr, win);
    //rpi_stream.Close();

    return 0;
}
