int led = 7;
int bouton = 6;
int etat;
void setup() {
  pinMode(led, OUTPUT);
  pinMode(bouton,INPUT);
  etat = LOW;
}

void loop() {
  etat=digitalRead(bouton);
  if(etat==LOW){
    digitalWrite(led, HIGH);
     delay(1000);
   }

     if(etat==HIGH){
    digitalWrite(led, LOW);
     delay(1000);
   }

}
