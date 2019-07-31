#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#include <ESP8266HTTPClient.h>

const char *ssid = "James Vodafone";  //ENTER YOUR WIFI SETTINGS
const char *password = "1234567z";
String  message;
const char *host = "192.168.1.101";   //localhost
HTTPClient http;    //Declare object of class HTTPClient


ESP8266WebServer server(80);

const int led = 16;

void handleRoot() {
  digitalWrite(led, 1);
  server.send(200, "text/plain", "hello from esp8266!");
  digitalWrite(led, 0);
}

void handleNotFound() {
  digitalWrite(led, 1);
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
  digitalWrite(led, 0);
}

void setup(void) {
  pinMode(led, OUTPUT);
  digitalWrite(led, 0);
  Serial.begin(115200);
  WiFi.mode(WIFI_OFF);        //Prevents reconnection issue (taking too long to connect)
  delay(1000);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
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
  server.on("/1", []() {
   digitalWrite(led, 1);
   Serial.println("led1/on");
   server.send(200, "text/plain","ledOn" );
  });
  server.on("/2", []() {
   digitalWrite(led, 0);
   Serial.println("led1/off");
   server.send(200, "text/plain","ledOff" );
  });
/***********Fin de reception de requetes http************/
  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {  
 
  delay(100);  //GET Data at every 5 seconds
  
  server.handleClient();
  
    while(Serial.available()){
      message = Serial.readStringUntil('\r');   // On lit une chaine de caractere
      if(message.equals("led1"))
      {
        String Link = "http://192.168.1.101/MaisonConnecter/public/allume/1";
   //     String Link = "http://192.168.1.104/SWEETHOME/ledChange.php?etat=ON";
        http.begin(Link);     //Specify request destination
        int httpCode = http.GET();            //Send the request
        String payload = http.getString();    //Get the response payload
        Serial.println(httpCode);   //Print HTTP return code
        Serial.println(payload);    //Print request response payload
        http.end();  //Close connection
    }else 
    if(message.equals("led2"))
    {      
      String Link = "http://192.168.1.101/MaisonConnecter/public/allume/2";
   //   String Link = "http://192.168.1.104/SWEETHOME/ledChange.php?etat=OFF";
      http.begin(Link);     //Specify request destination
      int httpCode = http.GET();            //Send the request
      String payload = http.getString();    //Get the response payload
      Serial.println(httpCode);   //Print HTTP return code
      Serial.println(payload);    //Print request response payload
      http.end();  //Close connection
    }else 
    if(message.equals("ventilateur/off"))
    {      
      String Link = "http://192.168.1.107/MaisonConnecter/rooutes/web.php/controleur_acces/10";
    //  String Link = "http://192.168.1.101/SWEETHOME/ledChange.php?etat=OFF";
      http.begin(Link);     //Specify request destination
      int httpCode = http.GET();            //Send the request
      String payload = http.getString();    //Get the response payload
      Serial.println(httpCode);   //Print HTTP return code
      Serial.println(payload);    //Print request response payload
      http.end();  //Close connection
    }else 
    if(message.equals("ventilateur/on"))
    {      
      String Link = "http://192.168.1.107/MaisonConnecter/rooutes/web.php/controleur_acces/10";
    //  String Link = "http://192.168.1.101/SWEETHOME/ledChange.php?etat=OFF";
      http.begin(Link);     //Specify request destination
      int httpCode = http.GET();            //Send the request
      String payload = http.getString();    //Get the response payload
      Serial.println(httpCode);   //Print HTTP return code
      Serial.println(payload);    //Print request response payload
      http.end();  //Close connection
    }else 
    if(message.equals("ouvrirPorte"))
    {      
      String Link = "http://192.168.1.107/MaisonConnecter/rooutes/web.php/controleur_acces/8";
    //  String Link = "http://192.168.1.101/SWEETHOME/ledChange.php?etat=OFF";
      http.begin(Link);     //Specify request destination
      int httpCode = http.GET();            //Send the request
      String payload = http.getString();    //Get the response payload
      Serial.println(httpCode);   //Print HTTP return code
      Serial.println(payload);    //Print request response payload
      http.end();  //Close connection
    }else 
    if(message.equals("fermerPorte"))
    {      
      String Link = "http://192.168.1.107/MaisonConnecter/rooutes/web.php/controleur_acces/8";
    //  String Link = "http://192.168.1.101/SWEETHOME/ledChange.php?etat=OFF";
      http.begin(Link);     //Specify request destination
      int httpCode = http.GET();            //Send the request
      String payload = http.getString();    //Get the response payload
      Serial.println(httpCode);   //Print HTTP return code
      Serial.println(payload);    //Print request response payload
      http.end();  //Close connection
    }
  }
}
