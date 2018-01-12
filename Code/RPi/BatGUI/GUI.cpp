#include <SDL2/SDL.h>
#include <stdio.h>
#include <SerialStream.h>
#include <SerialStreamBuf.h>
#include <iostream>
#include <SDL2/SDL.h>

#define PORT "/dev/ttyS0"
#define STREAM "/dev/ttyACM0" //change in rpi

using namespace std;
using namespace LibSerial;

SerialStream rpi_stream;
int setup(string, string);
int heartbeat();
//int display();

int something = 0;
string thing1;
string thing2;

int main(){
    setup(PORT, STREAM);
    //display();
    heartbeat();
    return 0;
}

int setup(string port, string stream){
    rpi_stream.Open( stream );
    rpi_stream.SetBaudRate( SerialStreamBuf::BAUD_9600 );   //arduino BAUD rate
    rpi_stream.SetNumOfStopBits(1);                         //arduino stop b

    return 0;
}

int heartbeat(){
    while(something<1000){
        cin >> thing1;
        rpi_stream <<  thing1 << endl;
        rpi_stream >> thing2;
        cout << thing2 << endl;
        something++;
    }
    return 0;
}
