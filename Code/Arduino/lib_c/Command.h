#include "Arduino.h"
#ifndef Command_h
#define Command_h

class Command{
  public:

    static const int DEFAULT_PIN = 3;
    static const int DEFAULT_OUTPUT = 0;
    
    Command();
    Command(int pin, bool isAnalog);
    Command(int pin, int output, bool isAnalog);
    
    int execute();
    
    int getAttachedPin();
    void setAttachedPin(int pin);
    
    int getAttachedOutput();
    void setAttachedOutput(int output);
    
  private:
    int _pin;
    int _output;
    bool analogMode;

};

#endif
