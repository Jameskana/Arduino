#include <ESP8266WiFi.h>

void setup()
{
  Serial.begin(9600);
  WiFi.softAP("Smart-house","12345678");

}


void loop()
{

    Serial.println((WiFi.scanNetworks()));

}
