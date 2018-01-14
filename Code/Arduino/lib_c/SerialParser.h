#include "Arduino.h"
#include "Command.h"
#ifndef SerialParser_h
#define SerialParser_h

class SerialParser{
  public:
    SerialParser();

    static const int NO_DATA_PRESENT = -1;
    
    String readByteString();
    int readByteInteger();

    int parseAvailableBytes();

    void sendData(String data);

    void recieveCommand();
    Command createCommand(int pin, int output);
    
    int pushCommand(Command command);
    void executeNextCommand();

    bool hasNextCommand();
    
  private:
    Command toExecute[10];
    int addLoc = 0;

    int nextCommand[2];

};

#endif

