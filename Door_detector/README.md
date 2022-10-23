# Door detector

My objective is to be aware when someone is near the main door of the house while I'm in my bedroom

## First idea

Having one ESP8266 outside with a motion sensor (maybe a camera module later),
and an other one on my desk with LEDs to notify me when there is someone in front of the door.

I would like it to be nomad. Not autonomous, but i would like to be able to move the motion sensor arround to
detect human presence elsewhere too.

One of the ESP8266 will create an WiFi AP for the second one to connect to, creating their own network.
Whrn the outside ESP8266 detects a movement, it triggers a function on the second ESP8266 to notify the user
someone is here.

## Secondary objective

One funny thing to try would be to send the updates to the ESP8266 OTA (Over The Air). If successfull,
I should try to create a CI/CD to automatize the process of updating the firmware.

## Architecture

### First ESP8266 : outside

The first ESP8266 will be outside.

It will need a motion sensor at least.

### Second ESP8266 : inside

The second ESP8266 will be on my desk. It will need at least a LED, maybe a buzzer.
It will create the AP, because this one will be inside, so with less energy restriction than the one outside that
might run on a battery (not sure about this, butthis way it will consume less energy anyway).
