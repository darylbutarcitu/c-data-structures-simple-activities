#ifndef ARRAY_H
#define ARRAY_H

void populateArray(int arr[], int size);
void displayArray(int arr[], int size);
void sortAscending(int arr[], int size);

void displayMedian(int arr[], int size);				// TASK 1
float getMedian(int arr[], int start, int end);

void displayMode(int arr[], int size);					// TASK 2

/*** TASK 3 */
void displayStandardDeviation(int arr[], int size);
double getMean(int arr[], int size);
double getVariance(int arr[], int size);
/* TASK 3 ***/

void displayRange(int arr[], int size);					// TASK 4
void displayFreqTable(int arr[], int size);				// TASK 5
void displayCumulativeSum(int arr[], int size);			// TASK 6
void displayPercentDistribution(int arr[], int size);	// TASK 7

#endif // ARRAY_H
