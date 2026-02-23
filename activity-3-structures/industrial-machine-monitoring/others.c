#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "others.h"

// Function to display project/activity title
void displayTitle() {
	printf("INDUSTRIAL MACHINE MONITORING SYSTEM\n");
}

// Function to get and validate integer input from user
int getIntegerInput() {
	char buffer[100];
	char *end;	// holds the first char detected after scanning numbers in a string
	long value;
	
	while(1) {
		fgets(buffer,sizeof(buffer),stdin);
		
		
		value = strtol(buffer, &end, 10); // convert text to number
		
		if(strcmp(buffer, "\n")) {	// If input is not empty or newline
			if(*end == '\n') {	// if stopper is a new line character
				return (int)value;	// the whole input is a valid number, cast as int
			}
		}	
		
	    printf(RED "Invalid input! " RESET YELLOW "Try again: " RESET);
	}
}

// Function to get and validate floating point input from user
float getFloatInput() {
	char buffer[100];
	char *end;	// holds the first char detected after scanning numbers in a string
	float value;
	
	while(1) {
		if(!fgets(buffer,sizeof(buffer),stdin)) {	// if reading fails
			continue;
		}
		value = strtof(buffer, &end); // convert text to float
		
		while(*end == ' ') {	// skip white spaces
			end++;
		}
		
		if(strcmp(buffer, "\n")) {	// If input is not empty or newline
			if(*end == '\n') {	// if stopper is a new line character
				return value;	// the whole input is a valid float
			}	
		}
		
	    printf(RED "Invalid input! " RESET YELLOW "Try again: " RESET);;
	}
}

// Function to get and validate floating point input from user
void getStringInput(char* string) {
    char* buffer = (char*)calloc(50, sizeof(char));

    while (1) {
    	// Check if string input is empty: newline or whitespaces only
        if (scanf("%49[^\n]", buffer) != 1 || isAllWhitespace(buffer)) {
            getchar(); // clear newline
            printf(RED "Empty input! " RESET YELLOW "Try again: " RESET);
            continue;
        }

        getchar(); // clear newline
        strcpy(string, buffer);
        free(buffer);	// release allocation
        break;
    }
}

// Function to check if a string contains only whitespace until newline
int isAllWhitespace(char* string) {
	int i;
    for (i = 0; string[i] != '\0'; i++) {
        // Stop checking at newline
        if (string[i] == '\n') {
        	break;
		}

        // If any non-whitespace character is found, return false
        if (!isspace((unsigned char)string[i])) {
            return 0;
        }
    }
    return 1; // All whitespace
}

