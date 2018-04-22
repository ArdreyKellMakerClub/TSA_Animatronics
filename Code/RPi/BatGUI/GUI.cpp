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
#include "menu/Menu.h"

#define nl "\n"

#define STREAM "/dev/ttyACM0" //change in rpi

using namespace std;

FramerateCapper fps, cap;   //timers
//std::stringstream timeText, timeText1, buttonStr; //in memory text stream

SDL_Window* win = NULL;
SDL_Surface* scr, *img = NULL;
SDL_Renderer* ren = NULL;
SDL_Texture* tex = NULL;

bool debug = false;

int main(){
    InitDisplay(win, scr, ren);

    Menu testMenu = Menu();

    testMenu.load(ren);

    bool quit = false;
    SDL_Event e;

    fps.start();
    long long frame = 0;

    while(!quit){
        cap.start();
        while(SDL_PollEvent(&e) !=0){
            if (e.type == SDL_QUIT)
                quit = true;
            else if (e.type == SDL_KEYDOWN){
                if (e.key.keysym.scancode == SDL_SCANCODE_ESCAPE || e.key.keysym.scancode==SDL_SCANCODE_GRAVE)
                    quit = true;
            }
            testMenu.handleEvent(&e);
            if(testMenu.quitFlag())
                quit = true;
        }

        SDL_RenderClear( ren );
        testMenu.render(ren);

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
