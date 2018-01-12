#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL.h>

#include "heartbeat.h"
#include "streamsetup.h"

#define STREAM "/dev/ttyACM0" //change in rpi

using namespace std;
using namespace LibSerial;

SerialStream rpi_stream;

int main(){
    setup(STREAM , rpi_stream);
    //display();
    heartbeat(rpi_stream);
    return 0;
}

