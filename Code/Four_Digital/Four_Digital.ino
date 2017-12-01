//www.elegoo.com
//2016.12.12

int latch=9;  //74HC595  pin 9 STCP
int clock=10; //74HC595  pin 10 SHCP
int data=8;   //74HC595  pin 8 DS
int trig=11; 
int echo=12;

long duration;
int distance;

unsigned char table[]=
{ 
  0x3f,//0
  0x06,//1
  0x5b,//2
  0x4f,//3
  0x66,//4
  0x6d,//5
  0x7d,//6
  0x07,//7
  0x7f,//8
  0x6f,//9
  0x77,//A
  0x7c,//B
  0x39,//C
  0x5e,//D
  0x79,//E
  0x71,//F
  0x00 //end
};

const byte digit[10] =
{
  B00111111, //0
  B00000110, //1
  B01011011, //2
  B01001111, //3
  B01100110, //4
  B01101101, //5
  B01111101, //6
  B00000111, //7
  B01111111, //8
  B01101111  //9
};
const int digitPins[4] = {4,5,6,7}; 
int digitBuffer[4] = {0};
int digitScan = 0, flag=0,  soft_scaler = 0;
;

void setup() {
  Serial.begin(9600);
  for(int i=0;i<4;i++){
    pinMode(digitPins[i],OUTPUT);
  }
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(latch,OUTPUT);
  pinMode(clock,OUTPUT);
  pinMode(data,OUTPUT);
}

void Ping(){
digitalWrite(trig, LOW);
delayMicroseconds(2);
digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig, LOW);
duration = pulseIn(echo, HIGH);
distance= duration*0.034/2;
Serial.println(distance);
}

void Display(unsigned char num){
  digitalWrite(latch,LOW);
  shiftOut(data,clock,MSBFIRST,table[num]);
  digitalWrite(latch,HIGH);
  
}

void updateDisp(){
  for(byte j=0; j<4; j++)  
    digitalWrite(digitPins[j], LOW);
 
  digitalWrite(latch, LOW);  
  shiftOut(data, clock, MSBFIRST, B11111111);
  digitalWrite(latch, HIGH);
 
  delayMicroseconds(100);
  digitalWrite(digitPins[digitScan], HIGH); 
 
  digitalWrite(latch, LOW);  
  if(digitScan==2)
    shiftOut(data, clock, MSBFIRST, ~(digit[digitBuffer[digitScan]] | B10000000)); //print the decimal point on the 3rd digit
  else
    shiftOut(data, clock, MSBFIRST, ~digit[digitBuffer[digitScan]]);
 
  digitalWrite(latch, HIGH);
  digitScan++;
  if(digitScan>3) digitScan=0; 
}


void loop() {
  Ping();
  digitBuffer[3] = (distance)/1000;
  digitBuffer[2] = ((distance)%1000)/100;
  digitBuffer[1] = ((distance)%100)/10;
  digitBuffer[0] = ((distance)%100)%10;
  updateDisp();
  delay(2);
}
