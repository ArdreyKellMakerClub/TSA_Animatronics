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

enum states {START, MAIN, ECHO, POLLEN, FLIGHT, TEST, QUIT};


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
            void handleTestEvent(SDL_Event*);

        void load(SDL_Renderer*);
            void loadStart(SDL_Renderer*);
            void loadMain(SDL_Renderer*);
            void loadEcho(SDL_Renderer*);
            void loadPollen(SDL_Renderer*);
            void loadFlight(SDL_Renderer*);
            void loadTest(SDL_Renderer*);

        void render(SDL_Renderer*, FramerateCapper, FramerateCapper);
            void renderStart(SDL_Renderer*);
            void renderMain(SDL_Renderer*);
            void renderEcho(SDL_Renderer*);
            void renderPollen(SDL_Renderer*);
            void renderFlight(SDL_Renderer*);
            void renderTest(SDL_Renderer*, FramerateCapper, FramerateCapper);
        bool quitFlag();
    protected:
        TTF_Font* font;
        SDL_Color textColor;

        //start
        Button start;

        //main
        Button echo, pollen, flight, quit;
        TexWrap echoIco, pollenIco, flightIco;

        //info
        Button goBack;
        TexWrap diagram;
        TexWrap bat;
        TexWrap banana, mango, guava;

        //test
        Button button, buttonTest;
        TexWrap fpsText, frameText, buttonText;
        TexWrap background;
        Mix_Chunk* youSuffer;
        bool debug = false;
        long long frame = 0;
    private:
        int page;

};

#endif // MENU_H
