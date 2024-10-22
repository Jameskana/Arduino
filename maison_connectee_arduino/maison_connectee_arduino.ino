#include <SPI.h>
#include <RFID.h>
#include <Servo.h>
//declaration
    #include <dht11.h>
    #define DHT11PIN 4 // broche DATA -> broche 4

    int capteurPIR = 3;
    int etatCapteurPIR = 0;
    int capteurFumee = 2;
    int etatCapteurFumee = 0;
    int ledCouloir = A2;
    int boutonVentilateur = A3;
    int ventilateur = A1;
    int etatVentilateur = 0;
     
    dht11 DHT11;

//fin
Servo monServo;
Servo monServo2;
int positionServo = 90;

int boutonPorteGarage = A4;
int etatBoutonPorteGarage = 0;

int pinPhoto = A0;
int ledPhoto = 6; 
int etatLedPhoto = 0;


String message;

/* RST P9
 * SDA P10
 * MOSI P11
 * MISO P12
 * SCK P13
 * Rosette RFID                              235 7 131 116 27
 */
RFID monModuleRFID(10, 9);
int UID[5];
String code_rfid = "";
int buz = 7;

void setup() 
{
   pinMode(capteurPIR, INPUT);
      pinMode(capteurFumee, INPUT);
      pinMode(ledCouloir, OUTPUT);
      pinMode(ventilateur, OUTPUT);
      pinMode(boutonVentilateur, INPUT);
  pinMode(ledPhoto, OUTPUT);
  monServo.attach(5);
  monServo.write(positionServo);
  monServo2.attach(A5);
  monServo2.write(positionServo);
  Serial.begin(115200);
  SPI.begin();
  monModuleRFID.init();
  pinMode(buz, OUTPUT);

  pinMode(boutonPorteGarage, INPUT);

}
/*************************Boucle infinie***********************/
void loop()
{ 
  /*****************1ere action*************************/
   if(analogRead(A0) <= 75){
    if(etatLedPhoto == 0){
      digitalWrite(ledPhoto, HIGH);
      etatLedPhoto = 1;
      Serial.println("ledPhoto/on");
    }
   }else
    {
      if(etatLedPhoto == 1){
      digitalWrite(ledPhoto, LOW);
      etatLedPhoto = 0;
      Serial.println("ledPhoto/off");
    }
   }
  /************2eme action***********************************/
  if(monModuleRFID.isCard())
  {
    if(monModuleRFID.readCardSerial())
    {
       for(int i = 0; i < 5; i++)
      {
        UID[i] = monModuleRFID.serNum[i];
        code_rfid += UID[i];
      }
      String code_rfid2 = "ouvrirPorte/"+code_rfid;
      Serial.println(code_rfid2);
      code_rfid = "";
      delay(200);
       if((UID[0] == 221) && (UID[1] == 0) && (UID[2] == 232) && (UID[3] == 43) && (UID[4] == 30)){
         for(positionServo = 90; positionServo >= 0; positionServo--){
          monServo.write(positionServo);
          delay(15);
        }
         delay(5000);
        for(positionServo = 0; positionServo <= 90; positionServo++){
          monServo.write(positionServo);
          delay(15);
        }
       }else{
        for(int i = 0; i < 10; i++){
              sonner();
              delay(500);
            }
       }
    }
    monModuleRFID.halt();
  }
  /*****************************3eme action***************************/
  while(Serial.available()){
      message = Serial.readStringUntil('\r');   // On lit une chaine de caractere
      if(message.equals("code_rfid_ok")){
        for(positionServo = 90; positionServo >= 0; positionServo--){
          monServo.write(positionServo);
          delay(15);
        }
         delay(5000);
        for(positionServo = 0; positionServo <= 90; positionServo++){
          monServo.write(positionServo);
          delay(15);
        }
      }else
      if(message.equals("code_rfid_bad")){
         for(int i = 0; i < 10; i++){
              sonner();
              delay(500);
            }
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
      }else
      if(message.equals("ouvrirPorteGarage")){
         if(etatBoutonPorteGarage == 0)
            {
              for(positionServo = 90; positionServo >= 0; positionServo--){
                  monServo2.write(positionServo);
                  delay(15);
                }
                etatBoutonPorteGarage = 1;
                Serial.println("porteGarage/ouverte");
            }else
            {
              for(positionServo = 0; positionServo <= 90; positionServo++){
                  monServo2.write(positionServo);
                  delay(15);
                }
                etatBoutonPorteGarage = 0;
                Serial.println("porteGarage/fermee");
            }
            delay(200);
      }else
      if(message.equals("ventilateur/on")){
         if(etatVentilateur == 0)
            {
              digitalWrite(ventilateur, HIGH);
              etatVentilateur = 1;
            }else
            {
              digitalWrite(ventilateur, LOW);
              etatVentilateur = 0;
            }
            delay(200);
      }
   }
  
   if(digitalRead(boutonPorteGarage) == LOW)
   {
    if(etatBoutonPorteGarage == 0)
    {
      for(positionServo = 90; positionServo >= 0; positionServo--){
          monServo2.write(positionServo);
          delay(15);
        }
        etatBoutonPorteGarage = 1;
        Serial.println("porteGarage/ouverte");
    }else
    {
      for(positionServo = 0; positionServo <= 90; positionServo++){
          monServo2.write(positionServo);
          delay(15);
        }
        etatBoutonPorteGarage = 0;
        Serial.println("porteGarage/fermee");
    }
    delay(200);
   }
   /*********************debut code**********************/
      /*****************Temperature******************/
      DHT11.read(DHT11PIN);
//      Serial.print("Température (°C): /");
//      Serial.println((float)DHT11.temperature, 2);

/***************capteur presence*******************/
     if(digitalRead(capteurPIR) == HIGH){
      digitalWrite(ledCouloir, HIGH);
      Serial.println("presence/detectee");
      delay(1000);
      }else {
        digitalWrite(ledCouloir, LOW);
//        Serial.println("presence/no");
      }
/****************Ventilateur********************/
      if(digitalRead(boutonVentilateur) == LOW){
        if(etatVentilateur == 0){
          digitalWrite(ventilateur, HIGH);
          etatVentilateur = 1;
          Serial.println("ventilateur/on");
        }else{
          digitalWrite(ventilateur, LOW);
          etatVentilateur = 0;
          Serial.println("ventilateur/off");
          }
          delay(200);
      }
/****************capteur de fumee**************/
        if(digitalRead(capteurFumee) == HIGH){
          if(etatCapteurFumee == 0){
            for(int i = 0; i < 10; i++){
              sonner();
              delay(500);
            }
            etatCapteurFumee = 1;
            Serial.println("flamme/detectee");
          }  
          }else{
            if(etatCapteurFumee == 1){
            etatCapteurFumee = 0;
//            Serial.println("flamme/no");
          }else{
            etatCapteurFumee = 0;
          }
       }
/********************fin code*******************/
}
void sonner(){
  tone(buz, 2500, 200);
  delay(100);
  tone(buz, 1000, 200);
  delay(100);
}
