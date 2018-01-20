#include "arduinoserial.h"


using namespace LibSerial;

int StreamSetup(string addr, SerialStream& stream){
    stream.Open( addr );
    cout<<"Connection Opened!"<<nl;
    stream.SetBaudRate( SerialStreamBuf::BAUD_9600 );   //arduino BAUD rate
    cout<<"Baud Set!"<<nl;
    stream.SetNumOfStopBits(1);                         //arduino stop bits
    cout<<"Stop Bits Set!"<<endl;
    return 0;
}
