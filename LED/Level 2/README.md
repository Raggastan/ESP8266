# Turning on an LED when someone is close

Using an LED and a PIR sensor.

PIR sensor output is analog, so I plugged it on A0, the analog to digital converter of
the board. It is supplied using the 5V pin (USBV or UV).

The LED is plugged with a resistor on pin D3.

For some reason, I couldn't make it work if the LED was on the same side of the board
as the sensor... 