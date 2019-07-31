#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
 
//SSID and Password of your WiFi router
const char* ssid = "James Vodafone";
const char* password = "1234567j";
 
ESP8266WebServer server(80);
 
//LED Connections
const int led = 2;

//=======================================================================
//                    SETUP
//=======================================================================
void setup(){
  Serial.begin(115200);   //Start serial connection  
  
  pinMode(led,OUTPUT);
  
    WiFi.begin(ssid, password);     //Connect to your WiFi router
  Serial.println("");
  
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP
  
  server.on("/ledOn", []{
    digitalWrite(led, HIGH);
    });  //Associate handler function to path
  server.on("/ledOff", []{
    digitalWrite(led, LOW);
    });
    
  server.begin();                           //Start server
  Serial.println("HTTP server started");
}
//=======================================================================
//                    LOOP
//=======================================================================
void loop(){
  server.handleClient();
}
