int valeur;
void setup() {
  Serial.begin(9600);

}

void loop() {
  delay(500);
  valeur = analogRead(A0);
  Serial.println(valeur);
  
  

}
