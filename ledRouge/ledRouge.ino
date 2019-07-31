#define led 13
#define ledOn digitalWrite(led, HIGH)
#define pous 12
#define pousPress digitalRead(pous)== 1
#define ledOff digitalWrite(led, LOW)
void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(pous, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(digitalRead(pous) == 0 ){
    ledOn;
  }
  ledOff;
    

}
