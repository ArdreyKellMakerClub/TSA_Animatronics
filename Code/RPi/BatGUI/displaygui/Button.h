#ifndef BUTTON_H
#define BUTTON_H

#include <vector>

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
        vector<SDL_Texture*> textures;
        enum States{unpressed, highlighted, pressed};
        int state;
};

#endif // BUTTON_H
