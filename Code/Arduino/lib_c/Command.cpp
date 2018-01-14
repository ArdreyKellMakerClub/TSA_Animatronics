#include "Arduino.h"
#include "Command.h"

/**
 * This class is a wrapper for a Digital I/0 pin on the arduino. It essentially gives the arduino an instruction, in the form of a pin
 * and an output, then executes that instruction. 
 * To see global variables and constants, as well as method declarations, see the Command.h file.
 */

/*
 * Default Command constructor, sets pin and output to values determined in Command.h
 */
Command::Command(){
  _pin = Command::DEFAULT_PIN;
  _output = Command::DEFAULT_OUTPUT;

  analogMode = true;
}

/**
 * Creates a Command giving options of pin and analog output
 */
Command::Command(int pin, bool isAnalog){
  if(!isAnalog){  
    pinMode(pin, OUTPUT);
  }
  _pin = pin;
  _output = Command::DEFAULT_OUTPUT;
  
  this-> analogMode = isAnalog;
}

/**
 * The full command constructor, allowing a preferred output and pin to be set, along with 
 * analog and digital capability.
 */
Command::Command(int pin, int output, bool isAnalog){
  if(!isAnalog){  
    pinMode(pin, OUTPUT);
  }
  _output = output;
  _pin = pin;

  this->analogMode = isAnalog;
  
}

/**
 * The execution method of the command
 */
int Command::execute(){
  if(analogMode){
    analogWrite(_pin, _output);
  } else {
    digitalWrite(_pin, _output);
  }
  Serial.println("Executing Command...");
}

/**
 * Various getters and setters...
 */
int Command::getAttachedPin(){
  return _pin;
}

void Command::setAttachedPin(int pin){
  _pin = pin;
}

int Command::getAttachedOutput(){
  return _output;
}

void Command::setAttachedOutput(int output){
  _output = output;
}


