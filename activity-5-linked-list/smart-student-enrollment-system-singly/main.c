#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Enrol.h"
#include "others.h"

// Reads an integer safely using prompt-based input.
static int readInt(const char* prompt, int* out) {
	printf("%s", prompt);
	if(scanf("%d", out) != 1) {
		clearInputBuffer();
		return 0;
	}
	clearInputBuffer();
	return 1;
}

// Reads a floating-point value safely using prompt-based input.
static int readFloat(const char* prompt, float* out) {
	printf("%s", prompt);
	if(scanf("%f", out) != 1) {
		clearInputBuffer();
		return 0;
	}
	clearInputBuffer();
	return 1;
}

// Collects student fields from user and returns a new node.
static Studentptr inputStudent(void) {
	int id;
	int yearLevel;
	float gpa;
	char fullName[SIZE];
	char program[SIZE];

	if(!readInt("Student ID: ", &id)) {
		printf(RED "Invalid student ID.\n" RESET);
		return NULL;
	}

	printf("Full Name: ");
	readLine(fullName, SIZE);
	printf("Program: ");
	readLine(program, SIZE);

	if(!readInt("Year Level (1-5): ", &yearLevel)) {
		printf(RED "Invalid year level.\n" RESET);
		return NULL;
	}

	if(!readFloat("GPA (0.0-4.0): ", &gpa)) {
		printf(RED "Invalid GPA.\n" RESET);
		return NULL;
	}

	if(yearLevel < 1 || yearLevel > 5 || gpa < MIN_GPA || gpa > MAX_GPA) {
		printf(RED "Invalid year level or GPA range.\n" RESET);
		return NULL;
	}

	return createStudent(id, fullName, program, yearLevel, gpa);
}

// Runs the menu-driven Smart Enrollment System.
int main(void) {
	int choice = 0; 	// User menu choice
	int id;
	int pos;
	int n;
	int beforeCount;
	int afterCount;
	int promoted;
	int removed;
	float avg;
	List head = NULL;
	Studentptr student;
	
	// Main Program Loop
	do {
		system("cls"); // clear screen
		displayTitle();
		displayMenu();
		printf("Enter choice: ");
		while (scanf("%d", &choice) != 1 || choice < 1 || choice > 13) {
			printf(RED "Invalid choice. Enter 1 to 13: " RESET);
			clearInputBuffer();
		}
		clearInputBuffer();
		
		switch(choice) {
			case 1:	// Regular Enrolment
				student = inputStudent();
				if(student == NULL) {
					break;
				}
				beforeCount = getCount(head);
				head = regEnrol(head, student);
				afterCount = getCount(head);
				if(afterCount > beforeCount) {
					printf(BRIGHTGREEN "Regular enrollment successful.\n" RESET);
				} else {
					printf(RED "Enrollment failed (duplicate ID).\n" RESET);
				}
				break;
			case 2:	// Priority Enrolment
				student = inputStudent();
				if(student == NULL) {
					break;
				}
				beforeCount = getCount(head);
				head = priorityEnrol(head, student);
				afterCount = getCount(head);
				if(afterCount > beforeCount) {
					printf(BRIGHTGREEN "Priority enrollment successful.\n" RESET);
				} else {
					printf(RED "Priority enrollment failed (GPA >= 3.0 and unique ID required).\n" RESET);
				}
				break;
			case 3:	// Manual Insert
				student = inputStudent();
				if(student == NULL) {
					break;
				}
				if(!readInt("Position to insert (start at 1): ", &pos)) {
					free(student);
					printf(RED "Invalid position.\n" RESET);
					break;
				}
				if(pos < 1 || pos > getCount(head) + 1) {
					free(student);
					printf(RED "Invalid position.\n" RESET);
					break;
				}
				beforeCount = getCount(head);
				head = manualEnrol(head, student, pos);
				afterCount = getCount(head);
				if(afterCount > beforeCount) {
					printf(BRIGHTGREEN "Manual insert successful.\n" RESET);
				} else {
					printf(RED "Manual insert failed (duplicate ID).\n" RESET);
				}
				break;
			case 4:	// Late Enrollment
				student = inputStudent();
				if(student == NULL) {
					break;
				}
				beforeCount = getCount(head);
				head = lateEnrol(head, student);
				afterCount = getCount(head);
				if(afterCount > beforeCount) {
					printf(BRIGHTGREEN "Late enrollment successful (GPA-ranked insert).\n" RESET);
				} else {
					printf(RED "Late enrollment failed (duplicate ID).\n" RESET);
				}
				break;
			case 5:	// Display All Students
				displayAll(head);
				break;
			case 6:	// Search Student
				if(!readInt("Enter Student ID to search: ", &id)) {
					printf(RED "Invalid ID.\n" RESET);
					break;
				}
				if(!searchById(head, id)) {
					printf(RED "Student not found.\n" RESET);
				}
				break;
			case 7:	// Delete Student
				if(!readInt("Enter Student ID to delete: ", &id)) {
					printf(RED "Invalid ID.\n" RESET);
					break;
				}
				beforeCount = getCount(head);
				head = deleteById(head, id);
				afterCount = getCount(head);
				if(afterCount < beforeCount) {
					printf(BRIGHTGREEN "Student deleted.\n" RESET);
				} else {
					printf(RED "Student not found.\n" RESET);
				}
				break;
			case 8:	// Count Students
				printf("Total Students: %d\n", getCount(head));
				break;
			case 9:	// Promote Year Level
				head = promoteAll(head, &promoted, &removed);
				printf("Promoted: %d | Removed (Graduated): %d\n", promoted, removed);
				break;
			case 10:	// Compute Average GPA
				avg = getAverageGPA(head);
				if(avg < 0.0f) {
					printf(RED "No students enrolled.\n" RESET);
				} else {
					printf("Average GPA: %.2f\n", avg);
				}
				break;
			case 11:	// Display Top N Students
				if(!readInt("Enter N: ", &n)) {
					printf(RED "Invalid N.\n" RESET);
					break;
				}
				displayTopN(head, n);
				break;
			case 12:	// Reverse List
				head = reverse(head);
				printf(BRIGHTGREEN "List reversed.\n" RESET);
				break;
			case 13:
				break;
			default:
				break;			
		}

		if(choice != 13) {
			printf("\nPress Enter to continue...");
			getchar();
		}
	}while(choice != 13);
	
	// free the list
	freeList(head);
	printf(BRIGHTGREEN "\nMemory freed. Exiting...\n" RESET);
	
	return 0;
}
