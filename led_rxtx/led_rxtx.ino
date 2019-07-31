void setup() {
  // put your setup code here, to run once:
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  int nbreAleatoire = random(3)+11;       //Generer un  nombre aleatoire entre 11 et 13
  
  digitalWrite(nbreAleatoire, HIGH);
  delay(1000);
  digitalWrite(nbreAleatoire, LOW);
  delay(1000);

}
