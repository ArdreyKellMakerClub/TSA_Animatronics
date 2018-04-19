#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <iostream>
#include <sstream>
#include <SDL2/SDL_mixer.h>

#include "displaygui.h"
#include "TexWrap.h"
#include "Button.h"
#include "FramerateCapper.h"

#define nl "\n"

#define STREAM "/dev/ttyACM0" //change in rpi

using namespace std;

FramerateCapper fps, cap;   //timers
std::stringstream timeText, timeText1, buttonStr; //in memory text stream

const double PI = 3.14159265;
char n;

SDL_Window* win = NULL;
SDL_Surface* scr, *img = NULL;
SDL_Renderer* ren = NULL;
SDL_Texture* tex = NULL;

bool debug = false;

int main(){

    InitDisplay(win, scr, ren);

    Button button = Button();
    button.TexWrap::load("assets/images/button/button_unpressed.bmp", ren);

    Button buttonTest = Button();
    buttonTest.TexWrap::load("assets/images/button/button_unpressed.bmp", ren);
    buttonTest.TexWrap::setPos(SCREEN_WIDTH/3, SCREEN_HEIGHT/2);

    TexWrap background = TexWrap();
    background.TexWrap::load("assets/images/background_placeholder.bmp", ren);
    background.setDim(SCREEN_WIDTH, SCREEN_HEIGHT);
    background.setPos(0,0);

    TexWrap fpsText = TexWrap();
    fpsText.setPos(10,10);
    TexWrap frameText = TexWrap();
    frameText.setPos(10,40);
    TexWrap buttonText = TexWrap();
    buttonText.setPos(10,70);

    TTF_Font* font = TTF_OpenFont("assets/font/cmunrm.ttf", 28);
    SDL_Color textColor = {0x33,0xFF,0x00,255};

    Mix_Music* crystallineCalls = nullptr;
    Mix_Chunk* youSuffer = nullptr;

    crystallineCalls = Mix_LoadMUS("assets/audio/testMusic.mp3");
    youSuffer        = Mix_LoadWAV("assets/audio/testChunk.wav");

    bool quit = false;
    SDL_Event e;

    long long frame = 0;

    fps.start();

    while(!quit){
        cap.start();

        if(Mix_PlayingMusic()==0)
            Mix_PlayMusic(crystallineCalls,-1);

        while(SDL_PollEvent(&e) !=0){
            if (e.type == SDL_QUIT)
                quit = true;
            else if (e.type == SDL_KEYDOWN){
                if (e.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
                    quit = true;
            }
            else if(buttonTest.handleEvent(&e)){
                buttonTest.TexWrap::setPos(rand()%(SCREEN_WIDTH-buttonTest.getWidth()), \
                                  rand()%(SCREEN_HEIGHT-buttonTest.getHeight()));
                Mix_PlayChannel( -1, youSuffer, 0);

            }
            if(button.handleEvent(&e)){
                debug = !debug;
            }
        }

        //clear screen
        SDL_SetRenderDrawColor( ren, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( ren );

        //render textures
        background.render(ren);
        button.TexWrap::setPos( SCREEN_WIDTH/2 + 100*cos(frame*PI/120)-50, SCREEN_HEIGHT/5 + SCREEN_HEIGHT/6*sin(frame*PI/120));
        button.TexWrap::render( ren );
        buttonTest.TexWrap::render(ren);

        if(debug){
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

            //draw text
            if(fpsText.loadText( timeText.str(),font, textColor, 28, ren) * \
                frameText.loadText( timeText1.str(),font, textColor, 28, ren) * \
                 buttonText.loadText( buttonStr.str(), font, textColor, 28, ren)<0){
                cout<<"Unable to disply frame info"<<nl;
            }

            //render text
            fpsText.render(ren);
            frameText.render(ren);
            buttonText.render(ren);
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

    return 0;
}
