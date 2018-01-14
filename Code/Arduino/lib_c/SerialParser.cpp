#include "Arduino.h"
#include "SerialParser.h"
/**
 * This class was designed to parse a Command object from a serial input in the form of <pin>-<analog/digital output>
 * Using this, it is able to construct Commands to instruct the arduino. Furthermore, this class buffers ten commands, so that it can process them all at once,
 * by using a stack structure.
 * See the SerialParser.h file for function declarations and global variables.
 */

 /**
  * The constructor, which initializes the Serial stream to any application.
  */
SerialParser::SerialParser(){
  Serial.begin(9600);
  addLoc = 0;
}

/**
 * Reads the String data on the Serial buffer
 */
String SerialParser::readByteString(){
  if (Serial.available() > 0) {
    // read the incoming byte:
    delay(50);
    String ret;
    
    while(Serial.available() != 0)
      ret += (char) Serial.read();
      
    return ret;
  }

  return "NO DATA AT PORT";
}

/**
 * Reads the integer data on the Serial buffer, if any.
 */
int SerialParser::readByteInteger(){
  if (Serial.available() > 0) {
    // read the incoming byte:
    delay(50);
    
    int action = 0;
    
    while(Serial.available() != 0)
      action += ((int)Serial.read() - 48) * pow(10, Serial.available());

    return action;
    
  }

  return SerialParser::NO_DATA_PRESENT;
}

/**
 * Parses a Command String in the form discussed at the top, and sends it to the receiveCommand() method so that a command can be pushed to the stack.
 */
int SerialParser::parseAvailableBytes(){

 delay(50);
 
 if (Serial.available() > 0) {
    nextCommand[0] = 0;
    nextCommand[1] = 0;
    
    int retLoc = 0;    
    byte allBytes[6];
    int avSize = Serial.available();
    
    while(Serial.available() != 0){
      allBytes[retLoc++] = Serial.read();
    }
    
    int dashLoc = 0;
    
    for(int i = 0; i < avSize; i++){
      if(((char) allBytes[i]) == '-'){
        dashLoc = i;
      }
    }
    
    for(int i = 0; i < dashLoc; i++){
      int byt = (int) allBytes[i] - 48;  
      nextCommand[0] += (byt) * pow(10, dashLoc - 1 - i);
    }
    
    for(int i = dashLoc + 1; i < avSize; i++){
      int byt = (int) allBytes[i] - 48;
      nextCommand[1] += (byt) * pow(10, avSize-i-1);
    }
    
    if(dashLoc > 0 && dashLoc < avSize){
      return 1;
    } else {
      return SerialParser::NO_DATA_PRESENT;
    }
  }

  return SerialParser::NO_DATA_PRESENT;
}

/**
 * Used to communicate back to the main application.
 */
void SerialParser::sendData(String data){
  Serial.println(data);
}

/**
 * The method that pushes a parsed command to the stack.
 */
void SerialParser::recieveCommand(){
  if(this->parseAvailableBytes() != SerialParser::NO_DATA_PRESENT){
    Command toPush(this->nextCommand[0], this->nextCommand[1], true);
    this->pushCommand(toPush);
  }
  
}

/**
 * Used to create a command.
 */
Command SerialParser::createCommand(int pin, int output){
  Command toPush(pin, output);
  return toPush;
}

/**
 * This puts a command on the end of the stack.
 */
int SerialParser::pushCommand(Command command){
  if(addLoc >= 10){
    return 0;  
  } else {
    this->toExecute[addLoc++] = command;
    return 1;
  }
}

/**
 * Executes the next command on the stack.
 */
void SerialParser::executeNextCommand(){
  
  if(this->hasNextCommand()){
    this->toExecute[0].execute();

    addLoc--;
    
    for(int i = 1; i < 10; i++){
      this->toExecute[i - 1] = this->toExecute[i];
    }
  }
}

/**
 * If there are any commands on the stack, this will return true.
 */
bool SerialParser::hasNextCommand(){
  return addLoc > 0;
}




