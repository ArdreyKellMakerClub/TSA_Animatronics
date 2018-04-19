#include "Button.h"

Button::Button(){

}

Button::~Button(){
    free();
}
    //dtor
void Button::render(SDL_Renderer* ren){

}

int Button::load(string path, SDL_Renderer* ren){
    return 0;
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
            state = unpressed;
        else{
            switch(e->type){
                case SDL_MOUSEBUTTONDOWN:
                    state = pressed;
                    break;
                case SDL_MOUSEMOTION:
                    state = highlighted;
                    break;
                case SDL_MOUSEBUTTONUP:
                    state = highlighted;
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
