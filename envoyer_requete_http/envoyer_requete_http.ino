#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* host = "192.168.1.102";
const int  port = 80;
const char* ssid = "James Vodafone";
const char* password = "1234567j";

HTTPClient http;

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.print("connecting to ");
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
  
//    if(WiFi.status() != WL_CONNECTED) {
//      Serial.println("!!");
//    } else {  
//      Serial.println("WiFi connected");
//      Serial.println("IP address: ");
//      Serial.println(WiFi.localIP());
    
      String url = "http://192.168.1.102/sweethome/ledChange.php?etat=ON";
      
//      Serial.print("connecting to ");
//      Serial.println(host);
      Serial.print("Requesting URL: ");
      Serial.println(url);
     
     // http.begin(host,port,url);
      http.begin("http://192.168.1.102/sweethome/ledChange.php?etat=ON"); //Specify request destination
      http.addHeader("Content-Type", "text/plain");  //Specify content-type for header
      int httpCode = http.POST("http://192.168.1.102/sweethome/ledChange.php?etat=ON"); //Send the request
     // int httpCode = http.POST();
      
        if (httpCode == 200) {
          String payload = http.getString();
          Serial.println(payload);
        }
        
      Serial.println("closing connection");
      http.end();
      WiFi.disconnect();
      delay(5000);
 //   }
}
