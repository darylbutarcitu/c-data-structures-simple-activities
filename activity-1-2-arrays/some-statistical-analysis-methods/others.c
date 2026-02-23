#include <stdio.h>
#include "others.h"

// Function to display custom dividers using a single character
void printDivider(char ch, int length) {
	int i;
	
	if(length > 0) {
	  for(i=0; i<length; i++){
	       printf("%c", ch);
	  }
	  printf("\n");
	}
}

// Function to get user input
void getUserInput(int *size) {
	printf("Enter size of array: ");
	while (scanf("%d", size) != 1 || *size <= 0) {
		printf(RED "Invalid size! Enter a positive integer: " RESET);
		while (getchar() != '\n');
	}
	printf("Size: %d", *size);
	printf("\n");
}
