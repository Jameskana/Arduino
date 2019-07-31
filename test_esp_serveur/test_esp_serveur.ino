#include <ESP8266WebServer.h>
#include <ESP8266WebServerSecure.h>
#include <ESP8266WebServerSecureAxTLS.h>
#include <ESP8266WebServerSecureBearSSL.h>

#include <BearSSLHelpers.h>
#include <CertStoreBearSSL.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiAP.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFiScan.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiType.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiClientSecureAxTLS.h>
#include <WiFiClientSecureBearSSL.h>
#include <WiFiServer.h>
#include <WiFiServerSecure.h>
#include <WiFiServerSecureAxTLS.h>
#include <WiFiServerSecureBearSSL.h>
#include <WiFiUdp.h>

#include <ESP8266HTTPClient.h>





const char* ssid = "iPhone se";
const char* password = "1234567m";
//const char* host = "192.168.43.128";


void setup() {
  delay(1000);
  Serial.begin(115200);
  WiFi.mode(WIFI_OFF);
  delay(1000);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  Serial.print("Connecting ..");
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

}

void loop() {
 // while(WiFi.status() == WL_CONNECTED){
    HTTPClient http;

    String ADCData, station, getData, Link;
    ADCData = "23";
    station = "B";
    getData = "?status=" + ADCData + "&station=" + station;
    Link = "http://192.168.43.128/c4yforum/getdemo.php" + getData;
    //http.begin("http://jsonplaceholder.typicode.com/users/1");
    http.begin(Link);
    
    int httpCode = http.GET();
    
  //  if(httpCode > 0){
      String payload = http.getString();
      Serial.println(httpCode); 
     Serial.println(payload); 
  //  }
    
    http.end();
 // }
  delay(5000);
 

}
