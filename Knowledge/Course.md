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


I issued a error code 1 when uploading : I am on linux, I had to run `sudo chmod a+rw /dev/ttyUSB0`
with `ttyUSB0` being the USB port where the board is plugged in.

When you see an error stating a function is already define (most probably `setup()` or `loop()`), check wether there is an already existing file in the directory with a function called the same.

## Language

Don't you dare forgetting the semicolon again.