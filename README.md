# ESP8266 Single Pin Capacitive Sensor
A simple class and example to allow for capacitive input on one single pin. 
Given that the limited pins on the ESP8266 chip, reducing the requirement for capacitive touch to one input comes in handy.

## Overview
The method for using one pin to detect capacitance was found in github user [juanpintom's](https://github.com/juanpintom) repo (found [here](https://github.com/juanpintom/Souliss_ESP_Examples/blob/master/E08_ESP_Capacitive_Sensor.ino)). 
This repo extracts the relevant method from the larger project and wraps it in a class, allowing it to be used as is or incorporated into other button classes in place of `digitalRead(pin)`

## Hardware 
Simply run a wire out of a pin capable of digital read/write. Connect the wire to a larger capacitive surface (such as tinfoil) in order to provide more touch surface. This isn't a requirement, merely touching the bare wire should report modified values when running the example. 

## Notes
Measured values will vary depending on hardware used. The `THRESHOLD` value will need to be modified to a value that is unlikely to be crossed by a noisy signal. Calibrate values by running `main.cpp` and watching the serial output of your connected sensors. Longer cables and possibly large capacitive surfaces are likely to yield higher values. 


