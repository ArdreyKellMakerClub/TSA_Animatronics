#include "SR04.h"
#include "LiquidCrystal.h"
#define TRIG_PIN 3
#define ECHO_PIN 4

SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  lcd.begin(16, 2);               //set up LCD with proper dimensions
  lcd.print("Distance: ");        //
}

void loop() {
  a=sr04.Distance();              //get distance
  lcd.setCursor(0, 1);            //set cursor back to home
  lcd.print("                ");  //  and then do a ghetto screen refresh
  lcd.setCursor(0, 1);            //set cursor back to home
  lcd.print(a);                   //  and print out distance
  lcd.print(" cm");               //  and print units
  delay(250);                     //refresh rate
}

