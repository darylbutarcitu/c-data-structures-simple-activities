#include <stdio.h>
#include <stdlib.h>
#include "machine.h"
#include "others.h"

#include <stdio.h>
#include <stdlib.h>
#include "machine.h"
#include "others.h"

int main() {
    int choice, sensorUpdateFlag = 0;
    Machine *m = malloc(sizeof(Machine));
    
    if (!m) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    displayTitle();

    // Initialize machine details
    printf(YELLOW"\nMachine Name: "RESET);
    getStringInput(m->name);

    printf(YELLOW"Machine ID: "RESET);
    m->id = getIntegerInput();

    printf(YELLOW"Motor Model: "RESET);
    getStringInput(m->motor.model);

    printf(YELLOW"Voltage: "RESET);
    m->motor.specs.voltage = getFloatInput();

    printf(YELLOW"Current: "RESET);
    m->motor.specs.current = getFloatInput();

    printf(YELLOW"Sensor Type: "RESET);
    getStringInput(m->sensor.type);

    printf(YELLOW"Sensor Reading: "RESET);
    m->sensor.reading = getFloatInput();

    printf(YELLOW"Minimum Range: "RESET);
    m->sensor.min = getFloatInput();

    printf(YELLOW"Maximum Range: "RESET);
    m->sensor.max = getFloatInput();

    // Main loop
    do {
        system("cls");
        displayTitle();
		
		// Initialize machine/sensor values by calling functions from machine.h
        float power = computePower(m);
        int powerLevel = classifyPowerLevel(power);
        int sensorStatus = checkSensorStatus(m);

		// Display Machine Details
        printf(YELLOW"\n[===== MACHINE REPORT =====]\n"RESET);
        printf(YELLOW"Name: \t\t"RESET"%s\n", m->name);
        printf(YELLOW"ID: \t\t"RESET"%d\n", m->id);
        printf(YELLOW"Motor: \t\t"RESET"%s\n", m->motor.model);
        printf(YELLOW"Voltage (V): \t"RESET"%f\n", m->motor.specs.voltage);
        printf(YELLOW"Current (I): \t"RESET"%f\n", m->motor.specs.current);
        printf(YELLOW"Power (IR): \t"RESET"%.2f Watts ", power);
		
		// Display appropriate power level
        if (powerLevel == 1) {
        	printf(BRIGHTRED"(LOW POWER)\n"RESET);
		}
        else if (powerLevel == 2) {
        	printf(BRIGHTGREEN"(NORMAL POWER)\n"RESET);
		}
        else {
        	printf(BRIGHTYELLOW"(HIGH POWER)\n"RESET);
		}
		
		// Display Sensor Details
        printf(YELLOW"\n[====== SENSOR DATA ======]\n"RESET);
        printf(YELLOW"Type: \t"RESET"%s\n", m->sensor.type);
        printf(YELLOW"Range: \t"RESET"[%.2f, %.2f]\n", m->sensor.min, m->sensor.max);
        printf(YELLOW"Reading: "RESET"%.2f ", m->sensor.reading);
        printf(sensorStatus ? BRIGHTGREEN"(WITHIN RANGE)\n"RESET : BRIGHTRED"(OUT OF RANGE)\n"RESET);

		// Prompt user to update sensor or exit
        printf("\n[1] Update Sensor Reading\n");
        printf(RED"[0] Exit\n"RESET);
        
        if (sensorUpdateFlag) {
            printf(BRIGHTGREEN"Sensor reading updated!\n"RESET);
            sensorUpdateFlag = 0;
        }
        
        printf(YELLOW"Enter choice: "RESET);
        choice = getIntegerInput();
        
        if (choice == 1) {
            printf(BRIGHTGREEN"\nUpdate Sensor Reading: "RESET);
            printf(YELLOW"Enter new value: "RESET);
            updateSensorReading(m, getFloatInput());
            sensorUpdateFlag = 1;
        }
    } while (choice != 0);

    free(m);
    printf(YELLOW"\nMemory freed..."RESET BRIGHTGREEN"\nExiting..."RESET);

    return 0;
}

/* 	Butar, Daryl D.	24-5865-705	BSCPE	
	CPE264 H1 2ndSem2526
	Activity 3
	February 19, 2026
*/
