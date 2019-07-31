#include <avr/io.h>
#include <avr/interrupt.h>

volatile unsigned char cpt = 0;

int main(){
  
  DDRB |= 0x20;      //PORTB5 en output
  PORTB &=~ 0x20;     //PORTB5 <-0
  /**********Timmer2**************/
  cli();
  TCCR2A = 0x02;       //mode CTC
  OCR2A = 156;        //comparateur
  TCCR2B = 0x07;      //prescaler 1024
  TIMSK2 = 0x02;    //activer OCIEA
  sei();
  
  while(1){}
  
  return 0;
}

ISR(TIMER2_COMPA_vect){
  cpt++;
  if(cpt == 40)
     PORTB = 0b00100000;
     if(cpt == 50){
         PORTB &=~ 0b00100000;
         cpt = 0;
     }
}
