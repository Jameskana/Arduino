int fum = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(fum, INPUT);
  delay(500);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(fum));
  delay(200);

}
