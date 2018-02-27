#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "arduinoserial/arduinoserial.h"
#include "displaygui/displaygui.h"
#include "displaygui/TexWrap.h"

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

    StreamSetup(STREAM , rpi_stream);
    cout<<"are we connected?"<<nl;
    cout<<"connection status: "<<Heartbeat(rpi_stream)<<endl; //check connection

    InitDisplay(win, scr, ren);

    TexWrap button = TexWrap();
    button.TexWrap::load("images/button/button_unpressed.bmp", ren);

    TexWrap background = TexWrap();
    background.TexWrap::load("images/background_placeholder.bmp", ren);
    background.setDim(SCREEN_WIDTH, SCREEN_HEIGHT);

    bool quit = false;
    SDL_Event e;

    while(!quit){
        while(SDL_PollEvent(&e) !=0){
            if (e.type == SDL_QUIT)
                quit = true;
        }

        SDL_SetRenderDrawColor( ren, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( ren );
        background.render( 0, 0,ren );
        button.render( 240, 190,ren);
        SDL_RenderPresent(ren);
    }

    CloseDisplay(scr, win);
    //rpi_stream.Close();

    return 0;
}
