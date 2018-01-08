#include <SDL2/SDL.h>
#include <stdio.h>
#include <SerialStream.h>
#include <SerialStreamBuf.h>
#include <iostream>
#include <unistd.h>
#include <cstdlib>

#define STREAM "/dev/ttyS0"
#define PORT "/dev/ttyACM0" //change in rpi

using namespace std;
using namespace LibSerial;

void setup(string, string);
void heartbeat();

int main(){
    setup(PORT, STREAM);
    heartbeat();

    return 0;
}

void setup(string port, string stream){
    SerialStream rpi_stream;
    rpi_stream.Open( stream );
    rpi_stream.SetBaudRate( SerialStreamBuf::BAUD_9600 );   //arduino BAUD rate
    rpi_stream.SetNumOfStopBits(1);                         //arduino stop b
}
