#include <SoftwareSerial.h>

SoftwareSerial Serial1(2,3);

void setup() {
  // initialize both serial ports:
  Serial.begin(9600);
  Serial1.begin(9600);
  delay(1000);
}

void loop() {
  // read from port 1, send to port 0:
  while (Serial1.available()) {
    int inByte = Serial1.read();
    Serial.write(inByte);
  }
//
//  // read from port 0, send to port 1:
//  if (Serial.available()) {
//    int inByte = Serial.read();
//    Serial1.write(inByte);
//  }
Serial1.println("AT");
delay(2000);
Serial1.println("AT+CWMODE=3");
delay(1000);

}
