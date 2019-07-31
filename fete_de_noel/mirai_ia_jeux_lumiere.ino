#define led1 2
#define led2 3
#define led3 4
#define led4 5

#define allume1 digitalWrite(led1, HIGH)
#define allume2 digitalWrite(led2, HIGH)
#define allume3 digitalWrite(led3, HIGH)
#define allume4 digitalWrite(led4, HIGH)

#define eteint1 digitalWrite(led1, LOW)
#define eteint2 digitalWrite(led2, LOW)
#define eteint3 digitalWrite(led3, LOW)
#define eteint4 digitalWrite(led4, LOW)
void setup() {
  pinMode(PIN_BUZZER,OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

}

void loop() {
  animation1();
  allumeAll();
  animation11();
  allumeAll();
  animation2();
  allumeAll();
  animation22();
  allumeAll();
  animation3();
  allumeAll();
  animation33();
  allumeAll();
  animation4();
  allumeAll();

}

void eteintAll(){
  eteint1;
  eteint2;
  eteint3;
  eteint4;
}
void allumeAll(){
  eteintAll();
  allume1;
  allume2;
  allume3;
  allume4;
}

void animation1(){
  for(int i = 0; i < 10; i++){
    eteintAll();
    allume1;
    delay(100);
    eteint1;
    allume2;
    delay(100);
    eteint2;
    allume3;
    delay(100);
    eteint3;
    allume4;
    delay(100);
    eteint4;
  }
}
void animation11(){
  for(int i = 0; i < 10; i++){
    eteintAll();
    allume4;
    delay(100);
    eteint4;
    allume3;
    delay(100);
    eteint3;
    allume2;
    delay(100);
    eteint2;
    allume1;
    delay(100);
    eteint1;
  }
  
}

void animation2(){
  for(int i = 0; i < 3; i++){
    eteintAll();
    allume1;
    delay(100);
    allume2;
    delay(100);
    allume3;
    delay(100);
    allume4;
    delay(100);
    eteintAll();
    delay(100);
  }
}
void animation22(){
  for(int i = 0; i < 3; i++){
    eteintAll();
    allume4;
    delay(100);
    allume3;
    delay(100);
    allume2;
    delay(100);
    allume1;
    delay(100);
    eteintAll();
    delay(100);
  }
}
void animation3(){
  for(int i = 0; i < 5; i++){
    eteintAll();
    allume1;
    allume3;
    delay(1000);
    eteintAll();
    allume2;
    allume4;
    delay(1000);
  }
}
void animation33(){
   for(int i = 0; i < 5; i++){
      eteintAll();
      allume2;
      allume4;
      delay(1000);
      eteintAll();
      allume1;
      allume3;
      delay(1000);
   } 
}

void animation4(){
  for(int i = 0; i < 10; i++){
     eteintAll();
     delay(100);
     allumeAll();
     delay(100);
  }
 
  
}
