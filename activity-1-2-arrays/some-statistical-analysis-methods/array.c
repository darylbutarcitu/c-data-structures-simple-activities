#include <stdio.h>
#include <math.h>
#include "array.h"
#include "others.h"

// Function to populate array via user input (with error handling)
void populateArray(int arr[], int size) {
	int i;
	printDivider('-', 50);
	printf("Enter values: \n");
	for(i=0; i<size; i++) {
		printf("Element %d: ", i);
		while (scanf("%d", &arr[i]) != 1) {
		    printf(RED "Invalid input! Try again.\n" RESET);
			printf("Element %d: ", i);
		    while (getchar() != '\n');  // Clear the buffer
		}
	}
	printDivider('-', 50);
}

// Function to display array elements
void displayArray(int arr[], int size){
	int i;
	printf("Array: ");
	for(i=0; i<size; i++) {
		printf(" %d", arr[i]);
	}
	printf("\n");
}

// Function to sort array ascendingly and display
void sortAscending(int arr[], int size){
	int i, j, temp;
	
	for(i=0; i<size-1; i++) {
		for(j=i+1; j<size; j++) {
			if(arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	
	printf("Sorted ");
	// Call function to display array
	displayArray(arr, size);
}

// TASK 1: Function to display the sorted array and computed median.
void displayMedian(int arr[], int size) {
	
	printf(YELLOW"\n");
	printDivider('=', 50);
	printf("TASK #1 MEDIAN OF ARRAY ELEMENTS\n" RESET);
	
	// Call function to sort array
	sortAscending(arr, size);

	printf("Median: %.1f\n", getMedian(arr, 0, size-1));
}

float getMedian(int arr[], int start, int end) {
	int len = end-start+1;
	int mid = start+len/2;

	if(len%2==0) {	// even array size
		return ((arr[mid-1] + arr[mid])/2.0);
	} else {	// odd array size
		return  arr[mid];
	}
}


// TASK 2: Function to display mode (most frequent element)
void displayMode(int arr[], int size) {
	printf(YELLOW"\n");
	printDivider('=', 50);
	printf("TASK #2 MODE (MOST FREQUENT ELEMENT)\n" RESET);
	
	int maxCount = 0;
    int i, j;
    // Find the highest frequency
    for (i = 0; i < size; i++) {
        int count = 0;
        for (j = 0; j < size; j++) {
            if (arr[j] == arr[i]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
        }
    }
    
    // Check if all elements appear only once
    if (maxCount == 1) {
        printf("No mode - all elements appear only once");
    } else {
    	int i, j, k;
        // Display all elements with the highest frequency
        printf("Mode:");
        for (i = 0; i < size; i++) {
            int count = 0;
            for (j = 0; j < size; j++) {
                if (arr[j] == arr[i]) {
                    count++;
                }
            }
            
            // Display if it has max frequency and hasn't been displayed yet
            if (count == maxCount) {
                int alreadyShown = 0;
                for (k = 0; k < i; k++) {
                    if (arr[k] == arr[i]) {
                        alreadyShown = 1;
                        break;
                    }
                }
                if (!alreadyShown) {
                    printf(" %d", arr[i]);
                }
            }
        }
        printf(" (frequency: %d)", maxCount);
    }
    printf("\n");
}

// TASK 3: Function to display the mean, variance, and standard deviation.
void displayStandardDeviation(int arr[], int size) {
	printf(YELLOW"\n");
	printDivider('=', 50);
	printf("TASK #3 STANDARD DEVIATION\n" RESET);
	printf("Mean: %.1lf", getMean(arr,size));
	printf("\nVariance: %.1lf", getVariance(arr,size));
	printf("\nStandard Deviation: %.1lf\n", sqrt(getVariance(arr,size)));
}

// Function to Calculate the mean
double getMean(int arr[], int size){
	double sum = 0;
	int i;
	
	for(i=0; i<size; i++) {
		sum+=arr[i];
	}
	
	return sum/(double)size;
}

// Function to Calculate the variance
double getVariance(int arr[], int size) {
	double sum = 0;
	double mean = getMean(arr,size);
	int i = 0;
	for(i=0; i<size; i++) {
		sum += pow((arr[i]-mean),2);
	}
	
	return sum/(double)size;
}

// TASK 4: Function to display the range, Q1, Q3, and IQR.
void displayRange(int arr[], int size) {
    float range, q1, q3, iqr;
    printf(YELLOW"\n");
    printDivider('=', 50);
    printf("TASK #4 RANGE AND INTERQUARTILE RANGE (IQR)\n" RESET);
    
    sortAscending(arr, size);
    
    
    range = arr[size-1] - arr[0];
    if(size%2==0) { // even
    	q1 = getMedian(arr, 0, (size/2) -1);
    	q3 = getMedian(arr, size/2, size-1);
	}
	else{
    	q1 = getMedian(arr, 0, (size/2) - 1);
    	q3 = getMedian(arr, size/2 + 1, size-1);
	}
    iqr = q3 - q1;

    printf("Range: %.1f", range);
    printf("\nQ1: %.1f", q1);
    printf("\nQ3: %.1f", q3);
    printf("\nIQR: %.1f\n", iqr);
}

// TASK 5: Function to display Frequency Distribution Table
void displayFreqTable(int arr[], int size) {
	int i, j, k;
	
	printf(YELLOW"\n");
	printDivider('=', 50);
	printf("TASK #5 FREQUENCY DISTRIBUTION TABLE\n" RESET);
	
	printf("Element\t\tFrequency\n");
	printDivider('-', 30);
	
	// Loop through each element
	for (i = 0; i < size; i++) {
		// Check if this element was already displayed
		int alreadyShown = 0;
		for (k = 0; k < i; k++) {
			if (arr[k] == arr[i]) {
				alreadyShown = 1;
				break;
			}
		}
		
		// If not already shown, count and display it
		if (!alreadyShown) {
			int count = 0;
			for (j = 0; j < size; j++) {
				if (arr[j] == arr[i]) {
					count++;
				}
			}
			printf("%d\t\t%d\n", arr[i], count);
		}
	}
	printf("\n");
}

// TASK 6: Function to display Cumulative Sum
void displayCumulativeSum(int arr[], int size) {
	printf(YELLOW"\n");
	printDivider('=', 50);
	printf("TASK #6 CUMULATIVE SUM (PREFIX SUM)\n" RESET);
	
	int i, newArr[size];
	newArr[0] = arr[0];
	
	for(i=1; i<size; i++) {
		newArr[i] = newArr[i-1] + arr[i];
	}
	
	printf("Original ");
	// Call function to display array
	displayArray(arr, size);
	
	printf("Cumulative Sum: ");
	for(i=0; i<size; i++) {
		printf(" %d", newArr[i]);
	}
	printf("\n");
}

// TASK 7: Function to display Percentage Distribution
void displayPercentDistribution(int arr[], int size) {
	printf(YELLOW"\n");
	printDivider('=', 50);
	printf("TASK #7 PERCENTAGE DISTRIBUTION\n" RESET);
	int sum = 0;
	int i;
	
	for (i = 0; i < size; i++) {
		sum += arr[i];
	}
	
	// Display table
	printf("Index\t\tValue\t\tPercentage (%%)\n");
	printDivider('-', 50);
	
	float runningTotal = 0;
	for (i = 0; i < size; i++) {
		float percentage = (arr[i] / (float)sum) * 100;
		printf("%d\t\t%d\t\t%.2f%%\n", i, arr[i], percentage);
		runningTotal += percentage;
	}
	printDivider('-', 50);
	printf("\t\tTotal:\t\t%.2f%%\n", runningTotal);
}
