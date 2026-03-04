#include <stdio.h>
#include <stdlib.h>
#include "machine.h"
#include "others.h"

// Function to calculate motor power
float computePower(Machine *m) {
    return (m->motor.specs.voltage * m->motor.specs.current); // P = V * I
}

// Function to validate sensor reading
int checkSensorStatus(Machine *m, int sensorIndex) {
	if (sensorIndex < 0 || sensorIndex >= m->sensorCount) {
		return 0;
	}

    if ((m->sensor[sensorIndex].reading >= m->sensor[sensorIndex].min) && (m->sensor[sensorIndex].reading <= m->sensor[sensorIndex].max)) { 
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

// Function to Update reading of a specific machine sensor
void updateSensorReading(Machine *m, int sensorIndex, float newReading) {
	if (sensorIndex < 0 || sensorIndex >= m->sensorCount) {
		printf(RED "Invalid sensor index.\n" RESET);
		return;
	}

	m->sensor[sensorIndex].reading = newReading;
	printf(checkSensorStatus(m, sensorIndex) ? BRIGHTGREEN "Sensor status: WITHIN RANGE\n" RESET : BRIGHTRED "Sensor status: OUT OF RANGE\n" RESET);
}

// Function to display data of a machine
void displayMachineInfo(Machine *m) {
	int i;
	float power = computePower(m);
	int powerLevel = classifyPowerLevel(power);
	printf(YELLOW "\n---------------------------------=]\n" RESET, findMachineByID(m, sizeof(m)/sizeof(Machine), (m->id)+1));
	printf(YELLOW "Machine Name: \t" RESET "%s\n", m->name);
	printf(YELLOW "Machine ID: \t" RESET "%d\n", m->id);
	printf(YELLOW "Motor Model: \t" RESET "%s\n", m->motor.model);
	printf(YELLOW "Voltage (V): \t" RESET "%.2f V\n", m->motor.specs.voltage);
	printf(YELLOW "Current (I): \t" RESET "%.2f A\n", m->motor.specs.current);
	printf(YELLOW "Power (V*I): \t" RESET "%.2f W\n", power);
	printf(YELLOW "Power Class: \t"); 
	if (powerLevel == 1) {
		printf(BRIGHTRED "LOW POWER\n" RESET);
	} else if (powerLevel == 2) {
		printf(BRIGHTGREEN "NORMAL POWER\n" RESET);
	} else {
		printf(BRIGHTYELLOW "HIGH POWER\n" RESET);
	}

	for (i = 0; i < m->sensorCount; i++) {
		printf(YELLOW"\nSensor[%d]\n"RESET, i);
		printf("Type: \t\t%s\n", m->sensor[i].type);
		printf("Reading: \t%.2f\n", m->sensor[i].reading);
		printf("Range: \t\t[%.2f, %.2f]\n", m->sensor[i].min, m->sensor[i].max);
		printf("Status: \t%s\n", checkSensorStatus(m, i) ? BRIGHTGREEN"WITHIN RANGE"RESET : BRIGHTRED"OUT OF RANGE"RESET);
	}
}

// Function to Compute the average sensor reading of a machine
float computeAverageSensorReading(Machine *m) {
	int i;
	float total = 0.0f;

	if (m->sensorCount <= 0) {
		return 0.0f;
	}

	for (i = 0; i < m->sensorCount; i++) {
		total += m->sensor[i].reading;
	}

	return total / m->sensorCount;
}

// Function to Count sensors of a machine that are out of range
int countOutOfRangeSensors(Machine *m) {
	int i;
	int count = 0;

	for (i = 0; i < m->sensorCount; i++) {
		if (!checkSensorStatus(m, i)) {
			count++;
		}
	}

	return count;
}

// Function to find the index of a machine using machine ID
int findMachineByID(Machine *machines, int machineCount, int machineID) {
	int i;
	for (i = 0; i < machineCount; i++) {
		if ((machines + i)->id == machineID) {
			return i;
		}
	}
	return -1;
}

// Function to Calculate the total power of all machines
float computeTotalPowerAllMachines(Machine *machines, int machineCount) {
	int i;
	float total = 0.0f;

	for (i = 0; i < machineCount; i++) {
		total += computePower(machines + i);
	}

	return total;
}

// Function to find the index of the machine with the highest power
int getHighestPowerMachine(Machine *machines, int machineCount) {
	int i;
	int highestIndex = 0;
	float highestPower;

	if (machineCount <= 0) {
		return -1;
	}

	highestPower = computePower(machines);
	for (i = 1; i < machineCount; i++) {
		float currentPower = computePower(machines + i);
		if (currentPower > highestPower) {
			highestPower = currentPower;
			highestIndex = i;
		}
	}

	return highestIndex;
}

// Function to Remove a Machine using machine id
void removeMachine(Machine *machines, int *machineCount, int machineID) {
	int i;
	int index = findMachineByID(machines, *machineCount, machineID);

	if (index == -1) {
		printf(RED "Machine ID not found.\n" RESET);
		return;
	}

	for (i = index; i < *machineCount - 1; i++) {
		machines[i] = machines[i + 1];
	}

	(*machineCount)--;
	printf(BRIGHTGREEN "Machine removed successfully.\n" RESET);
}
