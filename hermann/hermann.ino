void setup() {
  pinMode(13, OUTPUT);
  pinMode(9,OUTPUT);

}

void loop() {
  digitalWrite(13, HIGH);
  tone(9,1000,100);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
  
}
