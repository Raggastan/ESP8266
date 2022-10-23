#include <stdlib.h>
#include <ESP8266WiFi.h>
#include <stdbool.h>

#ifndef MOTION_SENSOR_PIN 10

const char *ssid = "esp8266Wifi";
const char *password = "M3@J;r5.-zX!n";

bool motion_detected();
void send_notification();

void setup()
{
  Serial.begin(115200);
  Serial.println("Liaison série démarrée");
  delay(10);
  Serial.println();
  Serial.println();
  Serial.print("Starting WiFI access point ");
  Serial.println(ssid);
  bool result = WiFi.softAP(ssid, password);
  if (result==true)
  {
    IPAddress myIP = WiFi.softAPIP();
    Serial.println("AP created");
    Serial.print("Password : ");
    Serial.println(password);
  }
  else
  {
    Serial.println("Something went wrong...");
  }
}

void loop()
{

}