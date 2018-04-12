#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <iostream>
#include <sstream>
#include <SDL2/SDL_mixer.h>

#include "arduinoserial/arduinoserial.h"
#include "displaygui.h"
#include "TexWrap.h"
#include "Button.h"
#include "FramerateCapper.h"

#define nl "\n"

#define STREAM "/dev/ttyACM0" //change in rpi

using namespace std;
using namespace LibSerial;

FramerateCapper fps, cap;   //timers
std::stringstream timeText; //in memory text stream

SerialStream rpi_stream;

char n;

SDL_Window* win = NULL;
SDL_Surface* scr, *img = NULL;
SDL_Renderer* ren = NULL;
SDL_Texture* tex = NULL;

int main(){

    /*
    StreamSetup(STREAM , rpi_stream);
    cout<<"are we connected?"<<nl;
    cout<<"connection status: "<<Heartbeat(rpi_stream)<<endl; //check connection
    */

    InitDisplay(win, scr, ren);

    Button button = Button();
    button.TexWrap::load("images/button/button_unpressed.bmp", ren);

    TexWrap background = TexWrap();
    background.TexWrap::load("images/background_placeholder.bmp", ren);
    background.setDim(SCREEN_WIDTH, SCREEN_HEIGHT);

    TexWrap fpsText = TexWrap();

    SDL_Color textColor = {0xFF,0,0,255};

    bool quit = false;
    SDL_Event e;

    int frame = 0;

    while(!quit){
        cap.start();
        while(SDL_PollEvent(&e) !=0){
            if (e.type == SDL_QUIT)
                quit = true;
        }

        SDL_Color textColor = {0,0xFF,0,255};
        TTF_Font* font = TTF_OpenFont("font/cmunrm.ttf", 28);

        //Set text to be render
        timeText.str(std::string());
        timeText << frame;

        //render text
        if(fpsText.loadText( timeText.str(),font, textColor, 28, ren)<0){
            cout<<"Unable to disply FPS"<<nl;
        }

        //clear screen
        SDL_SetRenderDrawColor( ren, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( ren );

        //render textures
        background.render( 0, 0, ren );
        button.render( 240, 190, ren );
        fpsText.render( 10, 10, ren);
        SDL_RenderPresent(ren);
        ++frame;

        //If frame finished early
        int frameTicks = cap.ticks();
        if( frameTicks < SCREEN_TICKS_PER_FRAME ){
            //Wait remaining time
            SDL_Delay( SCREEN_TICKS_PER_FRAME - frameTicks );
        }
    }

    CloseDisplay(scr, win);
    //rpi_stream.Close();

    return 0;
}
