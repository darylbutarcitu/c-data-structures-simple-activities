#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "others.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {
	int size;
	
	getUserInput(&size);	// Get input from user
	
	int arr[size];
	
	// Populate via user input and display
	populateArray(arr, size);	
	displayArray(arr, size);
	
	displayMedian(arr, size);				// TASK 1
	displayMode(arr, size);					// TASK 2
	displayStandardDeviation(arr, size);	// TASK 3
	displayRange(arr, size);				// TASK 4
	displayFreqTable(arr, size);			// TASK 5
	displayCumulativeSum(arr, size);		// TASK 6
	displayPercentDistribution(arr, size);	// TASK 7
	
	return 0;
}

// Butar, Daryl D. Activity 1: Array CPE264H1-2ndSem2-2526
