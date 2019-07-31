
// constants won't change. They're used here to set pin numbers:
const int buttonPin = 12;     // the number of the pushbutton pin
const int ledPin =  4;      // the number of the LED pin
String message;


void setup() {
  //Init serial communication
  Serial.begin(115200);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // read the state of the pushbutton value:
  if(digitalRead(buttonPin) == LOW){
    if(digitalRead(ledPin) == LOW){
      digitalWrite(ledPin, HIGH);
     Serial.println("ledOn");
    }else
   if(digitalRead(ledPin) == HIGH){
      digitalWrite(ledPin, LOW);
     Serial.println("ledOff");
    }
  }

   while(Serial.available()){
      message = Serial.readStringUntil('\r');   // On lit une chaine de caractere
      if(message.equals("ledOn")){
        digitalWrite(ledPin, HIGH);
      }else
      if(message.equals("ledOff")){
        digitalWrite(ledPin, LOW);
      }
   }
      
  delay(100);
}
