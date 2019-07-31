#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>


const char pinIR=9;
IRrecv monRecepteur(pinIR);
decode_results messageRecu;


void setup() {
  // put your setup code here, to run once:
     Serial.begin(9600);
     monRecepteur.enableIRIn();
     monRecepteur.blink13(true);

}

void loop() {

    if(monRecepteur.decode(&messageRecu)){
      Serial.println(messageRecu.value,DEC);
      delay(500);
     // Serial.println(transcode(messageRecu));
   //   afficher(transcode(messageRecu));
      monRecepteur.resume();
 

    }
    delay(10);
 }
