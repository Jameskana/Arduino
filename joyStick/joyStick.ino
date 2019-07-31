int led;
int x;
int y;

void setup() {
  for(int i = 2; i <= 10; i++){
    pinMode(i, OUTPUT);
    Serial.begin(115200);
  }

}

void loop() {
  x = analogRead(A1);
  led = map(x, 0, 1023, 2, 10);
  Serial.println(led);
  digitalWrite(led, HIGH);
  delay(10);
  digitalWrite(led, LOW);

}
