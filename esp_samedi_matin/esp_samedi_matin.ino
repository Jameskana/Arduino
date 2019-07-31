#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "James Vodafone";
const char* password = "1234567j";

const char* host = "192.168.1.101";
int temp = 22.5;

void setup() {
  Serial.begin(115200);
  delay(10);

  // We start by connecting to a WiFi network

  //Serial.println();
  Serial.println("");
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected"); 
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
void loop() {

// Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
//temp variable is set with a function to check the temp of an DS18B20 sensor. Let me know if you need it
  //String data = "temp1=" + (String)temp;
// "temp1=" is what is going to be sent using GET to the apache server, see code in add.php

  // We now create a URI for the request
    String url = "POST/esp/dataCollector.php?Humidity=11&Temperature_Cel=22&Temperature_Fehr=33&HeatIndex_Cel=44&HeatIndex_Fehr=55";
  //  String url = "GET/sweethome/ledChange.php?etat=ON";
 // String url = "GET /add.php?" + data + " HTTP/1.1";
//  String url = "GET /add.php?" + data + " HTTP/1.1";
  client.println(url);
  client.println("Host: 192.168.1.101");
  client.println("Connection: close");
  client.println();
  delay(500);
 
  // Read all the lines of the reply from server and print them to Serial
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  client.stop(); //Stopping client
  ESP.deepSleep(60U*60*1000000); //U for unsigned
  delay(1000); //for above sleep
}
