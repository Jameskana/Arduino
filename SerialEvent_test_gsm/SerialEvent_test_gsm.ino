/*
  Serial Event example

  When new serial data arrives, this sketch adds it to a String.
  When a newline is received, the loop prints the string and clears it.

  A good test for this is to try it with a GPS receiver that sends out
  NMEA 0183 sentences.

  NOTE: The serialEvent() feature is not available on the Leonardo, Micro, or
  other ATmega32U4 based boards.

  created 9 May 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/SerialEvent
*/
#include <SoftwareSerial.h>
SoftwareSerial Serial1(11, 12);

String inputString = "";         // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete

void setup() {
  pinMode(8, OUTPUT);
  // initialize serial:
  Serial.begin(9600);
   Serial1.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
}

void loop() {
  // print the string when a newline arrives:
  if (stringComplete) {
    Serial1.println(inputString);
    // clear the string:
    inputString = "";
    stringComplete = false;
  }

  
  if(Serial1.available()){
  Serial.println(Serial1.read());
//    digitalWrite(8, HIGH);
//    delay(100);
//    digitalWrite(8, LOW);
    
    int inByte = Serial1.read();
     if(inByte == 'r' || inByte == 'R'){
      PORTB |= 0x01;
    }else
    if(inByte == 'g' || inByte == 'G'){
      PORTB |= 0x02;
    }else
    if(inByte == 'b' || inByte == 'B'){
      PORTB |= 0x03;
    }
  }
}

/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run between each time loop() runs, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
*/
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
