const int ledPin = 2;    // The LED is plugged on pin 10

void setup() {
  pinMode(ledPin, OUTPUT);   // Just saying this is an output
  digitalWrite(ledPin, LOW); // Set to off the LED
  Serial.begin(115200);
  Serial.print("Setup completed");
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(500);
}
