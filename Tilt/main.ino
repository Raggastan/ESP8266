const int ledPin = 5;
const int tiltPin = 16;

void setup() {
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, LOW);
    pinMode(tiltPin, INPUT);
    Serial.begin(115200);
    Serial.print("Started");
}

void loop() {
    int sensorValue = digitalRead(tiltPin);
    Serial.print(sensorValue);
    Serial.print(" ");
    if (sensorValue == HIGH) {
        digitalWrite(ledPin, HIGH);
    }
    else {
        digitalWrite(ledPin, LOW);
    }
    delay(250);
}