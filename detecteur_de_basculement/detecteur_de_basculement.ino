char DO_Alert = 3;
char DI_Detecteur = 2;
void setup() {
  pinMode(DI_Detecteur, INPUT_PULLUP);

}

void loop() {
  boolean basculement = digitalRead(DI_Detecteur);
  if(basculement == true){
    tone(DO_Alert, 8869.8, 50);
    delay(100);
  }
  delay(1);

}
