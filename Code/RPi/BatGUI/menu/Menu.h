#ifndef MENU_H
#define MENU_H

#include <vector>

#include "displaygui.h"
#include "TexWrap.h"
#include "Button.h"

using namespace std;

class Menu
{
    public:
        Menu();
        virtual ~Menu();
        void render(SDL_Renderer* ren);
        void handleEvent(SDL_Event*);
        void close();
        void load();
    protected:
        vector<Button> buttons;
        vector<TexWrap> images;
        vector<TexWrap> text;
    private:
};

#endif // MENU_H
