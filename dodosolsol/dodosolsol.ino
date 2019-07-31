#define do 523.25
#define re 587.33 
#define mi 559.26
#define fa 698.46
#define sol 783.99
#define la 880
#define si 987.77 
#define doo 554.37
#define buzzer 13
#define led 12

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT); 

}

void loop() {
  // put your main code here, to run repeatedly:
  tone(buzzer, do, 500);
  digitalWrite(led, HIGH);
  delay(500);
  tone(buzzer, do, 1000);
  digitalWrite(led, HIGH);
  delay(500);
  
  tone(buzzer, sol, 500);
  digitalWrite(led, HIGH);
  delay(500);
  tone(buzzer, sol, 1000);
  digitalWrite(led, HIGH);
  delay(500);
  
  tone(buzzer, la, 1000);
  digitalWrite(led, HIGH);
  delay(500);
  tone(buzzer, la, 1000);
  digitalWrite(led, HIGH);
  delay(500);
  
  tone(buzzer, sol, 2000);
  digitalWrite(led, HIGH);
  delay(500);
  
  tone(buzzer, fa, 500);
  digitalWrite(led, HIGH);
  delay(500);
  tone(buzzer, fa, 1000);
  digitalWrite(led, HIGH);
  delay(500);
  
  tone(buzzer, mi, 500);
  digitalWrite(led, HIGH);
  delay(500);
  tone(buzzer, mi, 1000);
  digitalWrite(led, HIGH);
  delay(500);
  
  tone(buzzer, re, 500);
  digitalWrite(led, HIGH);
  delay(500);
  tone(buzzer, re, 1000);
  digitalWrite(led, HIGH);
  delay(500);
  
  tone(buzzer, do, 2000);
  digitalWrite(led, HIGH);
  delay(2000);

}
