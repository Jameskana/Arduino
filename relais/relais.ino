#define relais 13
void setup() {
  pinMode(relais, OUTPUT);
}

void loop() {
  digitalWrite(relais, HIGH);
  delay(5000);
  digitalWrite(relais, LOW);
  delay(5000);

}
