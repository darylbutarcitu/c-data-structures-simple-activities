#include <stdio.h>
#include <stdlib.h>
#include "machine.h"
#include "others.h"

int main() {
	int choice = 0; 	// User menu choice
	int machineCount; 	// Number of machines to be entered by user
	int i, j;			// Loop counters
	Machine *machines;	// Dynamic array of machines

	displayTitle();
	printf("Enter number of Machines: ");
	while (scanf("%d", &machineCount) != 1 || machineCount <= 0) {
		printf(RED "Invalid input. Enter a positive number: " RESET);
		clearInputBuffer();
	}
	clearInputBuffer();

	// Dynamically allocate memory for machines
	machines = (Machine *)malloc(machineCount * sizeof(Machine));
	if (machines == NULL) {
		printf(RED "Memory allocation failed.\n" RESET);
		return 1;
	}

	for (i = 0; i < machineCount; i++) {
		printf(BRIGHTGREEN "\nInitialize data of Machine[%d]\n" RESET, i);

		printf(YELLOW"Machine Name: "RESET);
		readLine((machines + i)->name, sizeof((machines + i)->name));

		printf(YELLOW"Machine ID: "RESET);
		while (scanf("%d", &((machines + i)->id)) != 1) {
			printf(RED "Invalid input. Enter a valid Machine ID: " RESET);
			clearInputBuffer();
		}
		clearInputBuffer();

		printf(YELLOW"Motor Model: "RESET);
		readLine((machines + i)->motor.model, sizeof((machines + i)->motor.model));

		printf(YELLOW"Voltage: "RESET);
		while (scanf("%f", &((machines + i)->motor.specs.voltage)) != 1) {
			printf(RED "Invalid input. Enter a valid voltage: " RESET);
			clearInputBuffer();
		}

		printf(YELLOW"Current: "RESET);
		while (scanf("%f", &((machines + i)->motor.specs.current)) != 1) {
			printf(RED "Invalid input. Enter a valid current: " RESET);
			clearInputBuffer();
		}
		clearInputBuffer();

		printf(YELLOW"Number of sensors (max 5): "RESET);
		while (scanf("%d", &((machines + i)->sensorCount)) != 1 || (machines + i)->sensorCount < 1 || (machines + i)->sensorCount > 5) {
			printf(RED "Invalid input. Enter 1 to 5: " RESET);
			clearInputBuffer();
		}
		clearInputBuffer();

		for (j = 0; j < (machines + i)->sensorCount; j++) {
			printf("\nSensor[%d] "YELLOW"Type: "RESET, j);
			readLine((machines + i)->sensor[j].type, sizeof((machines + i)->sensor[j].type));

			printf("Sensor[%d] "YELLOW"Reading: "RESET, j);
			while (scanf("%f", &((machines + i)->sensor[j].reading)) != 1) {
				printf(RED "Invalid input. Enter a valid reading: " RESET);
				clearInputBuffer();
			}

			printf("Sensor[%d] "YELLOW"Min Range: "RESET, j);
			while (scanf("%f", &((machines + i)->sensor[j].min)) != 1) {
				printf(RED "Invalid input. Enter a valid minimum range: " RESET);
				clearInputBuffer();
			}

			printf("Sensor[%d] "YELLOW"Max Range: "RESET, j);
			while (scanf("%f", &((machines + i)->sensor[j].max)) != 1) {
				printf(RED "Invalid input. Enter a valid maximum range: " RESET);
				clearInputBuffer();
			}
			clearInputBuffer();
		}
	}

	do {
		int machineID, machineIndex, sensorIndex;
		float power, newReading;

		printf("\n");
		displayTitle();
		displayMenu();
		printf("Enter choice: ");

		while (scanf("%d", &choice) != 1 || choice < 1 || choice > 11) {
			printf(RED "Invalid choice. Enter 1 to 11: " RESET);
			clearInputBuffer();
		}
		clearInputBuffer();

		if (choice == 1) {
			if (machineCount == 0) {
				printf(RED "No machines available.\n" RESET);
			} else {
				for (i = 0; i < machineCount; i++) {
					displayMachineInfo(machines + i);
				}
			}
		} else if (choice == 2) {
			printf("Enter Machine ID: ");
			scanf("%d", &machineID);
			clearInputBuffer();
			machineIndex = findMachineByID(machines, machineCount, machineID);
			if (machineIndex == -1) {
				printf(RED "Machine not found.\n" RESET);
			} else {
				power = computePower(machines + machineIndex);
				printf(YELLOW"\nComputed Power: "RESET"%.2f W\n", power);
				switch (classifyPowerLevel(power)) {
					case 1: printf(YELLOW"Classification: "RESET"LOW POWER\n"); break;
					case 2: printf(YELLOW"Classification: "BRIGHTGREEN"NORMAL POWER\n"RESET); break;
					default: printf(YELLOW"Classification: "BRIGHTRED"HIGH POWER\n"RESET); break;
				}
			}
		} else if (choice == 3) {
			printf("Enter Machine ID: ");
			scanf("%d", &machineID);
			clearInputBuffer();
			machineIndex = findMachineByID(machines, machineCount, machineID);
			if (machineIndex == -1) {
				printf(RED "Machine not found.\n" RESET);
			} else {
				printf("Enter Sensor Index (0 to %d): ", (machines + machineIndex)->sensorCount - 1);
				scanf("%d", &sensorIndex);
				clearInputBuffer();
				if (sensorIndex < 0 || sensorIndex >= (machines + machineIndex)->sensorCount) {
					printf(RED "Invalid sensor index.\n" RESET);
				} else {
					printf(YELLOW"Sensor type:"RESET" %s\n", (machines + machineIndex)->sensor[sensorIndex].type);
					printf(YELLOW"Sensor range [min, max]: "RESET"[%.2f, %.2f]\n", (machines + machineIndex)->sensor[sensorIndex].min, (machines + machineIndex)->sensor[sensorIndex].max);
					printf(YELLOW"Current reading: "RESET"%.2f\n", (machines + machineIndex)->sensor[sensorIndex].reading);
					printf(checkSensorStatus(machines + machineIndex, sensorIndex) ? BRIGHTGREEN "WITHIN RANGE\n" RESET : BRIGHTRED "OUT OF RANGE\n" RESET);
				}
			}
		} else if (choice == 4) {
			printf("Enter Machine ID: ");
			scanf("%d", &machineID);
			clearInputBuffer();
			machineIndex = findMachineByID(machines, machineCount, machineID);
			if (machineIndex == -1) {
				printf(RED "Machine not found.\n" RESET);
			} else {
				printf("Enter Sensor Index (0 to %d): ", (machines + machineIndex)->sensorCount - 1);
				scanf("%d", &sensorIndex);
				clearInputBuffer();
				if (sensorIndex < 0 || sensorIndex >= (machines + machineIndex)->sensorCount) {
					printf(RED "Invalid sensor index.\n" RESET);
				} else {
					printf(YELLOW"Sensor type:"RESET" %s\n", (machines + machineIndex)->sensor[sensorIndex].type);
					printf(YELLOW"Sensor range [min, max]: "RESET"[%.2f, %.2f]\n", (machines + machineIndex)->sensor[sensorIndex].min, (machines + machineIndex)->sensor[sensorIndex].max);
					printf(YELLOW"Current reading: "RESET"%.2f\n", (machines + machineIndex)->sensor[sensorIndex].reading);
					printf("Enter New Reading: ");
					scanf("%f", &newReading);
					clearInputBuffer();
					updateSensorReading(machines + machineIndex, sensorIndex, newReading);
				}
			}
		} else if (choice == 5) {
			printf("Enter Machine ID: ");
			scanf("%d", &machineID);
			clearInputBuffer();
			machineIndex = findMachineByID(machines, machineCount, machineID);
			if (machineIndex == -1) {
				printf(RED "Machine not found.\n" RESET);
			} else {
				printf("Average Sensor Reading: %.2f\n", computeAverageSensorReading(machines + machineIndex));
			}
		} else if (choice == 6) {
			printf("Enter Machine ID: ");
			scanf("%d", &machineID);
			clearInputBuffer();
			machineIndex = findMachineByID(machines, machineCount, machineID);
			if (machineIndex == -1) {
				printf(RED "Machine not found.\n" RESET);
			} else {
				printf("Out-of-Range Sensors: %d\n", countOutOfRangeSensors(machines + machineIndex));
			}
		} else if (choice == 7) {
			printf("Enter Machine ID to find: ");
			scanf("%d", &machineID);
			clearInputBuffer();
			machineIndex = findMachineByID(machines, machineCount, machineID);
			if (machineIndex == -1) {
				printf(RED "Machine not found.\n" RESET);
			} else {
				printf(BRIGHTGREEN "Machine found at index %d.\n" RESET, machineIndex);
				displayMachineInfo(machines + machineIndex);
			}
		} else if (choice == 8) {
			printf("Total Power of All Machines: %.2f W\n", computeTotalPowerAllMachines(machines, machineCount));
		} else if (choice == 9) {
			machineIndex = getHighestPowerMachine(machines, machineCount);
			if (machineIndex == -1) {
				printf(RED "No machines available.\n" RESET);
			} else {
				printf(BRIGHTYELLOW "Machine with Highest Power:\n" RESET);
				displayMachineInfo(machines + machineIndex);
			}
		} else if (choice == 10) {
			printf("Enter Machine ID to remove: ");
			scanf("%d", &machineID);
			clearInputBuffer();
			removeMachine(machines, &machineCount, machineID);
		}
	} while (choice != 11);

	free(machines);
	printf(BRIGHTGREEN "\nMemory freed. Exiting...\n" RESET);
	return 0;
}

/* 	Butar, Daryl D.	24-5865-705	BSCPE	
	CPE264 H1 2ndSem2526
	Activity 4
	February 26, 2026
*/
