#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <iostream>
#include <sstream>

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

    StreamSetup(STREAM , rpi_stream);
    cout<<"are we connected?"<<nl;
    cout<<"connection status: "<<Heartbeat(rpi_stream)<<endl; //check connection

    InitDisplay(win, scr, ren);

    Button button = Button();
    button.TexWrap::load("images/button/button_unpressed.bmp", ren);

    TexWrap background = TexWrap();
    background.TexWrap::load("images/background_placeholder.bmp", ren);
    background.setDim(SCREEN_WIDTH, SCREEN_HEIGHT);

    SDL_Color textColor = {0,0,0,255};

    bool quit = false;
    SDL_Event e;

    int frames = 0;
    fps.start();

    while(!quit){
        cap.start();
        while(SDL_PollEvent(&e) !=0){
            if (e.type == SDL_QUIT)
                quit = true;
        }

        //calculate and correct FPS
        float avgFPS = frames / ( fps.ticks() / 1000.f );
        if( avgFPS > 2000000 ){
            avgFPS = 0;
        }

        //Set text to be rendered
        timeText.str( "" );
        timeText << "Average Frames Per Second (With Cap) " << avgFPS;

        //render text
        if( !gFPSTextTexture.loadFromRenderedText( timeText.str().c_str(), textColor ) ){
            printf( "Unable to render FPS texture!\n" );
        }

        //clear screen
        SDL_SetRenderDrawColor( ren, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( ren );

        //render textures
        background.render( 0, 0,ren );
        button.render( 240, 190,ren);

        SDL_RenderPresent(ren);
        ++frames;
    }

    CloseDisplay(scr, win);
    //rpi_stream.Close();

    return 0;
}
