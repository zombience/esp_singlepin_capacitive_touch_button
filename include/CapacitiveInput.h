#ifndef SINGLEPININPUT_h
#define SINGLEPININPUT_h

#include <Arduino.h>

class SinglePinCapacitiveInput
{
	public:
		SinglePinCapacitiveInput(int hwpin, int threshold = 3);
		bool pollSensor();
		void printSensorInfo();
	private:
		const int 
			// prevent noise from triggering state changes
			_debounceTime = 10, // milliseconds
			// determines how many samples read in new state before allowing update of stored state
			_consecutiveSampleCount = 10;
		int 
			_pin, 
			_curVal, 
			_threshold,
			_threshCrossCount;
		bool _curState;
		unsigned int _lastTouchTime;
		

		// from github user [juanpintom](https://github.com/juanpintom)
		// https://github.com/juanpintom/Souliss_ESP_Examples/blob/master/E08_ESP_Capacitive_Sensor.ino
	static uint8_t readCapacitivePin(int inputPin) 
	{
		pinMode(inputPin, OUTPUT);
		digitalWrite(inputPin, LOW);
		delay(1);
		// Prevent the timer IRQ from disturbing our measurement
		noInterrupts();
		// Make the pin an input with the internal pull-up on
		pinMode(inputPin, INPUT_PULLUP);

		// Now see how long the pin to get pulled up. This manual unrolling of the loop
		// decreases the number of hardware cycles between each read of the pin,
		// thus increasing sensitivity.
		uint8_t cycles = 17;
				 if (digitalRead(inputPin)) { cycles =  0;}
		else if (digitalRead(inputPin)) { cycles =  1;}
		else if (digitalRead(inputPin)) { cycles =  2;}
		else if (digitalRead(inputPin)) { cycles =  3;}
		else if (digitalRead(inputPin)) { cycles =  4;}
		else if (digitalRead(inputPin)) { cycles =  5;}
		else if (digitalRead(inputPin)) { cycles =  6;}
		else if (digitalRead(inputPin)) { cycles =  7;}
		else if (digitalRead(inputPin)) { cycles =  8;}
		else if (digitalRead(inputPin)) { cycles =  9;}
		else if (digitalRead(inputPin)) { cycles = 10;}
		else if (digitalRead(inputPin)) { cycles = 11;}
		else if (digitalRead(inputPin)) { cycles = 12;}
		else if (digitalRead(inputPin)) { cycles = 13;}
		else if (digitalRead(inputPin)) { cycles = 14;}
		else if (digitalRead(inputPin)) { cycles = 15;}
		else if (digitalRead(inputPin)) { cycles = 16;}

		// End of timing-critical section
		interrupts();

		// Discharge the pin again by setting it low and output
		//  It's important to leave the pins low if you want to 
		//  be able to touch more than 1 sensor at a time - if
		//  the sensor is left pulled high, when you touch
		//  two sensors, your body will transfer the charge between
		//  sensors.
		digitalWrite(inputPin, LOW);
		pinMode(inputPin, OUTPUT);

		return cycles;
	}	
};

#endif