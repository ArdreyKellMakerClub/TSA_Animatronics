#ifndef BUTTON_H
#define BUTTON_H

#include <vector>

#include "displaygui.h"
#include "TexWrap.h"


enum States{UNPRESSED, HIGHLIGHTED, PRESSED};

class Button : public TexWrap
{
    public:
        Button();
        virtual ~Button();
        void render(SDL_Renderer*);
        void setPos(int,int);
        void load(string, SDL_Renderer*);
        bool handleEvent(SDL_Event*);
        int getState();
    protected:
    private:
        TexWrap unpressed, highlighted, pressed;
        int state;
};

#endif // BUTTON_H
