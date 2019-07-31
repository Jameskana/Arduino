#include <Servo.h>

Servo monServo;
int positionServo = 90;

void setup() {
  Serial.begin(115200);
  delay(200);
  monServo.attach(5);
  monServo.write(positionServo);

}

void loop() {
    if(Serial.available())
  {
    String req = Serial.readStringUntil('\r');
    if(req.equals("etat/1"))
    {
        for(positionServo = 90; positionServo >= 0; positionServo--){
          monServo.write(positionServo);
          delay(15);
      }
      delay(1000);
       for(positionServo = 0; positionServo <= 90; positionServo++){
        monServo.write(positionServo);
        delay(15);
      }
//      delay(3000);
    }
  }
  

}
