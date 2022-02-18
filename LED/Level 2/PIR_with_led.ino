const int ledPin = 2;      // The LED is plugged on pin 10
const int analogPinIn = A0; // PIR sensor plugged in analog in = pin0

void setup() {
  pinMode(ledPin, OUTPUT);   // Just saying this is an output
  digitalWrite(ledPin, LOW); // Set to off the LED
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  int sensorValue = analogRead(analogPinIn);
  if (sensorValue > 500) {
    digitalWrite(ledPin, HIGH);
    delay(2500);
  }
  else {
  digitalWrite(ledPin, LOW);
  }
}
