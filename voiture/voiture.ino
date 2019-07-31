#include <Servo.h>
#define avance digitalWrite(10, HIGH);
#define recule digitalWrite(11, HIGH);

Servo monServo;
int positionServo = 90;

void setup() {
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  monServo.attach(9);
  monServo.write(positionServo);

}

void loop() {

  for(int i = 0; i < 1000; i++){
   avance; 
  }
  delay(1000);
  stop();
  
  for(int i = 0; i < 1000; i++){
   recule;
  }
  delay(1000);
  stop();
  
  for(positionServo = 90; positionServo <= 100; positionServo++){
    monServo.write(positionServo);
    delay(15);
  }
  delay(1000);
  for(positionServo = 100; positionServo >= 80; positionServo--){
    monServo.write(positionServo);
    delay(15);
  }
  delay(1000);

}
void stop(){
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
}
