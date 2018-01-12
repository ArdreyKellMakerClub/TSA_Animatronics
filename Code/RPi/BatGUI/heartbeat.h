#ifndef HEARTBEAT_H_INCLUDED
#define HEARTBEAT_H_INCLUDED

#include <stdio.h>
#include <SerialStream.h>
#include <SerialStreamBuf.h>
#include <iostream>

using namespace std;
using namespace LibSerial;

int heartbeat(SerialStream&);

#endif // HEARTBEAT_H_INCLUDED
