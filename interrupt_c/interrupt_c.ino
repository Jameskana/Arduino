#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main(){
  DDRB = 0x20;       //portB5 en sortie
  PORTB &=~ 0x20;       //portB5 <- 0
  DDRD &=~ 0x80;    //portD7 en entree
  PORTD = 0x80;   //activer pull-up
  /**********interrupt**********/
  cli();
  PCICR = 0x04;    //100 PCIE2
  PCMSK2 = 0x80;        //PCINT23
  sei();
  
  while(1){
    
  }

  return 0;
}

ISR(PCINT2_vect){
  PORTB |= 0x20;
  _delay_ms(100);
  PORTB &=~ 0x20;
}
