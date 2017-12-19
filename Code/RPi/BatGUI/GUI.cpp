#include <SDL2/SDL.h>
#include <stdio.h>
#include <SerialPort.h>
#include <SerialStream.h>
#include <SerialStreamBuf.h>>
#define STREAM "/dev/whatever"
#define PORT "/dev/whatever" //change in rpi

using namespace std;
using namespace LibSerial;

SerialStream rpi_stream;

void SerialSetup();


int main(){
    SerialSetup();

    return 0;
}

void SerialSetup(){
    rpi_stream.Open(PORT);
    rpi_stream.BaudRate( SerialStreamBuf::BAUD_9600 );    //arduino BAUD rate
    rpi_stream.SetNumOfStopBits(1);                       //arduino stop bits



}
