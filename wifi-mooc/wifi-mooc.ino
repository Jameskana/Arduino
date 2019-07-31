//#include <BearSSLHelpers.h>
//#include <CertStoreBearSSL.h>
#include <ESP8266WiFi.h>
//#include <ESP8266WiFiAP.h>
//#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiMulti.h>
//#include <ESP8266WiFiScan.h>
//#include <ESP8266WiFiSTA.h>
//#include <ESP8266WiFiType.h>
//#include <WiFiClient.h>
//#include <WiFiClientSecure.h>
//#include <WiFiClientSecureAxTLS.h>
//#include <WiFiClientSecureBearSSL.h>
//#include <WiFiServer.h>
//#include <WiFiServerSecure.h>
//#include <WiFiServerSecureAxTLS.h>
//#include <WiFiServerSecureBearSSL.h>
//#include <WiFiUdp.h>


//#include <ESP8266WiFi.h>
//#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
//#include <WiFi.h>
//#include <WiFiMulti.h>

//#include <HTTPClient.h>

//WiFiMulti wifiMulti;

// paramètres du réseau wifi à modifier
char ssid[] = "<nom_de_votre_réseau>";
char pass[] = "<mot_de_passse_de_votre_réseau>";

// chemin vers la ressource que l'on souhaite consulter
String url  = "http://api.openweathermap.org/data/2.5/weather?appid=c1b327687e24fed4784cdf65b83b48fd&units=metric&q=Rennes,fr";

void setup() {
  Serial.begin (115200);

  // connexion au wifi
  Serial.println();
  Serial.println();
  Serial.print("Connexion au reseau ");
  Serial.print(ssid);

//  Wifi.addAP(ssid, pass);
  WiFi.softAP(ssid, pass);
//  WiFi.softAP(ssid, pass);
  
  while (WiFi.status() != WL_CONNECTED) {
 // while (wifiMulti.run() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println();
  Serial.print("WiFi OK, adresse IP : ");
  Serial.println(WiFi.localIP());
}

void loop() {
  if ((WiFi.status() == WL_CONNECTED)) {
   // if ((wifiMulti.run() == WL_CONNECTED)) {
    // si on est connecté alors on créé un objet http pour envoyer une requête
    HTTPClient http;
//    ESP8266HTTPClient http;

    // on envoit une requête HTTP
    Serial.print("Requete HTTP : ");
    Serial.println(url);
    http.begin(url);
  

    // c'est une requête GET
    if (http.GET() == HTTP_CODE_OK) {
      // on vient ensuite afficher la réponse du serveur
      Serial.print("Reponse serveur : ");
      Serial.println(http.getString());
    }
    else {
      Serial.println("La requete HTTP a echoue !");
    }

    http.end();
  }

  delay(10000);
}
