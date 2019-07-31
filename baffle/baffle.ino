#define do 523.25
#define re 587.33 
#define mi 559.26
#define fa 698.46
#define sol 783.99
#define la 880
#define si 987.77 
#define doo 554.37
#define baffle 7

long portPotentiometre = A0;
float valeurPotentiometre;

void setup() {
  pinMode(baffle, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
  valeurPotentiometre = analogRead(portPotentiometre);
  valeurPotentiometre = (valeurPotentiometre * 5.06 )/1023;
  Serial.println(valeurPotentiometre);
  delay(1);

  
  tone(baffle, do, 500);
  delay(200);
  tone(baffle, do, 1000);
  delay(200);
  
  tone(baffle, sol, 500);
  
  delay(200);
  tone(baffle, sol, 1000);
  
  delay(500);
  
  tone(baffle, la, 1000);
  
  delay(200);
  tone(baffle, la, 1000);
  
  delay(200);
  
  tone(baffle, sol, 2000);
  
  delay(200);
  
  tone(baffle, fa, 500);
  
  delay(200);
  tone(baffle, fa, 1000);
  
  delay(200);
  
  tone(baffle, mi, 500);
  
  delay(200);
  tone(baffle, mi, 1000);
  
  delay(200);
  
  tone(baffle, re, 500);
  
  delay(200);
  tone(baffle, re, 1000);
  
  delay(200);
  
  tone(baffle, do, 2000);
  
  delay(2000);

}
