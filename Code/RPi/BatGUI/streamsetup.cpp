#include "streamsetup.h"

using namespace LibSerial;

int setup(string addr, SerialStream& stream){
    stream.Open( addr );
    stream.SetBaudRate( SerialStreamBuf::BAUD_9600 );   //arduino BAUD rate
    stream.SetNumOfStopBits(1);                         //arduino stop bits

    return 0;
}
