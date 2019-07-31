char code;
void setup() {
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial){}
  Serial.print("PORT INITIALISE");

}

void loop() {
  // put your main code here, to run repeatedly:
//  Serial.println("\nBonjour!!!");

//  Serial.println();
  if(Serial.available()){
   code = Serial.read();
//    
//    Serial.println(code);
//    delay(1000);
  
      
  
    if(code == 'v'){
        digitalWrite(13, HIGH);
        delay(1000);
        digitalWrite(13, LOW);
        delay(1000);
    }else
    if(code == 'r'){
        digitalWrite(12, HIGH);
        delay(1000);
        digitalWrite(12, LOW);
        delay(1000);
    }else
    if(code == 'b'){
        digitalWrite(11, HIGH);
        delay(1000);
        digitalWrite(11, LOW);
        delay(1000);
    }
  }

}
