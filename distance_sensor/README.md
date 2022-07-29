# Objectif

Je veux afficher une distance sur une page web

Premièrement, je cherche à afficher sur le moniteur série la distance obtenue par le capteur
ultrasonique.

Le capteur ultrasonique focntionne de la façon suivante :

- il attend une impulsion de 10 micro seconde (10us) sur le pin trig

- il envoie en retour une impulsion depuis le pin echo, de durée égale au temps qu'il y a eu entre le temps
d'émission et de réception de l'onde ultrasonique.

- en capturant ce temps, le multipliant par la vitesse du son et en le divisant par deux, on peut définir à quelle distance se trouve l'objet.
  
Il faut diviser par deux car le temps total correspond au temps qu'à mis l'onde pour aller jusqu'à l'objet puis revenir
