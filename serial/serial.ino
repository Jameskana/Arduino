int led = 13;
void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  if(Serial.available()){
    int data = Serial.read();
    if(data == 'A'){
     digitalWrite(led, HIGH);
     delay(2000);
    }else{
      digitalWrite(led, LOW);
    }
  }

}
