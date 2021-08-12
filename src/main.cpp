#include <Arduino.h>
#include "capacitiveInput.h"

#define SENSOR0 D1 // pin 5
#define SENSOR1 D2 // pin 4
#define SENSOR2 D5 // pin 14

#define THRESHOLD 3

SinglePinCapacitiveInput s0 = SinglePinCapacitiveInput(SENSOR0, THRESHOLD);
SinglePinCapacitiveInput s1 = SinglePinCapacitiveInput(SENSOR1, THRESHOLD);
SinglePinCapacitiveInput s2 = SinglePinCapacitiveInput(SENSOR2, THRESHOLD);

void setup() 
{
	Serial.begin(115200);
}

void loop() 
{
	s0.pollSensor();
	s1.pollSensor();
	s2.pollSensor();

	s0.printSensorInfo();
	s1.printSensorInfo();
	s2.printSensorInfo();

	Serial.println();
}