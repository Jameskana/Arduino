/*
  Modified version of WifiWebServer example.  
 */

#include <ESP8266WiFi.h>

//WIfi AP name and password
const char* ssid = "Mirai_ESP";
//const char* password = "1234567r";

// Create an instance of the server and specify the port to listen on as an argument
WiFiServer server(80);

void setup() {
  delay(1000);
//  WiFi.softAP(ssid, password); // remove the password parameter if you want the AP to be open.
WiFi.softAP(ssid);
  server.begin();
  delay(2000);
   // prepare LED PIN, LED is connected to TX = BUILTIN_LED
   // TX is 1 = BUILTIN_LED
   // RX is 3
   // GPIO 0 is 0 
   // GPIO 2 is 2
  pinMode(BUILTIN_LED, OUTPUT);
  delay(100);
  digitalWrite(BUILTIN_LED, HIGH); // Turn OFF led at initial stage
}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  
  // Wait until the client sends some data
  while(!client.available()){
    delay(1);
  }
  
  // Read the first line of the request
  String req = client.readStringUntil('\r');
  client.flush();
  
  // Match the request
  if (req.indexOf("/LED_1/off") != -1)
    digitalWrite(BUILTIN_LED, LOW); //LED OFF // Set Blue LED according to the request
  else if (req.indexOf("LED_1/on") != -1)
    digitalWrite(BUILTIN_LED, HIGH); //LED ON // Set Blue LED according to the request
  else if (req.indexOf("/") != -1)
    ; //do nothing; just send html page
  else {
    client.stop();
    return;
  }
  client.flush();
  
  String HTML = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html> <h1>DIY HowToDoIt</h1> <h2>ESP8266 Web Server</h2>";
  HTML += "<h3>Blue LED is now ";
  HTML += (digitalRead(BUILTIN_LED))?"ON":"OFF</h3>"; //HIGH = LED ON and LOW = LED OFF
  HTML += "<h3>Blue LED <button onclick=\"window.location.href='/LED_1/on'\">LED ON</button>&nbsp;<button onclick=\"window.location.href='/LED_1/off'\">LED OFF</button></h3></html>";
 

  client.print(HTML);
  delay(10);
  // The client will actually be disconnected 
  // when the function returns and 'client' object is detroyed
}
