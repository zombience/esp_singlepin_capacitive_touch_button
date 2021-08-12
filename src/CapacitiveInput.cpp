#include "capacitiveInput.h"

// threshold value may change depending on length of wires or materials used
SinglePinCapacitiveInput::SinglePinCapacitiveInput(int hwpin, int threshold)
{
	_curState = false;
	_lastTouchTime = millis();
	_threshold = threshold;
	_pin = hwpin;
}

bool
SinglePinCapacitiveInput::pollSensor()
{
	_curVal = readCapacitivePin(_pin);

	if((_curVal >= _threshold && !_curState) || (_curVal < _threshold && _curState))
	{
		
		if(abs(_lastTouchTime - millis()) < _debounceTime) return _curState;
		if(_threshCrossCount >= _consecutiveSampleCount)
		{
			// low input values tend to be 1 or 2
			// hi input values tend to be 4 or 5
			bool newState = _curVal >= _threshold;
			if(newState != _curState)
			{
				_curState = newState;
				_lastTouchTime = millis();
				_threshCrossCount = 0;
			}
		}
		else
		{
			_threshCrossCount ++;
		}
	}
	else
	{
		_threshCrossCount = 0;
	}
	
	return _curState;
}

void
SinglePinCapacitiveInput::printSensorInfo()
{
	Serial.print("pin: ");
	Serial.print(_pin);
	Serial.print(" raw val: ");
	Serial.print(_curVal);
	Serial.print(" state: ");
	Serial.print(_curState ? "on  " : "off ");
}