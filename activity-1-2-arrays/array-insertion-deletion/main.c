#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include "array.h"
#include "others.h"

int main(void) {
	int choice, value, position, arr[SIZE] = {0}, count = 0;
	bool isBack = false;
	
	// Main menu loop
	while(1){
		system("cls");
		displayTitle();
		showMainMenu();
		displayCapacity(count);
		display(arr, count);
		validateMenuChoice(&choice, 4);
		
		switch(choice) {
			case 1: // SEARCH
				if(count==0) printf(BRIGHTRED"Array EMPTY! Cannot perform SEARCH operation.\n"RESET);
				else {
					printf("Enter value to search: ");
					position = search(arr, count, getUserInput());
					if(position!=-1) {
						printf("Element %d is found at index "BRIGHTGREEN"%d"RESET, arr[position], position);
					} else {
						printf(BRIGHTRED"Value not found."RESET);
					}
				}
				break;
				
			case 2: // DISPLAY
				system("cls");
				displayTitle();
				displayCapacity(count);
				display(arr, count);
				break;
				
			case 3: // INSERT OPERATIONS
				if(count==SIZE) {
					printf(BRIGHTRED"Array FULL! Cannot perform INSERT operations.\n"RESET);
					break;
				}
				while(!isBack) {
					system("cls");
					showInsertMenu();
					displayCapacity(count);
					display(arr, count);
					validateMenuChoice(&choice, 4);
					
					switch(choice) {
						case 1: // INSERT FRONT
							printf("Enter "YELLOW"value"RESET" to insert at front: ");
							insertBeginning(arr, &count, getUserInput());
							break;
						case 2: // INSERT END
							printf("Enter "YELLOW"value"RESET" to insert at end: ");
							insertEnd(arr, &count, getUserInput());
							break;
						case 3: // INSERT AT POSITION
							printf("Enter "YELLOW"value"RESET" to insert: ");
							value = getUserInput();
							printf("Enter "YELLOW"position"RESET": ");
							while((position = getUserInput()) < 0 || position > count)
								printf(BRIGHTRED"Invalid position! Out of range.\n"RESET"Enter "YELLOW"position"RESET": ");
							insertAtPosition(arr, &count, position, value);
							break;
						case 4: // INSERT AFTER VALUE
							printf("Enter "YELLOW"value"RESET" to insert: ");
							value = getUserInput();
							printf("Enter "YELLOW"target"RESET" element: ");
							insertAfterValue(arr, &count, getUserInput(), value);
							break;
						default:
							isBack = true;
							continue;
					}
					if(count==SIZE) {
						printf(RED"\nArray Capacity [%d/%d] Full!\n"RESET, count, SIZE);
						break;
					}
					printf("\nPress any key to continue...");
					getch();
				}
				isBack = false;
				break;
				
			case 4: // DELETE OPERATIONS
				if(count==0) {
					printf(BRIGHTRED"Array EMPTY! Cannot perform DELETE operations.\n"RESET);
					break;
				}
				while(!isBack) {
					system("cls");
					showDeleteMenu();
					displayCapacity(count);
					display(arr, count);
					validateMenuChoice(&choice, 5);
					
					switch(choice) {
						case 1: // DELETE AT POSITION
							printf("Enter position of element to delete: ");
							while((position = getUserInput()) < 0 || position >= count)
								printf(BRIGHTRED"Invalid Position! Out of range.\n"RESET"Enter position: ");
							deleteAtPosition(arr, &count, position);
							break;
						case 2: // DELETE BY VALUE
							printf("Enter value to delete: ");
							deleteByValue(arr, &count, getUserInput());
							break;
						case 3: // DELETE ALL OCCURRENCES
							printf("Enter value to delete: ");
							deleteAllOccurrences(arr, &count, getUserInput());
							break;
						case 4: // DELETE 2ND SMALLEST
							deleteSecondSmallest(arr, &count);
							break;
						case 5: // DELETE 2ND LARGEST
							deleteSecondLargest(arr, &count);
							break;
						default:
							isBack = true;
							continue;
					}
					if(count==0) {
						printf(RED"\nArray Capacity [%d/%d] Empty!\n"RESET, count, SIZE);
						break;
					}
					printf("\nPress any key to continue...");
					getch();
				}
				isBack = false;
				break;
				
			default: // EXIT
				printf("\nExiting program...");
				return 0;
		}
		printf("\nPress any key to continue...");
		getch();
	}
}

/* 	Butar, Daryl D.	24-5865-705	BSCPE	
	CPE264 H1 2ndSem2526
	Activity 2
	February 16, 2026
*/
