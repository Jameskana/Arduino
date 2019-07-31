void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial){}
  Serial.print("ATI");

}

void loop() {
  // put your main code here, to run repeatedly:
 // Serial.print("AT");
 // delay(1000);
 if(Serial.available()>0){
 // Serial.print("AT");
   char reponse = Serial.read();
 // Serial.print("\n");
  Serial.print(reponse);
 // delay(1000);
 }
 
//Serial.print("ATI");
//delay(1000);

}
