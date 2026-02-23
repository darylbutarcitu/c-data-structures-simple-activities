#include <stdio.h>
#include "array.h"
#include "others.h"

// Function to search an element in the array and return the index
int search(int arr[], int count, int value) {
	int i;
	for(i=0; i<count; i++) {
		if(arr[i]==value) {
			return i;
		}
	}
	return -1;
}

// Function to Display all elements in the array
void display(int arr[], int count) {
	int i;
	printf("   Array = "YELLOW"{");
	for(i=0; i<count; i++) {
		printf("%d, ", arr[i]);
	}
	if(count!=0) {
		printf("\b\b");	
	} else {
		printf(RED"\b{EMPTY");
	}
	printf("}\n"RESET);
}

// Function to Display capacity of array
void displayCapacity(int count) {
	printf("Capacity = %d out of %d", count, SIZE);
	if(count==SIZE) {
		printf(BRIGHTRED" (FULL)" RESET);
	}
	printf("\n");
}

// Function to insert an element at the front
void insertBeginning(int arr[], int *count, int value) {
	int i;
	printf(YELLOW "\nOPERATION:" RESET " INSERT BEGINNING\n");
	// Check for overflow
	if(*count == SIZE) {
		printf(BRIGHTRED"INSERT failed! Array is FULL.\n"RESET);
		return;
	}
	
	for(i=*count; i>0; i--) {
		arr[i] = arr[i-1];
	}
	arr[0] = value;
	(*count)++;
	printf("Value "BRIGHTGREEN"%d"RESET" inserted at the front!\n", value);
}

// Function to insert an element at the end
void insertEnd(int arr[], int *count, int value) {
	printf(YELLOW "\nOPERATION:" RESET " INSERT END\n");
	// Check for overflow
	if(*count == SIZE) {
		printf(BRIGHTRED"INSERT failed! Array is FULL.\n"RESET);
		return;
	}
	
	arr[(*count)++] = value;
	printf("Value "BRIGHTRED"%d"RESET" inserted at the end!\n", value);
}

// Function to insert an element at a position
void insertAtPosition(int arr[], int *count, int position, int value) {
	int i;
	printf(YELLOW "\nOPERATION:" RESET " INSERT AT POSITION\n");
	// Check for overflow
	if(*count == SIZE) {
		printf(BRIGHTRED"INSERT failed! Array is FULL.\n"RESET);
		return;
	}
	
	for(i=*count; i>position; i--) {
		arr[i] = arr[i-1];
	}
	arr[position] = value;
	(*count)++;
	printf("Value "BRIGHTRED"%d"RESET" inserted at position %d!\n", value, position);
}

// Function to insert an element after a value
void insertAfterValue(int arr[], int *count, int target, int value) {
	int i, pos;
	printf(YELLOW "\nOPERATION:" RESET " INSERT AFTER A GIVEN VALUE\n");
	pos = search(arr, *count, target);

	if(pos != -1) {
		// Check for overflow
		if(*count == SIZE) {
			printf(BRIGHTRED"INSERT failed! Array is FULL.\n"RESET);
			return;
		}
		for(i=*count; i>pos+1; i--) {
			arr[i] = arr[i-1];
		}
		arr[pos+1] = value;
		(*count)++;
		printf("\nElement " YELLOW "%d" RESET " inserted after target value %d at position %d.\n", value, target, pos + 1);
	} else {
		printf(BRIGHTRED "\nINSERT failed! Target value %d not found.\n" RESET, target);
	}
}

// Function to delete an element at a given position
void deleteAtPosition(int arr[], int *count, int position) {
	int i, deleted;
	printf(YELLOW "\nOPERATION:" RESET " DELETE AT POSITION\n");
	deleted = arr[position];
	
	for(i=position; i<*count-1; i++) {
		arr[i] = arr[i+1];
	}
	arr[--(*count)] = 0;
	
	printf("\nDeleted an occurence of "BRIGHTGREEN"%d"RESET" (Position: %d).\n", deleted, position);
}

// Function to delete the first occurence of a given value
void deleteByValue(int arr[], int *count, int value){
	int i, pos;
	printf(YELLOW "\nOPERATION:" RESET " DELETE BY VALUE\n");
	pos = search(arr, *count, value); // Get index of target using search function
		
	if(pos!=-1) {
		for(i=pos; i<*count-1; i++) {
			arr[i] = arr[i+1];
		}
		arr[--(*count)] = 0;
		printf("\nDeleted an occurence of "BRIGHTGREEN"%d"RESET" (Position: %d).\n", value, pos);
		return;
	}
	
	printf(BRIGHTRED"\nDELETE failed! Target value %d not found.\n"RESET, value);
}

// Function to delete the all occurences of a given value
void deleteAllOccurrences(int arr[], int *count, int value){
	int i, pos, occurence = 0;
	printf(YELLOW "\nOPERATION:" RESET " DELETE ALL OCCURENCES OF A VALUE\n");
	
	// use search function as loop condition
	while((pos = search(arr, *count, value))!=-1){
		for(i=pos; i<*count-1; i++) {
			arr[i] = arr[i+1];
		}
		arr[--(*count)] = 0;
		occurence++;
	}
	
	if(occurence>0) {
		printf("\nDeleted %d occurence/s of "BRIGHTGREEN"%d\n"RESET, occurence, value);
	} else {
		printf(BRIGHTRED"\nDELETE failed! Target value %d not found.\n"RESET, value);
	}
}

// Function to delete the second smallest element
void deleteSecondSmallest(int arr[], int *count){
	int i, pos, min1, min2;
	printf(YELLOW "\nOPERATION:" RESET " DELETE 2ND SMALLEST ELEMENT\n");
	
	if(*count<2) {
		printf(BRIGHTRED"\nDELETE failed! Array has only 1 element.\n"RESET);
		return;
	}
	
	// Initialize min1 and min2 from first two elements
	if(arr[0] <= arr[1]) {
		min1 = arr[0];
		min2 = arr[1];
	} else {
		min1 = arr[1];
		min2 = arr[0];
	}
	
	// Find the two smallest values
	for(i=2; i<*count; i++) {
		if(arr[i]<min1) {
			min2 = min1;
			min1 = arr[i];
		} else if(arr[i]<min2) {
			min2 = arr[i];
		}
	}
	
	printf("\nFound 2nd smallest value: "YELLOW"%d\n"RESET, min2);
	
	pos = search(arr, *count, min2);
	for(i=pos; i<*count-1; i++) {
		arr[i] = arr[i+1];
	}
	arr[--(*count)] = 0;
	printf("\nDeleted an occurence of "BRIGHTGREEN"%d"RESET" (Position: %d).\n", min2, pos);
}

// Function to delete the second largest element
void deleteSecondLargest(int arr[], int *count){
	int i, pos, max1, max2;
	printf(YELLOW "\nOPERATION:" RESET " DELETE 2ND LARGEST ELEMENT\n");
	
	if(*count<2) {
		printf(BRIGHTRED"\nDELETE failed! Array has only 1 element.\n"RESET);
		return;
	}
	
	// Initialize max1 and max2 from first two elements
	if(arr[0] >= arr[1]) {
		max1 = arr[0];
		max2 = arr[1];
	} else {
		max1 = arr[1];
		max2 = arr[0];
	}
	
	// Find the two largest values
	for(i=2; i<*count; i++) {
		if(arr[i]>max1) {
			max2 = max1;
			max1 = arr[i];
		} else if(arr[i]>max2) {
			max2 = arr[i];
		}
	}
	
	printf("\nFound 2nd largest value: "YELLOW"%d\n"RESET, max2);
	
	pos = search(arr, *count, max2);
	for(i=pos; i<*count-1; i++) {
		arr[i] = arr[i+1];
	}
	arr[--(*count)] = 0;
	printf("\nDeleted an occurence of "BRIGHTGREEN"%d"RESET" (Position: %d).\n", max2, pos);
}
