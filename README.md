# ESP8266 Single Pin Capacitive Sensor
A simple class and example to allow for capacitive input on one single pin. 

Normally capacative touch input requires two pins for comparison. Reducing detection capability to one pin is useful on hardware with limited inputs such as the ESP8266. 

## Overview
The method for using one pin to detect capacitance was found in github user [juanpintom's](https://github.com/juanpintom) repo (found [here](https://github.com/juanpintom/Souliss_ESP_Examples/blob/master/E08_ESP_Capacitive_Sensor.ino)). 
This repo extracts the relevant method from the larger project and wraps it in a class, allowing it to be used as-is or incorporated into other button classes in place of `digitalRead(pin)`

## Hardware 
Simply run a wire out of a pin capable of digital read/write. Connect the wire to a larger capacitive surface (such as tinfoil) in order to provide more touch surface. This isn't a requirement, merely touching the bare wire should report modified values when running the example. 

## Notes
Measured values will vary depending on hardware used and may be affected by ambient environment. The `THRESHOLD` value sets the gate to prevent trigger being activated by noise . Calibrate values by running `main.cpp` and observing the serial output of your connected sensors. Longer cables and large capacitive surfaces are likely to yield higher values. YMMV


