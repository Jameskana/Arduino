#include <Servo.h>

Servo monServo;
int positionServo = 0;

void setup() {
  monServo.attach(9);
  monServo.write(positionServo);

}

void loop() {
  for(positionServo = 0; positionServo <= 180; positionServo++){
    monServo.write(positionServo);
    delay(15);
  }
  for(positionServo = 180; positionServo >= 0; positionServo--){
    monServo.write(positionServo);
    delay(15);
  }

}
