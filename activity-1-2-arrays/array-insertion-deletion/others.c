#include <stdio.h>
#include "others.h"
#include "windows.h"

// Function to display the Program Title
void displayTitle() {
	printf("Array Management System\n\n");
}

// Function to get integer input from user
int getUserInput() {
	int num;
	while (scanf("%d", &num) != 1) {
	    printf(RED "Error! Integers only " RESET);
		printf(YELLOW "Try again: " RESET);
	    while (getchar() != '\n');  // Clear the buffer
	}
	return num;
}

// Function to display text menu
void showMainMenu() {
	printf(YELLOW "[=---- MAIN MENU ----=]\n" RESET);
	printf("     (1) SEARCH\n");
	printf("     (2) DISPLAY\n");
	printf("     -----------\n");
	printf(BRIGHTGREEN "     (3) INSERT\n" RESET);
	printf(BRIGHTRED "     (4) DELETE\n" RESET);
	printf("     -----------\n");
	printf("     (0) EXIT\n");
	printf(YELLOW "[=-------------------=]\n" RESET);
}

// Function to display menu for INSERT operations
void showInsertMenu() {
	printf(YELLOW "[=-------- INSERT MENU --------=]\n" RESET);
	printf(BRIGHTGREEN"     (1) Insert Front\n"RESET);
	printf(BRIGHTRED"     (2) Insert End\n"RESET);
	printf("     -----------------------\n");
	printf("     (3) Insert at Position\n");
	printf("     (4) Insert after Value\n");
	printf("     -----------------------\n");
	printf("     (0) BACK\n");
	printf(YELLOW "[=-----------------------------=]\n" RESET);
}

// Function to display menu for DELETE operations
void showDeleteMenu() {
	printf(YELLOW "[=---------- DELETE MENU ----------=]\n" RESET);
	printf(BRIGHTGREEN"     (1) Delete at Position\n"RESET);
	printf(BRIGHTRED"     (2) Delete by Value\n"RESET);
	printf("     -----------------------\n");
	printf("     (3) Delete All Occurences\n");
	printf("     (4) Delete 2nd Smallest\n");
	printf("     (5) Delete 2nd Largest\n");
	printf("     -----------------------\n");
	printf("     (0) BACK\n");
	printf(YELLOW "[=---------------------------=]\n" RESET);
}

// Function to get input from user, range for selection starts from 0
void validateMenuChoice(int *choice, int range) {
	printf(YELLOW "\nEnter choice: " RESET);
	do {
		
		*choice = getUserInput();
		if((*choice<0 || *choice>range)) {
			printf(RED "Error! Out of range." RESET);
			printf(YELLOW "Try again: " RESET);
		} else {
			break;
		}
	} while (1);
}

