int pinPhoto = A0;
int ledPhoto = 6;
int OFFSET = 950;
void setup() {
  Serial.begin(9600);
  pinMode(ledPhoto, OUTPUT);

}

void loop() {
  int valeurA0 = analogRead(pinPhoto);
  Serial.println(valeurA0);
  if(valeurA0 <= 75){
    digitalWrite(ledPhoto, HIGH);
  }else{
    digitalWrite(ledPhoto, LOW);
  }
//  int intensiteLed = 1023 - valeurA0;
//  intensiteLed = intensiteLed - OFFSET;
//  if(intensiteLed <= 0)
//  intensiteLed = 0;
//// // Serial.println(valeurA0, DEC);
//  Serial.println(intensiteLed);
//  analogWrite(ledPhoto, intensiteLed);
//  delay(1);
  

}
