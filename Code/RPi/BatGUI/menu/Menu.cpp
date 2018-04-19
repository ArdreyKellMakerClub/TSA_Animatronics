#include "Menu.h"

Menu::Menu()
{
    load();
}

Menu::~Menu()
{
    //dtor
}


void Menu::render(SDL_Renderer* ren){
    for (Button b : buttons)
        b.render(ren);
    for (TexWrap i : images)
        i.render(ren);
    for (TexWrap t : text)
        t.render(ren);
}

void Menu::handleEvent(SDL_Event*){

}

void Menu::close(){
    for (Button b : buttons)
        b.free();
    for (TexWrap i : images)
        i.free();
    for (TexWrap t : text)
        t.free();
}

void Menu::load(){

}
