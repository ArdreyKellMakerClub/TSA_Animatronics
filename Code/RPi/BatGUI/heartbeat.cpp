#include "heartbeat.h"

bool connected;
int status=1;

int heartbeat(SerialStream& stream){
    for(int i = 0; i<5; i++){
        stream<<1;
        stream>>status;
        if(status==0)
            connected = true;
        sleep_for(milliseconds(500));
    }

    if(!connected)
        return 1; //not connected
    return 0;
}
