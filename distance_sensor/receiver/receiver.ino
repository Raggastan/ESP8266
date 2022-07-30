#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <stdlib.h>

const char *ssid = "distanceOverWifi";
const char *password = "chocolat";

ESP8266WebServer server(80);

void handleSentVar() {
  Serial.println("handleSentVar function called...");
  if (server.hasArg("distance")) {
    Serial.println("Sensor reading received...");

    double valeur = server.arg("distance").toFloat();

    Serial.print("Reading: ");
    Serial.println(valeur);
    Serial.println();
    server.send(200, "text/html", "Data received");
  }
  else {
    Serial.println();
    Serial.println("Data not received...");
  }
}

void setup() {
  delay(1000);
  Serial.begin(115200);
  Serial.println();
  Serial.print("Configuring access point...");

  WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.on("/data/", HTTP_GET, handleSentVar);
  server.begin();
  Serial.println("HTTP server started");

}

void loop() {
  server.handleClient();

}
