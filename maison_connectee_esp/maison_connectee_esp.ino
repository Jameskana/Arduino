#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#include <ESP8266HTTPClient.h>

const char *ssid = "James Vodafone";  //ENTER YOUR WIFI SETTINGS
const char *password = "1234567a";
String  message;
String host = "http://192.168.1.102";   //localhost
HTTPClient http;    //Declare object of class HTTPClient

int ledSalon =  0;     
int ledCuisine = 2;
int ledGarage = 14;
int ledChambre1 = 12;
int etatLedChambre1 = 0;
int ledChambre2 = 13;
int etatLedChambre2 = 0;

int boutonSalon = 16;
int etatBoutonSalon = 0;
int boutonCuisine = 5;
int etatBoutonCuisine = 0;
int boutonGarage = 4;
int etatBoutonGarage = 0;

int ledWifi = 15;


ESP8266WebServer server(80);

void handleRoot() {
  server.send(200, "text/plain", "hello from esp8266!");
}

void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}

void setup(void) {
  pinMode(ledWifi, OUTPUT);
  digitalWrite(ledWifi, LOW);
   pinMode(ledSalon, OUTPUT);
  digitalWrite(ledSalon, LOW);
  pinMode(ledGarage, OUTPUT);
  digitalWrite(ledGarage, LOW);
  pinMode(ledCuisine, OUTPUT);
  digitalWrite(ledCuisine, LOW);
  pinMode(boutonSalon, INPUT);
  pinMode(boutonCuisine, INPUT);
  pinMode(boutonGarage, INPUT);
  pinMode(ledChambre1, OUTPUT);
  pinMode(ledChambre2, OUTPUT);
  Serial.begin(115200);
  WiFi.mode(WIFI_OFF);        //Prevents reconnection issue (taking too long to connect)
  delay(1000);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(ledWifi, HIGH);
    delay(250);
    Serial.print(".");
    digitalWrite(ledWifi, LOW);
    delay(250);
  }
  digitalWrite(ledWifi, HIGH);
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("MAC address: ");
  Serial.println(WiFi.macAddress());

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", handleRoot);

/****Je recois une requete http et je la transmet a l'Arduino via communication serie****/
  server.on("/allume/1", []() {
   allumeChambre2();
   server.send(200, "text/plain","ledChambre2/on" );
  });
  server.on("/allume/2", []() {
    allumeSalon();
   server.send(200, "text/plain","ledSalon/on" );
  });
   server.on("/allume/4", []() {
   Serial.println("ledCouloir/on");
   server.send(200, "text/plain","ledCouloir/on" );
  });
    server.on("/allume/5", []() {
      allumeCuisine();
   server.send(200, "text/plain","ledCuisine/on" );
  });
    server.on("/allume/6", []() {
      allumeChambre1();
   server.send(200, "text/plain","ledChambre1/on" );
  });
    server.on("/allume/14", []() {
      allumeGarage();
   server.send(200, "text/plain","ledGarage/on" );
  });
    server.on("/allume/8", []() {
   Serial.println("ouvrirPorteGarage");
   server.send(200, "text/plain","ouvrirPorteGarage" );
  });
    server.on("/allume/7", []() {
   Serial.println("code_rfid_ok");
   server.send(200, "text/plain","code_rfid_ok" );
  });
     server.on("/allume/99", []() {
   Serial.println("code_rfid_bad");
   server.send(200, "text/plain","code_rfid_bad" );
  });
     server.on("/allume/9", []() {
   Serial.println("ventilateur/on");
   server.send(200, "text/plain","ventilateur/on" );
  });
/***********Fin de reception de requetes http************/
//  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {  
 
  delay(100);  //GET Data at every 5 seconds
  
  server.handleClient(); //Ecoute des requetes

  /**************ecoute du pour serie*************/
    while(Serial.available()){
      message = Serial.readStringUntil('\r');   // On lit une chaine de caractere
      if(message.equals("ledChambre2/on") || message.equals("ledChambre2/off"))
      {
        String Link = host+"/MaisonConnecter/public/allume/1";
        http.begin(Link);     //Specify request destination
        int httpCode = http.GET();            //Send the request
        String payload = http.getString();    //Get the response payload
//        Serial.println(httpCode);   //Print HTTP return code
//        Serial.println(payload);    //Print request response payload
        http.end();  //Close connection
    }else 
     if(message.equals("ledPhoto/on") || message.equals("ledPhoto/off"))
      {
        String Link = host+"/MaisonConnecter/public/allume/3";
        http.begin(Link);     //Specify request destination
        int httpCode = http.GET();            //Send the request
        String payload = http.getString();    //Get the response payload
//        Serial.println(httpCode);   //Print HTTP return code
//        Serial.println(payload);    //Print request response payload
        http.end();  //Close connection
    }else 
     if(message.equals("ledCouloir/on") || message.equals("ledCouloir/off"))
      {
        String Link = host+"/MaisonConnecter/public/allume/4";
        http.begin(Link);     //Specify request destination
        int httpCode = http.GET();            //Send the request
        String payload = http.getString();    //Get the response payload
//        Serial.println(httpCode);   //Print HTTP return code
//        Serial.println(payload);    //Print request response payload
        http.end();  //Close connection
    }else 
     if(message.equals("ledChambre1/on") || message.equals("ledChambre1/off"))
      {
        String Link = host+"/MaisonConnecter/public/allume/6";
        http.begin(Link);     //Specify request destination
        int httpCode = http.GET();            //Send the request
        String payload = http.getString();    //Get the response payload
//        Serial.println(httpCode);   //Print HTTP return code
//        Serial.println(payload);    //Print request response payload
        http.end();  //Close connection
    }else 
     if(message.equals("flamme/detectee"))
      {
        String Link = host+"/MaisonConnecter/public/fumee/1";
        http.begin(Link);     //Specify request destination
        int httpCode = http.GET();            //Send the request
        String payload = http.getString();    //Get the response payload
//        Serial.println(httpCode);   //Print HTTP return code
//        Serial.println(payload);    //Print request response payload
        http.end();  //Close connection
    }else 
     if(message.equals("presence/detectee"))
      {
        String Link = host+"/MaisonConnecter/public/presence/1";
        http.begin(Link);     //Specify request destination
        int httpCode = http.GET();            //Send the request
        String payload = http.getString();    //Get the response payload
//        Serial.println(httpCode);   //Print HTTP return code
//        Serial.println(payload);    //Print request response payload
        http.end();  //Close connection
    }else 
     if(message.equals("ventilateur/on") || message.equals("ventilateur/off"))
      {
        String Link = host+"/MaisonConnecter/public/allume/9";
        http.begin(Link);     //Specify request destination
        int httpCode = http.GET();            //Send the request
        String payload = http.getString();    //Get the response payload
//        Serial.println(httpCode);   //Print HTTP return code
//        Serial.println(payload);    //Print request response payload
        http.end();  //Close connection
    }else 
    if(message.indexOf("ouvrirporte/") != -1)
    {      
      String Link = host+"/MaisonConnecter/public/"+message;
      http.begin(Link);     //Specify request destination
      int httpCode = http.GET();            //Send the request
      String payload = http.getString();    //Get the response payload
      if(payload == "code_rfid_ok"){
         Serial.println("code_rfid_ok");
      }
      if(payload == "code_rfid_bad"){
         Serial.println("code_rfid_bad");
      }
//      Serial.println(httpCode);   //Print HTTP return code
//      Serial.println(payload);    //Print request response payload
      http.end();  //Close connection
    }else 
    if(message.equals("porteGarage/ouverte") || message.equals("porteGarage/fermee"))
    {      
      String Link = host+"/MaisonConnecter/public/allume/8";
      http.begin(Link);     //Specify request destination
      int httpCode = http.GET();            //Send the request
      String payload = http.getString();    //Get the response payload
//      Serial.println(httpCode);   //Print HTTP return code
//      Serial.println(payload);    //Print request response payload
      http.end();  //Close connection
    }
  }
  //bouton
   if(digitalRead(boutonCuisine) == LOW){ allumeCuisine();}
   
    if(digitalRead(boutonSalon) == LOW){ allumeSalon(); 
    }
    if(digitalRead(boutonGarage) == LOW){ allumeGarage(); }
}

void allumeGarage(){
   if(etatBoutonGarage == 0)
    {
      digitalWrite(ledGarage, HIGH);
      etatBoutonGarage = 1;
      Serial.println("ledGarage/on");
    }else
    {
      digitalWrite(ledGarage, LOW);
      etatBoutonGarage = 0;
      Serial.println("ledGarage/off");
    }
    storeGarage();
    delay(200);
}
void allumeCuisine(){
  
    if(etatBoutonCuisine == 0)
    {
      digitalWrite(ledCuisine, HIGH);
      etatBoutonCuisine = 1;
      Serial.println("ledCuisine/on");
    }else
    {
      digitalWrite(ledCuisine, LOW);
      etatBoutonCuisine = 0;
      Serial.println("ledCuisine/off");
    }
    storeCuisine();
    delay(200);
}
void allumeSalon(){
  
    if(etatBoutonSalon == 0)
    {
      digitalWrite(ledSalon, HIGH);
      etatBoutonSalon = 1;
      Serial.println("ledSalon/on");
    }else
    {
      digitalWrite(ledSalon, LOW);
      etatBoutonSalon = 0;
      Serial.println("ledSalon/off");
    }
    storeSalon();
    delay(200);
}
void allumeChambre1(){
  
    if(etatLedChambre1 == 0)
    {
      digitalWrite(ledChambre1, HIGH);
      etatLedChambre1 = 1;
    }else
    {
      digitalWrite(ledChambre1, LOW);
      etatLedChambre1 = 0;
    }
    delay(200);
}
void allumeChambre2(){
  
    if(etatLedChambre2 == 0)
    {
      digitalWrite(ledChambre2, HIGH);
      etatLedChambre2 = 1;
    }else
    {
      digitalWrite(ledChambre2, LOW);
      etatLedChambre2 = 0;
    }
    delay(200);
}
void storeCuisine(){
        String Link = host+"/MaisonConnecter/public/allume/5";
        http.begin(Link);     //Specify request destination
        int httpCode = http.GET();            //Send the request
        String payload = http.getString();    //Get the response payload
        Serial.println(httpCode);   //Print HTTP return code
        Serial.println(payload);    //Print request response payload
        http.end();  //Close connection
}
void storeGarage(){
        String Link = host+"/MaisonConnecter/public/allume/14";
        http.begin(Link);     //Specify request destination
        int httpCode = http.GET();            //Send the request
        String payload = http.getString();    //Get the response payload
        Serial.println(httpCode);   //Print HTTP return code
        Serial.println(payload);    //Print request response payload
        http.end();  //Close connection
}
void storeSalon(){
      String Link = host+"/MaisonConnecter/public/allume/2";
      http.begin(Link);     //Specify request destination
      int httpCode = http.GET();            //Send the request
      String payload = http.getString();    //Get the response payload
      Serial.println(httpCode);   //Print HTTP return code
      Serial.println(payload);    //Print request response payload
      http.end();  //Close connection
}
