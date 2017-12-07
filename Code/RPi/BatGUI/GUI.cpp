#include <SDL2/SDL.h>
#include <stdio.h>
#include <SerialStream.h>

using namespace std;
using namespace LibSerial;

#define PORT "/dev/whatever" //change in rpi

SerialStream rpi;

void SerialSetup();

int main(){
    SerialSetup();

    return 0;
}

void SerialSetup(){
    rpi.Open(PORT);
    rpi.SetBaudRate(SerialStreamBuf::BAUD_9600);
    rpi.SetCharSize
}
