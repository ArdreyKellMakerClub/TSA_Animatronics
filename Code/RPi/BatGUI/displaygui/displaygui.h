#ifndef DISPLAYGUI_H_INCLUDED
#define DISPLAYGUI_H_INCLUDED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#define nl "\n"

using namespace std;

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

int             InitDisplay     (SDL_Window*&, SDL_Surface*&, SDL_Renderer*&);
SDL_Surface*    LoadMedia       (SDL_Surface*, string);
void            CloseDisplay    (SDL_Surface*&, SDL_Window*&);

#endif // DISPLAYGUI_H_INCLUDED
