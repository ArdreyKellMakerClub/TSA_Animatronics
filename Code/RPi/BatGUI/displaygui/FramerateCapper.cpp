#include "FramerateCapper.h"

FramerateCapper::FramerateCapper()
{
    ticksFromStart = 0;
    ticksFromPause = 0;

    isStarted = false;
    isPaused  = false;
}

FramerateCapper::~FramerateCapper()
{
    //dtor
}

void FramerateCapper::start(){
    isStarted = true;
    isPaused = false;
    ticksFromStart=SDL_GetTicks();
    ticksFromPause=0;
}

void FramerateCapper::stop(){
    isStarted = false;
    isPaused = false;

    //clear tick variables
    ticksFromStart = 0;
    ticksFromPause = 0;
}

void FramerateCapper::pause(){
    if (isStarted && ! isPaused){
        isPaused = true;
        ticksFromPause = SDL_GetTicks() - ticksFromStart;
        ticksFromStart = 0;
    }
}

void FramerateCapper::resume(){
    if (isStarted && isPaused){
        isPaused = true;
        ticksFromStart = SDL_GetTicks() - ticksFromPause;
        ticksFromPause = 0;
    }
}

unsigned int FramerateCapper::ticks(){
    unsigned int time = 0;

    if(isStarted){
        if(isPaused)
            time = ticksFromPause;
        else
            time = SDL_GetTicks()-ticksFromStart;
    }
    return time;
}

int FramerateCapper::status(){
    if(isStarted){
        if(isPaused)
            return 0;   //paused
        return 1;       //started
    }
    return -1;          //not started`
}
