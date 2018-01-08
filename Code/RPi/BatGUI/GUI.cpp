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

int something = 0;
int dist;



int main(){
    SerialStream rpi_stream;
    rpi_stream.Open( STREAM );
    rpi_stream.SetBaudRate( SerialStreamBuf::BAUD_9600 );   //arduino BAUD rate
    rpi_stream.SetNumOfStopBits(1);                         //arduino stop bits

    while(something<1000){
        rpi_stream <<  'r';
        rpi_stream >> dist;
        cout << dist << endl;
        something++;
    }

    return 0;
}
