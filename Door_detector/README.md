# Door detector

My objective is to be aware when someone is near the main door of the house while I'm in my bedroom

## First idea

Having one ESP8266 outside with a motion sensor (maybe a camera module later),
and an other one on my desk with LEDs to notify me when there is someone in front of the door.

I would like it to be nomad. Not autonomous, but i would like to be able to move the motion sensor arround to
detect human presence elsewhere too.

## Secondary objective

One funny thing to try would be to send the updates to the ESP8266 OTA (Over The Air). If successfull,
I should try to use a CI/CD to automatize the process of updating the programs.
