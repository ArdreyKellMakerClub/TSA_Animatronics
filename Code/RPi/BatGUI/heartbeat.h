#ifndef HEARTBEAT_H_INCLUDED
#define HEARTBEAT_H_INCLUDED

#include <SerialStream.h>
#include <SerialStreamBuf.h>
#include <iostream>
#include <chrono>
#include <thread>

using namespace LibSerial;
using namespace std;
using namespace std::chrono;
using namespace std::this_thread;

int heartbeat(SerialStream&);

#endif // HEARTBEAT_H_INCLUDED
