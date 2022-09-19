//I, Aniket CHopra, student number 000814313, certify that this material 
//is my original work. No other person's work has been used without
// due acknowledgment and I have not made my work available to anyone else.

#include <Arduino.h> 
 
void setup() { 
  // configure the USB serial monitor 
  Serial.begin(115200); 
} 
 
void loop() { 
  int iVal; 
 
  // read digitized value from the D1 Mini's A/D convertor 
  iVal = analogRead(A0); 


  float V;
  int Temp;
  String judgement;
  V = (3.3/1023)*iVal;

  // Serial.println(V);
  Temp = (50/3.3)*V;
  
  
  
  if(Temp<10){
    judgement = "Cold!";
  }
  else if(Temp <15){
    judgement = "Cool";

  }
  else if(Temp<25){
    judgement = "Perfect";
  }
  else if(Temp<30){
    judgement = "Warm";
  }
  else if(Temp<35){
    judgement = "Hot";
  }
  else{
    judgement = "Too Hot!";
  }
 
 
  // print value to the USB port 
  Serial.println("Digitized Value of " + String(iVal) + " is equivalent to a temperature input of " + Temp + " deg. C, which is "+ judgement); 
 
  
  delay(2000); 
} 