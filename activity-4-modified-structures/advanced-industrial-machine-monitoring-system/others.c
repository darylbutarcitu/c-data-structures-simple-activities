#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "others.h"

// Function to display project/activity title
void displayTitle() {
	printf(BRIGHTYELLOW"======= INDUSTRIAL MACHINE MONITORING SYSTEM =======\n"RESET);
}

// Function to display menu
void displayMenu() {
	printf("\t1. Display All Machines\n");
	printf("\t2. Compute and Classify Power of a Machine\n");
	printf("\t3. Check Sensor Status\n");
	printf("\t4. Update Sensor Reading\n");
	printf("\t5. Compute Average Sensor Reading\n");
	printf("\t6. Count Out-of-Range Sensors\n");
	printf("\t7. Find Machine by ID\n");
	printf("\t8. Compute Total Power of All Machines\n");
	printf("\t9. Show Machine with Highest Power\n");
	printf("\t10. Remove Machine\n");
	printf(BRIGHTRED"\t11. Exit\n"RESET);
	printf(YELLOW "[=------------------------------------------------=]\n" RESET);
}

// Function to removes leftover characters from input buffer
void clearInputBuffer(void) {
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}

// Function to read a full line of input and replace \n with \0
void readLine(char *buffer, int size) {
	if (fgets(buffer, size, stdin) != NULL) {
		buffer[strcspn(buffer, "\n")] = '\0';
	}
}

