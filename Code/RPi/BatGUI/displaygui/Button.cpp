#include "Button.h"

Button::Button(){
    state = UNPRESSED;
}

Button::~Button(){
    free();
}
    //dtor
void Button::render(SDL_Renderer* ren){
    switch (state){
        case UNPRESSED:
            unpressed.render(ren);
            break;
        case HIGHLIGHTED:
            highlighted.render(ren);
            break;
        case PRESSED:
            pressed.render(ren);
            break;
    }
}

void Button::load(string path, SDL_Renderer* ren){
    unpressed = TexWrap();
    unpressed.load(path+"_unpressed.bmp", ren);

    highlighted = TexWrap();
    highlighted.load(path+"_highlighted.bmp", ren);

    pressed = TexWrap();
    pressed.load(path+"_highlighted.bmp", ren);
}

void Button::setPos(int x, int y){
    unpressed.setPos(x,y);
    highlighted.setPos(x,y);
    pressed.setPos(x,y);
}

bool Button::handleEvent(SDL_Event* e){
    if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP){
        int x,y;
        SDL_GetMouseState(&x, &y);
        bool inside = true;

        if(x<position.x)
            inside = false;
        else if (x>position.x+getWidth())
            inside = false;
        else if (y<position.y)
            inside = false;
        else if (y>position.y+getHeight())
            inside = false;

        if(!inside)
            state = UNPRESSED;
        else{
            switch(e->type){
                case SDL_MOUSEBUTTONDOWN:
                    state = PRESSED;
                    break;
                case SDL_MOUSEMOTION:
                    state = HIGHLIGHTED;
                    break;
                case SDL_MOUSEBUTTONUP:
                    state = HIGHLIGHTED;
                    return true;
                    break;
            }
        }
    }
    return false;
}

int Button::getState(){
    return state;
}
