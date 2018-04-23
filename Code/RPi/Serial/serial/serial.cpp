#include "serial.h"

using namespace LibSerial;
using namespace std;


int Heartbeat(SerialStream&);

int main(){

    SerialStream stream;("/dev/ttyACM1");
    stream.Open("/dev/ttyACM1");
    stream.SetBaudRate(SerialStreamBuf::BAUD_9600);
    stream.SetCharSize(SerialStreamBuf::CHAR_SIZE_8 );
    stream.SetNumOfStopBits(1);
    stream.SetParity( SerialStreamBuf::PARITY_NONE ) ;

    int ping;
    int pong;

    //Heartbeat(stream);

    while (true){
        cin>>ping;
        stream<<ping;
        stream>>pong;
        cout<<pong<<nl;
    }
    return 0;
}

void setup(){

}

#include <chrono>
#include <thread>


using namespace std::chrono;
using namespace std::this_thread;


bool connected;
char status;

int Heartbeat(SerialStream& stream){
    for(int i = 0; i<5; i++){
        cout<<"Test "<<i<<" of 5"<<nl;
        stream<<'1';
        cout<<"Ping!"<<nl;
        sleep_for(milliseconds(500));
        stream>>status;
        cout<<status;
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
