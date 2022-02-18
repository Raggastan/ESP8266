const int ledPin = 2;    // The LED is plugged on pin 2

void setup() {
  pinMode(ledPin, OUTPUT);   // Just saying this is an output
  digitalWrite(ledPin, LOW); // Set to off the LED
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(500);
}
