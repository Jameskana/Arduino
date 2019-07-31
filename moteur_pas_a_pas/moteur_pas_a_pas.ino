#include <Stepper.h>

int nbrePas = 48*64;
Stepper monMoteur(nbrePas, 9, 11, 10, 6);

void setup() {
  monMoteur.setSpeed(9);
  Serial.begin(115200);
  delay(200);

}

void loop() {
  if(Serial.available())
  {
    String req = Serial.readStringUntil('\r');
    if(req.equals("etat/1"))
    {
       monMoteur.step(1536);
    }
  }
 
 // monMoteur.step(-200);
 delay(100);

}
