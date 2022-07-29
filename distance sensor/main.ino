const int trigPin = 14;
const int echoPin = 12;

void setup() {
  Serial.begin(115200);
  Serial.println("Liaison série démarrée");
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
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

  Serial.print("distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  delay(500);
}
