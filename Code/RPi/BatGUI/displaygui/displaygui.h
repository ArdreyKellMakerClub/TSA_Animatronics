#ifndef DISPLAYGUI_H_INCLUDED
#define DISPLAYGUI_H_INCLUDED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

using namespace std;

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

int     InitDisplay     (SDL_Window*&, SDL_Surface*&);
int     LoadMedia       (SDL_Surface*&, SDL_Surface*, string, int);
void    CloseDisplay    (SDL_Surface*&, SDL_Window*&);

#endif // DISPLAYGUI_H_INCLUDED
