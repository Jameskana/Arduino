#include <SoftwareSerial.h>

SoftwareSerial gsm(3, 2);

String inputString = "";         
bool stringComplete = false; 

char caractere;
void setup() {
  Serial.begin(9600);
  gsm.begin(9600);
  delay(1000);
  inputString.reserve(200);
}

void loop() {

 if (stringComplete) {
    gsm.println(inputString);
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
  
//  if(Serial.available()){
//    caractere = Serial.read();
//    delay(100);
//    gsm.println(caractere);
//  }

  if(gsm.available()){
    caractere = gsm.read();
    delay(100);
    Serial.print(caractere);    
  }

}

void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    inputString += inChar;
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
