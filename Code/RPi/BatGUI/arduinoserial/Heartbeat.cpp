#include <chrono>
#include <thread>

#include "arduinoserial.h"

using namespace std::chrono;
using namespace std::this_thread;


bool connected;
char status;

int Heartbeat(SerialStream& stream){
    for(int i = 0; i<5; i++){
        cout<<"Test "<<i<<" of 5"<<nl;
        stream<<'y';
        cout<<"Ping!"<<nl;
        sleep_for(milliseconds(500));
        stream.get(status);
        cout<<status<<nl;
        if(status == 1){
            cout<<"Pong!"<<endl;
            connected = true;
            break;
        }

    }

    if(!connected)
        return -1; //not connected
    return 0;
}
