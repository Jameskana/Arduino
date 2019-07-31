// Déclare le serveur Web
#include <ESP8266WebServer.h>
ESP8266WebServer server(80); 

const char* ssid = "James Vodafone";
const char* password = "1234567j";

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
  
  // Répond à la requete / (racine)
  server.on("/", [](){ 
    server.send(200, "text/plain", "Bienvenue sur le serveur Web");
  });
  
  // Démarre le serveur Web
  server.begin(); 
}
void loop() {
  // Traite les requetes
  server.handleClient();
}
