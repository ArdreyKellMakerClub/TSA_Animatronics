#ifndef MENU_H
#define MENU_H

#include <string>
#include <cmath>
#include <iostream>
#include <sstream>

#include "displaygui.h"
#include "FramerateCapper.h"
#include "TexWrap.h"
#include "Button.h"

using namespace std;

const double PI = 3.14159265;

enum states {START, MAIN, ECHO, POLLEN, FLIGHT, QUIT};


class Menu
{
    public:
        Menu();
        virtual ~Menu();
        void close();

        void handleEvent(SDL_Event*);
            void handleStartEvent(SDL_Event*);
            void handleMainEvent(SDL_Event*);
            void handleEchoEvent(SDL_Event*);
            void handlePollenEvent(SDL_Event*);
            void handleFlightEvent(SDL_Event*);

        void load(SDL_Renderer*);
            void loadStart(SDL_Renderer*);
            void loadMain(SDL_Renderer*);
            void loadEcho(SDL_Renderer*);
            void loadPollen(SDL_Renderer*);
            void loadFlight(SDL_Renderer*);

        void render(SDL_Renderer*);
            void renderStart(SDL_Renderer*);
            void renderMain(SDL_Renderer*);
            void renderEcho(SDL_Renderer*);
            void renderPollen(SDL_Renderer*);
            void renderFlight(SDL_Renderer*);

        bool quitFlag();
    protected:
        TTF_Font* font;
        SDL_Color textColor;
        int narrKey;

        //start
        Button start;

        //main
        Button echo, pollen, flight, quit;
        TexWrap echoIco, pollenIco, flightIco;
        Mix_Chunk* intro;

        //echo
        Button goBack;
        TexWrap diagram;
        Mix_Chunk* echo1, *echo2, *echoErr, *echoSucc1, *echoSucc2;
        Mix_Chunk* one, *two, *three, *four, *five, *six, *seven, *eight,  \
                   *nine, *ten, *eleven, *twelve, *thirteen, *fourteen,    \
                   *fifteen, *sixteen, *seventeen, *eighteen, *nineteen,   \
                   *twenty, *thirty, *fourty, *fifty, *sixty, *seventy,    \
                   *eighty, *ninety, *hundred;

        //pollen
        TexWrap banana, mango, guava;
        Mix_Chunk* pollenNarr;

        //flight
        TexWrap bat;
        Mix_Chunk* flap1, *flap2, *flap3, *flap4;

        Mix_Chunk* backNarr;

        //debug
        TexWrap frameText;
        TexWrap background;
        Mix_Chunk* batman;
        bool debug = false;
        long long frame = 0;
    private:
        int page;

};

#endif // MENU_H
