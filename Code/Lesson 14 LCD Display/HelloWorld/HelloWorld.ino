#include "SR04.h"
#include <LiquidCrystal.h>
#define TRIG_PIN 3
#define ECHO_PIN 4
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Distance: ");
}

void loop() {
  a=sr04.Distance();
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print(a);
  lcd.print(" cm");
  delay(250);
}

