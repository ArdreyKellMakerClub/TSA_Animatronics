
#include<Servo.h>
#include "SerialParser.h"

Servo bat[5];

SerialParser* sp;


void setup() {
  // put your setup code here, to run once:

  sp = new SerialParser();
  
}

void loop() {

 if(Serial.available() > 0){
    sp->recieveCommand();
    sp->executeNextCommand();
 }

}

