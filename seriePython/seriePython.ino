
void setup() {
  // initialize both serial ports:
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);}

void loop() {
//  String req = client.readStringUntil('\r');
    String req = Serial.readStringUntil('\r');
    if(req.indexOf("ledRougeOn") != -1){
      digitalWrite(10, HIGH);
    }
     if(req.indexOf("ledVerteOn") != -1){
      digitalWrite(9, HIGH);
    }
     if(req.indexOf("ledBleuOn") != -1){
      digitalWrite(8, HIGH);
    }

    if(req.indexOf("ledRougeOf") != -1){
      digitalWrite(10, LOW);
    }
     if(req.indexOf("ledVerteOf") != -1){
      digitalWrite(9, LOW);
    }
     if(req.indexOf("ledBleuOf") != -1){
      digitalWrite(8, LOW);
    }
}
