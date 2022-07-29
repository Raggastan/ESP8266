const int ledPin = 5;
const int tiltPin = 16;
const int laserPin = 4;

void setup() {
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, LOW);
    pinMode(tiltPin, INPUT);
    pinMode(laserPin, OUTPUT);
    digitalWrite(laserPin, LOW);
    Serial.begin(9600);
    Serial.print("Started");
}

void loop() {
    int sensorValue = digitalRead(tiltPin);
    if (sensorValue == HIGH) {
        digitalWrite(ledPin, HIGH);
        digitalWrite(laserPin, HIGH);
    }
    else {
        digitalWrite(ledPin, LOW);
        digitalWrite(laserPin, LOW);
    }
    delay(250);
}