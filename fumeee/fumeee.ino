int led = 13;
int fumee = 12;
int state = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(fumee, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  state = digitalRead(fumee);
  if(state == HIGH){
    digitalWrite(led, HIGH);
  }else{
    digitalWrite(led, LOW);
  }

}
