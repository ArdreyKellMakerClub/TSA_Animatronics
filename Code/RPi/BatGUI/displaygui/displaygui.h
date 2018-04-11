#ifndef DISPLAYGUI_H_INCLUDED
#define DISPLAYGUI_H_INCLUDED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <iostream>

#define nl "\n"

using namespace std;

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
const int FRAMERATE = /*a cinematic*/ 24;
const int SCREEN_TICKS_PER_FRAME = 1000 / FRAMERATE;

int             InitDisplay(SDL_Window*&, SDL_Surface*&, SDL_Renderer*&);
SDL_Surface*    LoadMedia(SDL_Surface*, string);
void            CloseDisplay(SDL_Surface*&, SDL_Window*&);
SDL_Texture*    LoadTexture(SDL_Renderer*, string);
#endif // DISPLAYGUI_H_INCLUDED
