#include <stdlib.h>
#include <ESP8266WiFi.h>
#include <stdbool.h>

#define MOTION_SENSOR_PIN 10

const char *ssid = "esp8266Wifi";
const char *password = "M3@J;r5.-zX!n";


boolean motion_detected();
void send_notification();

void setup()
{
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

void loop()
{

}

boolean flag = true;

bool motion_detected()
{
    if(digitalRead(MOTION_SENSOR_PIN) == HIGH)
    {
        // Turn LED on on the desk
        if (flag)
        {
            // Notification on Telegram
            flag = false;
        }
        delay(200);
    }
    else
    {
        if (!flag)
        {
            // Turn LED off on the desk
            flag = true;
        }
    }
}