#ifndef ARRAY_H
#define ARRAY_H

#define SIZE 10

// Display functions
int search(int arr[], int count, int value);
void display(int arr[], int count);
void displayCapacity(int count);

// Insert operations
void insertBeginning(int arr[], int *count, int value);
void insertEnd(int arr[], int *count, int value);
void insertAtPosition(int arr[], int *count, int position, int value);
void insertAfterValue(int arr[], int *count, int target, int value);

// Delete operations
void deleteAtPosition(int arr[], int *count, int position);
void deleteByValue(int arr[], int *count, int value);
void deleteAllOccurrences(int arr[], int *count, int value);
void deleteSecondSmallest(int arr[], int *count);
void deleteSecondLargest(int arr[], int *count);


#endif
