//#include <boarddefs.h>
#include <IRremote.h>
//#include <IRremoteInt.h>
//#include <ir_Lego_PF_BitStreamEncoder.h>

const char pinIR = 2;
IRrecv monRecepteur(pinIR);
decode_results message_recu;

void setup() {
  Serial.begin(9600);
  monRecepteur.enableIRIn();
  monRecepteur.blink13(true);

}

void loop() {
  if(monRecepteur.decode(&message_recu)){
    Serial.println(message_recu.value, DEC);
    delay(500);
    monRecepteur.resume();
  }
  delay(1);
}
