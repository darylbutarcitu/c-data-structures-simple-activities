#include <stdio.h>
#include "machine.h"

// Function to calculate motor power
float computePower(Machine *m) {
    return (m->motor.specs.voltage * m->motor.specs.current);
}

// Function to validate sensor reading
int checkSensorStatus(Machine *m) {
    if (m->sensor.reading >= m->sensor.min && m->sensor.reading <= m->sensor.max) { 
		return 1; // valid, within range
	}
    return 0;	// out of range
}

// Function to check and classify power level
int classifyPowerLevel(float power) {
    if (power < 500) { // LOW
		return 1; 
	} else if (power <= 1500) {	// NORMAL
    	return 2; 
	} else {	// HIGH
		return 3;
	}						
}

// Function to update sensor value
void updateSensorReading(Machine *m, float newReading) {
    m->sensor.reading = newReading;	// update reading
}
