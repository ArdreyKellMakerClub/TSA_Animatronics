#ifndef BUTTON_H
#define BUTTON_H
#include "displaygui.h"
#include "TexWrap.h"

class Button : public TexWrap
{
    public:
        Button();
        virtual ~Button();
        void render(SDL_Renderer*);
        void setPos(int,int);
        int load(string, SDL_Renderer*);
        bool handleEvent(SDL_Event*);
        int getState();
    protected:
    private:
        SDL_Texture* buttonUnpressed, *buttonHighlighted, *buttonPressed;
        enum States{unpressed, highlighted, pressed};
        int state;
        SDL_Point position;
};

#endif // BUTTON_H
