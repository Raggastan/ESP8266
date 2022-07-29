#include <ESP8266WiFi.h>
 
const char* ssid = "SSID";
const char* password = "PASSWORD";
 
int ledPin = 0;         // Pin D3
WiFiServer server(80);
 
void setup() 
{
  Serial.begin(115200);  
  delay(100);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
 
  // Wifi connection
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);               // Start wifi connection
  while (WiFi.status() != WL_CONNECTED)     // Visual representation of the connexion
  {
    delay(500);
    Serial.print(".");
  }

  // Wifi connected
  Serial.println("WiFi connected");
 
  // Server startup
  server.begin();
  Serial.println("Server started !");
 
  // Display the IP address to connect to
  Serial.print("Use this IP address to connect :");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
 
}
 
void loop() 
{
WiFiClient client;

  
  // Is the client connected ?
  client = server.available();
  if (!client)
  {
    return;
  }
 
  // Wait for the client to send request
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
 
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

  int value = LOW;
  if (request.indexOf("/LED=ON") != -1)  { // Turning on the light
    digitalWrite(ledPin, HIGH);
    value = HIGH;
  }
  if (request.indexOf("/LED=OFF") != -1)  { // Turning off the light
    digitalWrite(ledPin, LOW);
  }
 
  // Response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); 
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
 
  client.print("LED state : ");
 
  if(value == HIGH) {
    client.print("On");
  } else {
    client.print("Off");
  }
  client.println("<br><br>");
  client.println("<a href=\"/LED=ON\"\"><button>Turn on </button></a>");
  client.println("<a href=\"/LED=OFF\"\"><button>Turn off </button></a><br />");  
  client.println("</html>");
 
  delay(1);
  Serial.println("Client disconnected");
  Serial.println("");
 
}