#include <SPI.h>
#include <RFID.h>

RFID monModule(10, 9);
int numeroCard[5];

void setup() {
  Serial.begin(9600);
  SPI.begin();
  monModule.init();

}

void loop() {
  if(monModule.isCard()){
    if(monModule.readCardSerial()){
      Serial.print("L'UID est : ");
      for(int i = 0; i <= 4; i++){
        numeroCard[i] = monModule.serNum[i];
        Serial.print(numeroCard[i], DEC);
        Serial.print("  ");
      }
      Serial.println("");
      delay(2000);
    }
    monModule.halt();
  }
}
