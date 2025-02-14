#include <SPI.h>
#include <RFID.h>
#include <Servo.h>

Servo monServo;
int positionServo = 90;

int pinPhoto = A0;
int ledPhoto = 6; 

int led3 =  4;      // the number of the LED pin
String message;
const int ventilateur = 2;

/* RST P9
 * SDA P10
 * MOSI P11
 * MISO P12
 * SCK P13
 * Rosette RFID                              235 7 131 116 27
 */
RFID monModuleRFID(10, 9);
int UID[5];
int buz = 7;
int ledBleue = 6;

void setup() 
{
  pinMode(ledPhoto, OUTPUT);
  monServo.attach(5);
  monServo.write(positionServo);
  Serial.begin(115200);
  SPI.begin();
  monModuleRFID.init();
  pinMode(buz, OUTPUT);
  pinMode(ventilateur, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(ledBleue, OUTPUT);

}
/*************************Boucle infinie***********************/
void loop()
{ 
  /*****************1ere action*************************/
   if(analogRead(A0) <= 75){
    digitalWrite(ledPhoto, HIGH);
    Serial.println("ledPhoto/on");
  }else{
    digitalWrite(ledPhoto, LOW);
    Serial.println("ledPhoto/off");
  }
  /************2eme action***********************************/
  if(monModuleRFID.isCard())
  {
    if(monModuleRFID.readCardSerial())
    {
       for(int i = 0; i < 5; i++)
      {
        UID[i] = monModuleRFID.serNum[i];
        Serial.print(UID[i], DEC);
        Serial.print(" ");
      }

      if((UID[0] == 221) && (UID[1] == 0) && (UID[2] == 232) && (UID[3] == 43) && (UID[4] == 30)){
        Serial.println("carteRFID/ok");
         for(positionServo = 90; positionServo >= 0; positionServo--){
          monServo.write(positionServo);
          delay(15);
        }
         delay(1000);
        for(positionServo = 0; positionServo <= 90; positionServo++){
          monServo.write(positionServo);
          delay(15);
        }
        delay(1000);
        
      }
      else
      {
        Serial.println("carteRFID/bad");
        tone(buz, 2500, 200);
        delay(100);
        tone(buz, 1000, 200);
        delay(100);
      }

    }
    monModuleRFID.halt();
  }
  /*****************************3eme action***************************/
  while(Serial.available()){
      message = Serial.readStringUntil('\r');   // On lit une chaine de caractere
      if(message.equals("led3/on")){
        digitalWrite(led3, HIGH);
      }else
      if(message.equals("led3/off")){
        digitalWrite(led3, LOW);
      }else
      if(message.equals("ventilateur/off")){
        digitalWrite(ventilateur, LOW);
      }else
      if(message.equals("ventilateur/on")){
        digitalWrite(ventilateur, HIGH);
      }else
      if(message.equals("ouvrirPorte")){
        for(positionServo = 90; positionServo >= 0; positionServo--){
          monServo.write(positionServo);
          delay(15);
        }
      }else
      if(message.equals("fermerPorte")){
         for(positionServo = 0; positionServo <= 90; positionServo++){
          monServo.write(positionServo);
          delay(15);
        }
      }
   }
}
