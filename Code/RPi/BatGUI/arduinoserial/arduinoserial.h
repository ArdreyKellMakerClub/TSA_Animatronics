#ifndef ARDUINOSERIAL_H_INCLUDED
#define ARDUINOSERIAL_H_INCLUDED

#include <SerialStream.h>
#include <SerialStreamBuf.h>
#include <iostream>

using namespace LibSerial;
using namespace std;



int     StreamSetup (string, SerialStream&);
int     Heartbeat   (SerialStream&);
int     TrigPoll    (SerialStream&);

#endif // ARDUINOSERIAL_H_INCLUDED
