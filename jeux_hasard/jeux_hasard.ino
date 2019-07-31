#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define ledBleueOn PORTB |= 0x08
#define ledRougeOn PORTB |= 0x10
#define ledVerteOn PORTB |= 0x20

#define ledBleueOff PORTB &=~ 0x08
#define ledRougeOff PORTB &=~ 0x10
#define ledVerteOff PORTB &=~ 0x20

volatile unsigned int win = 1;
volatile unsigned int nbre = 0;
int main(){
  
  DDRB |= 0x38;   //PB3 PB4 PB5 en sortie
  PORTB &=~ 0x38;   //PB3 = 0 PB4 = 0 PB5 = 0
  DDRD &=~ 0xE0;    //PD5 PD6 PD7 en entree
  PORTD |= 0xE0;     //PULL-UP sur PD5 PD6 PD7
  /***************Interruptions sur les PORTD5 PORTD6 PORTD7 *****************/
  cli();
  PCICR = 0x04;        // PCIE2
  PCMSK2 = 0xE0;   //PD5 PD6 PD7
  sei();

// volatile  unsigned byte nbre = generateur(11,13);
  
//  Serial.begin(9600);

  while(1){

//    ledVerteOn;
//    _delay_ms(100);
//    ledVerteOff;
//    ledRougeOn;
//    _delay_ms(100);
//    ledRougeOff;
//    ledBleueOn;
//    _delay_ms(100);
//    ledBleueOff;
    
//   if(win == nbre){
//       bravo();
//}
    
//Serial.println(generateur(1,3), DEC);
//_delay_ms(1000);
    
  }
  return 0;
}

void bravo(){
        allumerLed();
       _delay_ms(1000);
       eteintLed();
       _delay_ms(1000);
         allumerLed();
       _delay_ms(1000);
         eteintLed();
       _delay_ms(1000);
         allumerLed();
       _delay_ms(1000);
         eteintLed();
       _delay_ms(1000);
       nbre = 0;
}

void eteintLed(){
   ledVerteOff;
   ledRougeOff;
   ledBleueOff;
}

void allumerLed(){
   ledBleueOn;
   ledRougeOn;
   ledVerteOn;
}

//int generateur(int min, int max){
//  srand(time(NULL));
//  return rand()%(max-min+1) + min;
// // srand(time(NULL));
//}

void allumerLedGagnante(int nbre){
  if(nbre == 11) ledBleueOn;
  else if(nbre == 12) ledRougeOn;
  else if(nbre == 13)  ledVerteOn;
}

ISR(PCINT2_vect){
//  if(PIND != 0b11100000){
//     nbre = random(3) + 11;  //On genere un nombre aleatoire
//  eteintLed();  //On eteint toutes les led avant d'allumer la led gagnante
//  allumerLedGagnante(nbre);
 // _delay_ms(1000);
  
   if((~PIND & 0x80)== 0x80){
    ledVerteOn;
    _delay_ms(1000);
    ledVerteOff;
//     win = 13;
  }else
  if((~PIND & 0x40) == 0x40){
    ledRougeOn;
    _delay_ms(1000);
    ledRougeOff;
//    win = 12;
  }else
  if((~PIND & 0x20) == 0x20){
    ledBleueOn;
    _delay_ms(1000);
    ledBleueOff;
 //   win = 11;
  }
/*************verification de la victoire***************/
//if(win == nbre){
//  allumerLed();
//  _delay_ms(1000);
//}

//if(win == 11){
//   ledBleueOn;
//    _delay_ms(1000);
//}else
//if(win == 12){
//    ledRougeOn;
//    _delay_ms(1000);
//}else
//if(win == 13){
//    ledVerteOn;
//    _delay_ms(1000);
//}
//  }
 }
