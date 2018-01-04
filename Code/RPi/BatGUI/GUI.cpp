#include <SerialPort.h>
#include <SerialStream.h>
#include <SerialStreamBuf.h>

#define STREAM "/dev/ttyS0"
#define PORT "/dev/ttyACM0" //change in rpi

using namespace LibSerial;


int main(){
    SerialPort rpi_port(PORT);
    SerialStream rpi_stream(STREAM);

    return 0;
}
