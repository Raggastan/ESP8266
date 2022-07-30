#include <stdlib.h>
#include <ESP8266WiFi.h>

const int trigPin = 14;
const int echoPin = 12;

const char *ssid = "distanceOverWifi";
const char *password = "chocolat";

void setup() {
  Serial.begin(115200);
  Serial.println("Liaison série démarrée");
  delay(10);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.begin(115200);
}


void loop() {
  float vitesse_son_cm_us = 0.034;     //Le son parcours 0.034cm/us
  
  //Faire une impulsion de 10ms
  digitalWrite(trigPin, HIGH);  //Passe à l'état HAUT le pin 10
  delayMicroseconds(10);        //Temporisation
  digitalWrite(trigPin,LOW);    //État bas
  //Fin impulsion
  
  //Calcul du temps de l'impulsion au retour
  float temps_us = pulseIn(echoPin, HIGH);  //temps de l'impulsion haute sur le pin9
  float distance_cm = vitesse_son_cm_us * temps_us / 2; //distance parcourue par l'onde, divisée par 2 car l'objet se trouve à mi-distance
  char valeurEnvoi[5];
  dtostrf(distance_cm, 0, 2, valeurEnvoi);
  Serial.print("distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  WiFiClient client;
  const char * host = "192.168.4.1";
  const int httpPort = 80;

  if (!client.connect(host, httpPort)) {
    Serial.println("Connection failed");
    return;
  }

  String url = "/data/";
  url += "?distance=";
  url += valeurEnvoi;

  Serial.print("Requesting URL: ");
  Serial.println(url);

  client.print(String("GET ") + url + " HTTP/1.1\r\n" + 
    "Host: " + host + "\r\n" + "Connection: close\r\n\r\n");
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if(millis() - timeout > 5000) {
      Serial.println(">>> Client Timeout");
      client.stop();
      return;
    }
  }

  Serial.println();
  Serial.println("Closing connection");
  Serial.println();
  Serial.println();
  Serial.println();
  
  delay(500);
}
