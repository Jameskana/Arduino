#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile unsigned int cpt = 0;
int main(){
  Serial.begin(9600);
  cli();
  setTimer1CTC(4, 10000);   //prescaler 256  et periode 10000
  TIMSK1 = 0x02;        //OCIEA
  sei();

  while(1){
    _delay_ms(1000);
    Serial.println(cpt, DEC);
  }
}

void setTimer1CTC(byte CSB, int periode){
  TCCR1A = 0x04;    //Mode CTC
  OCR1A = periode;  //comparateur
  TCCR1B = 0x08;  //Initialisation prescaler
  TCCR1B |= (CSB & 0x07);  //prescaler
}

ISR(TIMER1_COMPA_vect){
  cpt++;
}
