    #include <dht11.h>
    #define DHT11PIN 4 // broche DATA -> broche 4

    int capteurPIR = 3;
    int etatCapteurPIR = 0;
    int capteurFumee = 5;
    int etatCapteurFumee = 0;
    int led = 13;
    int boutonVentilateur = 12;
    int ventilateur = 11;
    int etatVentilateur = 0;
     
    dht11 DHT11;
     
    void setup()
    {
      Serial.begin(9600);
      pinMode(capteurPIR, INPUT);
      pinMode(capteurFumee, INPUT);
      pinMode(led, OUTPUT);
      pinMode(ventilateur, OUTPUT);
      pinMode(boutonVentilateur, INPUT);
      while (!Serial) {
        // wait for serial port to connect. Needed for native USB (LEONARDO)
      }
    }
     
    void loop()
    {
//      /*****************Temperature******************/
//      DHT11.read(DHT11PIN);
//      Serial.print("Température (°C): /");
//      Serial.println((float)DHT11.temperature, 2);
//
/***************capteur presence*******************/
     if(digitalRead(capteurPIR) == HIGH){
      digitalWrite(led, HIGH);
      Serial.println("presence detectee");
      delay(1000);
      }else {
        digitalWrite(led, LOW);
        Serial.println("presence no");
      }
/****************Ventilateur********************/
      if(digitalRead(boutonVentilateur) == LOW){
        if(etatVentilateur == 0){
          digitalWrite(ventilateur, HIGH);
          etatVentilateur = 1;
        }else{
          digitalWrite(ventilateur, LOW);
          etatVentilateur = 0;
          }
      }
/****************capteur de fumee**************/
        if(digitalRead(capteurFumee) == HIGH){
          if(etatCapteurFumee == 0){
            digitalWrite(led, HIGH);
            etatCapteurFumee = 1;
            Serial.println("flamme detectee");
          }  
          }else{
            if(etatCapteurFumee == 1){
            digitalWrite(led, LOW);
            etatCapteurFumee = 0;
            Serial.println("no flamme");
          }
       }
    }
