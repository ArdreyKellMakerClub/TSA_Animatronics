#include <SDL2/SDL.h>
#include <stdio.h>
#include <SerialPort.h>
#include <SerialStream.h>

using namespace std;
using namespace LibSerial;

#define PORT "/dev/whatever" //change in rpi

SerialPort   rpi_port;
SerialStream rpi_stream;

void SerialSetup();


int main(){
    SerialSetup();

    return 0;
}

void SerialSetup(){
    rpi_port.Open(PORT);
    rpi_stream.Open(PORT);
}
