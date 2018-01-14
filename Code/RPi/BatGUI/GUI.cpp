#include <SDL2/SDL.h>
#include <iostream>

#include "heartbeat.h"
#include "streamsetup.h"
//#include "displaygui.h"

#define STREAM "/dev/ttyACM0" //change in rpi

using namespace std;
using namespace LibSerial;

SerialStream rpi_stream;

char n;

SDL_Window *win = NULL;
SDL_Surface *scr, *img = NULL;
SDL_Renderer *ren = NULL;
SDL_Texture *tex = NULL;
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

int initdisplay();
int loadmedia();
void closedisplay();

int main(){
    //setup(STREAM , rpi_stream);
    //heartbeat(rpi_stream); //check connection

    cout<<"init status: "<<initdisplay()<<endl;

    cout<<"load status: "<<loadmedia()<<endl;

    SDL_BlitSurface( img, NULL, scr, NULL );
    SDL_UpdateWindowSurface(win);

    cout<<"Type \'n\' to quit"<<endl;

    while(n != 'n'){cin>>n;}

    closedisplay();
    //rpi_stream.Close();

    return 0;
}

int initdisplay(){
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        cout<<"SDL_Init Error: "<<SDL_GetError()<<endl;
        return 1;
    }

    win = SDL_CreateWindow("Bat Gui", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (win == nullptr){
        cout<<"SDL_CreateWindow Error: "<<SDL_GetError()<<endl;
        SDL_Quit();
        return 2;
    }
    scr = SDL_GetWindowSurface(win);

    return 0;
}

int loadmedia(){
    img = SDL_LoadBMP("images/output.bmp");
    if(img == nullptr){
        SDL_DestroyWindow(win);
        cout<<"SDL_LoadBMP Error: "<<SDL_GetError()<<endl;
        SDL_Quit();
        return 1;
    }

    return 0;
}

void closedisplay(){
    SDL_FreeSurface(img);
    img = NULL;

    SDL_DestroyWindow(win);
    win = NULL;

    SDL_Quit();
}
