#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

#define bouton 2
#define led 13
#define led2 9
#define capteurIR 8
int initial;
IRrecv monRecepteur(capteurIR);
decode_results code;
decode_results message;
#define pressButton digitalRead(bouton)== HIGH

void setup() {
  initial = 0;
  Serial.begin(9600);
  monRecepteur.enableIRIn();
 // monRecepteur.blink13(true);
  pinMode(bouton, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  if(monRecepteur.decode(&message)){
    Serial.println(message.value);
    if(initial == 0){
      code.value = message.value;
      initial = 1;
    }
      if(message.value==code.value){
         digitalWrite(led, HIGH);
       delay(1000);
      }else{
        digitalWrite(led, LOW);
      }
    delay(500);
    monRecepteur.resume();
  }
  if(pressButton){
    digitalWrite(led2, OUTPUT);
    delay(1000);
    digitalWrite(led2, LOW);
    initial = 0;
  }
  delay(1);
}
