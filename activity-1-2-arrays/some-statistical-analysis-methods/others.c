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
	scanf("%d", size);
	printf("Size: %d", *size);
	printf("\n");
}
