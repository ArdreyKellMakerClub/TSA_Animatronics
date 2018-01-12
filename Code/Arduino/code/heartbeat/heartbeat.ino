String s;
void setup(){
 Serial.begin(9600); 
}

void loop(){
    
    s = String(Serial.read());
    Serial.println(s);
}
