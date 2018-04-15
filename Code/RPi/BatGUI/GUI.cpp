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
std::stringstream timeText, timeText1, buttonStr; //in memory text stream

SerialStream rpi_stream;

const double PI = 3.14159265;
char n;

SDL_Window* win = NULL;
SDL_Surface* scr, *img = NULL;
SDL_Renderer* ren = NULL;
SDL_Texture* tex = NULL;

bool debug = false;

int main(){

    /*
    StreamSetup(STREAM , rpi_stream);
    cout<<"are we connected?"<<nl;
    cout<<"connection status: "<<Heartbeat(rpi_stream)<<endl; //check connection
    */

    InitDisplay(win, scr, ren);

    Button button = Button();
    button.TexWrap::load("images/button/button_unpressed.bmp", ren);

    Button buttonTest = Button();
    buttonTest.TexWrap::load("images/button/button_unpressed.bmp", ren);
    buttonTest.setPos(SCREEN_WIDTH/3, SCREEN_HEIGHT/2);

    TexWrap background = TexWrap();
    background.TexWrap::load("images/background_placeholder.bmp", ren);
    background.setDim(SCREEN_WIDTH, SCREEN_HEIGHT);

    TexWrap fpsText = TexWrap();
    TexWrap frameText = TexWrap();
    TexWrap buttonText = TexWrap();

    TTF_Font* font = TTF_OpenFont("font/cmunrm.ttf", 28);
    SDL_Color textColor = {0x22,0xFF,0x00,255};

    bool quit = false;
    SDL_Event e;

    long long frame = 0;

    fps.start();

    while(!quit){
        cap.start();
        while(SDL_PollEvent(&e) !=0){
            if (e.type == SDL_QUIT)
                quit = true;
            if(buttonTest.handleEvent(&e))
                buttonTest.setPos(rand()%(SCREEN_WIDTH-buttonTest.getWidth()), rand()%(SCREEN_HEIGHT-buttonTest.getHeight()));
            if(button.handleEvent(&e)){
                debug = !debug;
            }
        }


        float avgFPS = frame / ( fps.ticks() / 1000.f );
        if( avgFPS > 2000000 ){
            avgFPS = 0;
        }

        //Set text to be render
        timeText1.str(std::string());
        timeText1 <<"Frame: "<< frame;

        timeText.str(std::string());
        timeText << "FPS: "<< avgFPS;

        buttonStr.str(std::string());
        buttonStr<< "Button Status: ";
        switch(buttonTest.getState()){
            case 0:
                buttonStr<<"Unpressed";
                break;
            case 1:
                buttonStr<<"Highlighted";
                break;
            case 2:
                buttonStr<<"Pressed";
                break;
        }
        //render text
        if(fpsText.loadText( timeText.str(),font, textColor, 28, ren) * \
            frameText.loadText( timeText1.str(),font, textColor, 28, ren) * \
             buttonText.loadText( buttonStr.str(), font, textColor, 28, ren)<0){
            cout<<"Unable to disply frame info"<<nl;
        }

        //clear screen
        SDL_SetRenderDrawColor( ren, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( ren );

        //render textures
        background.render( 0, 0, ren );
        button.setPos( SCREEN_WIDTH/2 + 100*cos(frame*PI/120)-50, SCREEN_HEIGHT/5 + SCREEN_HEIGHT/6*sin(frame*PI/120));
        button.render( ren );
        buttonTest.render(ren);

        if(debug){
            fpsText.render( 10, 10, ren);
            frameText.render( 10, 40, ren);
            buttonText.render(10, 70, ren);
        }

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
