#include <SoftwareSerial.h>

SoftwareSerial ESP8266(2, 3);

String NomduReseauWifi = "James Vodafone"; // Garder les guillements
String MotDePasse      = "1234567d"; // Garder les guillements

/****************************************************************/
/*                             INIT                             */
/****************************************************************/
void setup()
{
  Serial.begin(9600); 
  ESP8266.begin(9600);  
  initESP8266();
}
/****************************************************************/
/*                        BOUCLE INFINIE                        */
/****************************************************************/
void loop()
{
   while(ESP8266.available()) 
   {    
     Serial.println(ESP8266.readString());
   }   
}
/****************************************************************/
/*                Fonction qui initialise l'ESP8266             */
/****************************************************************/
void initESP8266()
{  
  Serial.println("**********************************************************");  
  Serial.println("**************** DEBUT DE L'INITIALISATION ***************"); 
  Serial.println("**********************************************************");  
//  envoieAuESP8266("AT+RST"); 
//  recoitDuESP8266(2000);
  Serial.println("**********************************************************"); 
  envoieAuESP8266("AT+CWMODE=3"); 
  recoitDuESP8266(5000);
  Serial.println("**********************************************************"); 
  envoieAuESP8266("AT+CWJAP=\""+ NomduReseauWifi + "\",\"" + MotDePasse +"\""); 
  recoitDuESP8266(10000);
  Serial.println("**********************************************************"); 
  envoieAuESP8266("AT+CIFSR"); 
  recoitDuESP8266(1000);
  Serial.println("**********************************************************"); 
  envoieAuESP8266("AT+CIPMUX=1");   
  recoitDuESP8266(1000);
  Serial.println("**********************************************************"); 
  envoieAuESP8266("AT+CIPSERVER=1,80"); 
  recoitDuESP8266(1000);
  Serial.println("**********************************************************"); 
  Serial.println("***************** INITIALISATION TERMINEE ****************"); 
  Serial.println("**********************************************************"); 
  Serial.println("");  
}

/****************************************************************/
/*        Fonction qui envoie une commande à l'ESP8266          */
/****************************************************************/
void envoieAuESP8266(String commande)
{  
  ESP8266.println(commande); 
}
/****************************************************************/
/*Fonction qui lit et affiche les messages envoyés par l'ESP8266*/
/****************************************************************/
void recoitDuESP8266(const int timeout)
{
  String reponse = "";
  long int time = millis();
  while( (time+timeout) > millis())
  {
    while(ESP8266.available())
    {
      char c = ESP8266.read(); 
      reponse+=c;
    }
  }
  Serial.print(reponse);   
}
