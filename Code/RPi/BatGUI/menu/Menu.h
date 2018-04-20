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

class Menu
{
    public:
        Menu();
        Menu(SDL_Renderer*);
        virtual ~Menu();
        void render(SDL_Renderer*, FramerateCapper, FramerateCapper);
        void handleEvent(SDL_Event*);
        void close();
        void load(SDL_Renderer*);

        void renderTest(SDL_Renderer*, FramerateCapper, FramerateCapper);
    protected:
        Button button, buttonTest;

        TexWrap fpsText, frameText, buttonText;
        TexWrap background;

        Mix_Chunk* youSuffer;

        bool debug = false;
        long long frame = 0;

        TTF_Font* font;
        SDL_Color textColor;
    private:
        int state = 5;
        enum states {start, main, echo, pollen, flight, test};
};

#endif // MENU_H
