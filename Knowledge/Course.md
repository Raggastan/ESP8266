# Things I've learned along the road

ESP8266 is a chip. The NodeMcu v3 is a board, with a ESP8266 chip.

## General

The ESP8266 can be in either Access Point mode (AP), or in station mode.
In the first one, you can connect to the ESP8266. In the second one, the ESP8266
connects to an existing network.

## Arduino

There is two main function in an arduino file: `void setup()` and `void loop()`.
The first one is run once at the startup of the board. It is used to initialize parameters,
the board... The second one is an infinite loop.
Basically, it is like there is a `void main()` function in C++ with the first few lines
being the setup() and a while(1) loop right after.