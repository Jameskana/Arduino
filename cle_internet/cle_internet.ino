#include <SoftwareSerial.h>
SoftwareSerial gsm(11,12);  //rx = 11 et tx = 12

#define ledBleueOn PORTB |= (1<<PORTB2)
#define ledVerteOn PORTB |= (1<<PORTB1)
#define ledRougeOn PORTB |= (1<<PORTB0)

#define ledBleueOff PORTB &=~ (1<<PORTB2)
#define ledVerteOff PORTB &=~ (1<<PORTB1)
#define ledRougeOff PORTB &=~ (1<<PORTB0)

char msg;


void setup() {
  Serial.begin(9600);  //Initialisation du port serie
  gsm.begin(9600);    //Initialisation cle internet
  while(!Serial) {};   //Attente de l'initialisation du port serie
  DDRB = 0x07;  //PB0 PB1 PB2 en sortie
  PORTB &=~ 0x07;   //PB0 = 0 , PB1 = 0, PB2 = 0
}

void loop() {
  if(Serial.available()){
   msg = Serial.read();
    gsm.print(msg);
  }

  if(gsm.available()){
    msg = gsm.read();
    Serial.print(msg);
    if(msg == 'r' || msg == 'R'){
      PORTB ^= 0x01;
    }else
    if(msg == 'g' || msg == 'G'){
      PORTB ^= 0x02;
    }else
    if(msg == 'b' || msg == 'B'){
      PORTB ^= 0x03;
    }
  }

}
