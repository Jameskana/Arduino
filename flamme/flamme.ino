int buzzer = 13;
int flamme = 12;
void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(flamme, INPUT);

}

void loop() {
  if(digitalRead(flamme)){
    tone(buzzer, 10, 1000);
  //  delay(1000); 
  }

}
