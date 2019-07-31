long portPotentiometre = A0;
float valeurPotentiometre;

void setup() {
  Serial.begin(9600);

}

void loop() {
  valeurPotentiometre = analogRead(portPotentiometre);
  valeurPotentiometre = (valeurPotentiometre * 5.06 )/1023;
  Serial.println(valeurPotentiometre);
  delay(1);

}
