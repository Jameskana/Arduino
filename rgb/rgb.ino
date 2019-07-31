int r = 9;
int g = 10;
int b = 11;
void setup() {
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
}

void loop() {
  setColor(255, 0, 0);
  delay(2000);
  setColor(0, 255, 0);
  delay(2000);
  setColor(0, 0, 255);
  delay(2000);
  setColor(128, 0, 255);
  delay(2000);

}

void setColor(int rr, int gg, int bb){
  #ifdef COMMON_ANODE
  rr = 255 - rr;
  gg = 255 - gg;
  bb = 255 - bb;
  #endif
  analogWrite(r, rr);
  analogWrite(g, gg);
  analogWrite(b, bb);
  
}
