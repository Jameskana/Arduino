#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>


const char pinIR=9;
IRrecv monRecepteur(pinIR);
decode_results messageRecu;



int LED_A =2;
int LED_B =3;
int LED_C =4;
int LED_D =5;
int LED_E =6;
int LED_F =7;
int LED_G =8;





void setup() {
  // put your setup code here, to run once:
     Serial.begin(9600);
     monRecepteur.enableIRIn();
     monRecepteur.blink13(true);
  pinMode(LED_A, OUTPUT);   
  pinMode(LED_B, OUTPUT);
  pinMode(LED_C, OUTPUT);
  pinMode(LED_D, OUTPUT);
  pinMode(LED_E, OUTPUT);
  pinMode(LED_F, OUTPUT);
  pinMode(LED_G, OUTPUT);

}

void loop() {

    if(monRecepteur.decode(&messageRecu)){
      Serial.println(messageRecu.value,DEC);
      delay(500);
      Serial.println(transcode(messageRecu));
      afficher(transcode(messageRecu));
      monRecepteur.resume();
 
      }
//    afficher1();
//    delay(2000);
//    afficher2();
//    delay(2000);
  
  // put your main code here, to run repeatedly:

}

int transcode(decode_results recu){
        if(recu.value==1086165103)
      return 0;    
      if(recu.value==1086128383)
      return 1;
         if(recu.value==1086161023)
      return 2;
          if(recu.value==1086144703)
      return 3;
          if(recu.value==1086177343)
      return 4;
          if(recu.value==1086136543)
      return 5;
          if(recu.value==1086169183)
      return 6;
          if(recu.value==1086152863)
      return 7;
          if(recu.value==1086185503)
      return 8;
          if(recu.value==1086132463)
      return 9;

  }

void afficher(int numero){
    if(numero==0){
       reset();
       digitalWrite(LED_A,HIGH);
       digitalWrite(LED_B,HIGH);
       digitalWrite(LED_C,HIGH);
       digitalWrite(LED_D,HIGH);
       digitalWrite(LED_E,HIGH);
       digitalWrite(LED_F,HIGH);

      }
    if(numero==1){
       reset();
       digitalWrite(LED_B,HIGH);
       digitalWrite(LED_C,HIGH);
     }

    if(numero==2){
       reset();
       digitalWrite(LED_A,HIGH);
       digitalWrite(LED_B,HIGH);
       digitalWrite(LED_G,HIGH);
       digitalWrite(LED_E,HIGH);
       digitalWrite(LED_D,HIGH);
     }

         if(numero==3){
       reset();
       digitalWrite(LED_A,HIGH);
       digitalWrite(LED_B,HIGH);
       digitalWrite(LED_C,HIGH);
       digitalWrite(LED_G,HIGH);
       digitalWrite(LED_D,HIGH);
     }
         if(numero==4){
       reset();
       digitalWrite(LED_F,HIGH);
       digitalWrite(LED_C,HIGH);
       digitalWrite(LED_G,HIGH);
       digitalWrite(LED_B,HIGH);

     }
         if(numero==5){
       reset();
       digitalWrite(LED_A,HIGH);
       digitalWrite(LED_F,HIGH);
       digitalWrite(LED_G,HIGH);
       digitalWrite(LED_C,HIGH);
       digitalWrite(LED_D,HIGH);
     }
         if(numero==6){
       reset();
       digitalWrite(LED_A,HIGH);
       digitalWrite(LED_C,HIGH);
       digitalWrite(LED_D,HIGH);
       digitalWrite(LED_E,HIGH);
       digitalWrite(LED_F,HIGH);
       digitalWrite(LED_G,HIGH);
      
     }
         if(numero==7){
       reset();
       digitalWrite(LED_A,HIGH);
       digitalWrite(LED_B,HIGH);
       digitalWrite(LED_C,HIGH);
 
     }
         if(numero==8){
       reset();
       digitalWrite(LED_B,HIGH);
       digitalWrite(LED_A,HIGH);
       digitalWrite(LED_C,HIGH);
       digitalWrite(LED_D,HIGH);
       digitalWrite(LED_E,HIGH);
       digitalWrite(LED_F,HIGH);
       digitalWrite(LED_G,HIGH);
     }
       if(numero==9){
       reset();
       digitalWrite(LED_A,HIGH);
       digitalWrite(LED_C,HIGH);
       digitalWrite(LED_D,HIGH);
       digitalWrite(LED_B,HIGH);
       digitalWrite(LED_F,HIGH);
       digitalWrite(LED_G,HIGH);
     }
  }

  void afficher1(){
      reset();
       digitalWrite(LED_B,HIGH);
       digitalWrite(LED_C,HIGH);
    }

    void afficher2(){
        reset();
       digitalWrite(LED_A,HIGH);
       digitalWrite(LED_B,HIGH);
       digitalWrite(LED_G,HIGH);
       digitalWrite(LED_E,HIGH);
       digitalWrite(LED_D,HIGH);

  }
 void  reset(){
    int i =0;
    for(i=2;i<=8;i++){
       digitalWrite(i,LOW);
      }
  }

  void afficher3(){
    
  }
  void afficher(){
    
  }
