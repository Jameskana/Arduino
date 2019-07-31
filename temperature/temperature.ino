int capteur = A0;

void setup() {
  Serial.begin(9600);

}

void loop() {
  int valeur = analogRead(capteur);
  float tension = valeur*5.0/1024;
  //float tension = map(valeur, 0, 1023, 0, 5);
  float temperature = (tension -0.5)* 100;
  Serial.println(temperature);

}
