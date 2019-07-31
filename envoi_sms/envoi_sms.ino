#include <SoftwareSerial.h>

SoftwareSerial gsm(11, 12);
int envoi = 0;

void setup() {
  Serial.begin(9600);
  gsm.begin(9600);
  pinMode(8, OUTPUT);
}

void loop() {
//  if(envoi == 0){
//    sendSms();
//    envoi = 1;
//  }
  if(Serial.available()){
    gsm.print(Serial.read());
  }

  if(gsm.available()){
    Serial.print(gsm.read());
    digitalWrite(8, HIGH);
    delay(1000);
    digitalWrite(8, LOW);
  }
}

void sendSms(){
  gsm.println("AT");
  delay(500);
  gsm.println("AT+CMGF=1");
  delay(500);
  gsm.println("AT+CMGS=\"+237694792879\"");
  delay(500);
  gsm.println("Bonjour le monde!!!");
  delay(100);
  gsm.println(0x1a);
  Serial.println("Message envoye");
  digitalWrite(8, HIGH);
  delay(100);
  digitalWrite(8, LOW);
}
