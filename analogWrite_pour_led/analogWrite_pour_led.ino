int potentiometre = A0;
int led = 3;
int valeurLue;
void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  valeurLue = analogRead(potentiometre);
  valeurLue = map(valeurLue, 0, 1023, 0, 240);
  Serial.println(valeurLue);
  analogWrite(led, valeurLue);
  

}
