#ifndef OTHERS_H
#define OTHERS_H

// Text color code
#define RESET   		"\033[0m"
#define YELLOW  		"\033[33m"
#define BRIGHTYELLOW	"\033[93m"
#define RED     		"\033[31m"
#define BRIGHTRED   	"\033[91m"
#define GREEN   		"\033[32m"
#define BRIGHTGREEN   	"\033[92m"

/* Function Prototypes */
void displayTitle();

int getIntegerInput();
float getFloatInput();
void getStringInput(char* string);

int isAllWhitespace(char* string); // helper method of getStringInput(char* string);


#endif
