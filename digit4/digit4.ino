#define digit1 6
#define digit2 3
#define digit3 2
#define digit4 12
#define ledA 5
#define ledB 13
#define ledC 10
#define ledD 8
#define ledE 7
#define ledF 4
#define ledG 11
#define ledH 9


#define zero affiche0()
#define un affiche1()
#define deux affiche2()
#define trois affiche3()
#define quatre affiche4()
#define cinq affiche5()
#define six affiche6()
#define sept affiche7()
#define huit affiche8()
#define neuf affiche9()

void setup() {
  pinMode(digit1 ,OUTPUT);
  pinMode(digit2 ,OUTPUT);
  pinMode(digit3 ,OUTPUT);
  pinMode(digit4 ,OUTPUT);
  pinMode(ledA ,OUTPUT);
  pinMode(ledB ,OUTPUT);
  pinMode(ledC ,OUTPUT);
  pinMode(ledD ,OUTPUT);
  pinMode(ledE ,OUTPUT);
  pinMode(ledF ,OUTPUT);
  pinMode(ledG ,OUTPUT);
 // pinMode(ledH ,OUTPUT);

  
  

}

void loop() {
  
  active_digit1();
  un;
  delay(2);
  active_digit2();
  deux;
  delay(2);
  active_digit3();
  trois;
  delay(2);
  active_digit4();
  quatre;
  delay(2);
 
 

}

void active_digit1(){
  digitalWrite(digit1, HIGH);
  digitalWrite(digit2, LOW);
  digitalWrite(digit3, LOW);
  digitalWrite(digit4, LOW);
}

void active_digit2(){
  digitalWrite(digit1, LOW);
  digitalWrite(digit2, HIGH);
  digitalWrite(digit3, LOW);
  digitalWrite(digit4, LOW);
}

void active_digit3(){
  digitalWrite(digit1, LOW);
  digitalWrite(digit2, LOW);
  digitalWrite(digit3, HIGH);
  digitalWrite(digit4, LOW);
}

void active_digit4(){
  digitalWrite(digit1, LOW);
  digitalWrite(digit2, LOW);
  digitalWrite(digit3, LOW);
  digitalWrite(digit4, HIGH);
}
void affiche0(){
  digitalWrite(ledA, LOW);
  digitalWrite(ledB, LOW);
  digitalWrite(ledC, LOW);
  digitalWrite(ledD, LOW);
  digitalWrite(ledE, LOW);
  digitalWrite(ledF, LOW);
  digitalWrite(ledG, HIGH);
  digitalWrite(ledH, LOW);
}

void affiche1(){
  digitalWrite(ledA, HIGH);
  digitalWrite(ledB, LOW);
  digitalWrite(ledC, LOW);
  digitalWrite(ledD, HIGH);
  digitalWrite(ledE, HIGH);
  digitalWrite(ledF, HIGH);
  digitalWrite(ledG, HIGH);
  digitalWrite(ledH, HIGH);
}

void affiche2(){
  digitalWrite(ledA, LOW);
  digitalWrite(ledB, LOW);
  digitalWrite(ledC, HIGH);
  digitalWrite(ledD, LOW);
  digitalWrite(ledE, LOW);
  digitalWrite(ledF, HIGH);
  digitalWrite(ledG, LOW);
  digitalWrite(ledH, LOW);
}

void affiche3(){
  digitalWrite(ledA, LOW);
  digitalWrite(ledB, LOW);
  digitalWrite(ledC, LOW);
  digitalWrite(ledD, LOW);
  digitalWrite(ledE, HIGH);
  digitalWrite(ledF, HIGH);
  digitalWrite(ledG, LOW);
  digitalWrite(ledH, LOW);
}
void affiche4(){
  digitalWrite(ledA, HIGH);
  digitalWrite(ledB, LOW);
  digitalWrite(ledC, LOW);
  digitalWrite(ledD, HIGH);
  digitalWrite(ledE, HIGH);
  digitalWrite(ledF, LOW);
  digitalWrite(ledG, LOW);
  digitalWrite(ledH, LOW);
}
//void affiche5(){
//  digitalWrite(ledA, HIGH);
//  digitalWrite(ledB, LOW);
//  digitalWrite(ledC, HIGH);
//  digitalWrite(ledD, HIGH);
//  digitalWrite(ledE, LOW);
//  digitalWrite(ledF, HIGH);
//  digitalWrite(ledG, HIGH);
//  digitalWrite(ledH, LOW);
//}
//void affiche6(){
//  digitalWrite(ledA, HIGH);
//  digitalWrite(ledB, LOW);
//  digitalWrite(ledC, HIGH);
//  digitalWrite(ledD, HIGH);
//  digitalWrite(ledE, HIGH);
//  digitalWrite(ledF, HIGH);
//  digitalWrite(ledG, HIGH);
//  digitalWrite(ledH, LOW);
//}
//void affiche7(){
//  digitalWrite(ledA, HIGH);
//  digitalWrite(ledB, HIGH);
//  digitalWrite(ledC, HIGH);
//  digitalWrite(ledD, LOW);
//  digitalWrite(ledE, LOW);
//  digitalWrite(ledF, LOW);
//  digitalWrite(ledG, LOW);
//  digitalWrite(ledH, LOW);
//}
//void affiche8(){
//  digitalWrite(ledA, HIGH);
//  digitalWrite(ledB, HIGH);
//  digitalWrite(ledC, HIGH);
//  digitalWrite(ledD, HIGH);
//  digitalWrite(ledE, HIGH);
//  digitalWrite(ledF, HIGH);
//  digitalWrite(ledG, HIGH);
//  digitalWrite(ledH, LOW);
//}
//void affiche9(){
//  digitalWrite(ledA, HIGH);
//  digitalWrite(ledB, HIGH);
//  digitalWrite(ledC, HIGH);
//  digitalWrite(ledD, HIGH);
//  digitalWrite(ledE, LOW);
//  digitalWrite(ledF, HIGH);
//  digitalWrite(ledG, HIGH);
//  digitalWrite(ledH, LOW);
//}
