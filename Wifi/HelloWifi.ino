#include "Arduino.h"
#include "ESP8266WiFi.h"

#define PIN_LED 5
const char * SSID = "RaggaPhone";
const char * PASSWORD = "charcuterie";

void onConnected(const WiFiEventStationModeConnected& event);   // prototypes,functions 
void onGotIP(const WiFiEventStationModeGotIP& event);           // delcared below

void setup() {
    pinMode(PIN_LED, OUTPUT);
    WiFi.mode(WIFI_STA);
    WiFi.begin(SSID, PASSWORD);
    Serial.begin(9600);
    Serial.println("");
    static WiFiEventHandler onConnectedHandler = WiFi.onStationModeConnected(onConnected);
    static WiFiEventHandler onGotIPHandler = WiFi.onStationModeGotIP(onGotIP);
}

void loop() {
    if (WiFi.isConnected()) {
        digitalWrite(PIN_LED, HIGH);
    }
    else {
        digitalWrite(PIN_LED, LOW);
        Serial.println("Offline");
    }
    delay(250);
}


void onConnected(const WiFiEventStationModeConnected& event) {
    Serial.println("Connected");
}

void onGotIP(const WiFiEventStationModeGotIP& event) {
    Serial.println("Connected");
    Serial.println("IP Adress : " + WiFi.localIP().toString());
    Serial.println("Gateway : " + WiFi.gatewayIP().toString());
    Serial.println("DNS : " + WiFi.dnsIP().toString());
    Serial.print("Signal strength : ");
    Serial.println(WiFi.RSSI());
}