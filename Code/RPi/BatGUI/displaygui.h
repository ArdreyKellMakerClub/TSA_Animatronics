#ifndef DISPLAYGUI_H_INCLUDED
#define DISPLAYGUI_H_INCLUDED

#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

int initdisplay(SDL_Window*&, SDL_Surface*&);
int loadmedia(SDL_Window*, SDL_Surface*&, string);
void closedisplay(SDL_Surface*&, SDL_Window*&);


#endif // DISPLAYGUI_H_INCLUDED
//
