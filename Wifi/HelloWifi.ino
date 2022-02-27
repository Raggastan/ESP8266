#include "Arduino.h"
#include "ESP8266WiFi.h"

#define PIN_LED 5
const char * SSID = "RaggaPhone";
const char * PASSWORD = "charcuterie";

void setup() {
    pinMode(PIN_LED, OUTPUT);
    WiFi.mode(WIFI_STA);
    WiFi.begin(SSID, PASSWORD);
    Serial.begin(9600);
    Serial.println("");
}

void loop() {
    if (WiFi.isConnected()) {
        digitalWrite(PIN_LED, HIGH);
        Serial.println("Connected");
        Serial.println("IP Adress : " + WiFi.localIP().toString());
    }
    else {
        digitalWrite(PIN_LED, LOW);
        Serial.println("Offline");
    }
    delay(250);
}