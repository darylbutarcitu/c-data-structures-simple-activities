#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Enrol.h"
#include "others.h"

// Validates whether year level is within 1 to 5.
static int isValidYear(int yearLevel) {
	return yearLevel >= 1 && yearLevel <= 5;
}

// Validates whether GPA is within the allowed range.
static int isValidGPA(float gpa) {
	return gpa >= MIN_GPA && gpa <= MAX_GPA;
}

// Checks if a student ID already exists in the list.
static int idExists(List head, int id) {
	Studentptr curr = head;
	while(curr != NULL) {
		if(curr->id == id) {
			return 1;
		}
		curr = curr->next;
	}
	return 0;
}

// Creates and initializes a new student node.
Studentptr createStudent(int id, const char* fullName, const char* program, int yearLevel, float gpa) {
	Studentptr s;

	if(!isValidYear(yearLevel) || !isValidGPA(gpa)) {
		return NULL;
	}

	s = (Studentptr) malloc(sizeof(Student));
	if(s == NULL) {
		return NULL;
	}

	s->id = id;
	strncpy(s->fullName, fullName, SIZE - 1);
	s->fullName[SIZE - 1] = '\0';
	strncpy(s->program, program, SIZE - 1);
	s->program[SIZE - 1] = '\0';
	s->yearLevel = yearLevel;
	s->GPA = gpa;
	s->next = NULL;

	return s;
}

// Frees all nodes in the linked list.
void freeList(List head) {
	Studentptr curr = head;
	while(curr != NULL) {
		Studentptr next = curr->next;
		free(curr);
		curr = next;
	}
}

// Inserts a student at the end of the list (regular enrollment).
List regEnrol(List head, Studentptr s) {
	Studentptr curr;

	if(s == NULL || idExists(head, s->id)) {
		if(s != NULL) {
			free(s);
		}
		return head;
	}

	if(head == NULL) {
		return s;
	}

	curr = head;
	while(curr->next != NULL) {
		curr = curr->next;
	}
	curr->next = s;
	return head;
}

// Inserts a student at the front if GPA is at least 3.0.
List priorityEnrol(List head, Studentptr s) {
	if(s == NULL || s->GPA < 3.0f || idExists(head, s->id)) {
		if(s != NULL) {
			free(s);
		}
		return head;
	}

	s->next = head;
	return s;
}

// Inserts a student at a specific valid 1-based position.
List manualEnrol(List head, Studentptr s, int pos) {
	Studentptr curr;
	int count = getCount(head);
	int i;

	if(s == NULL || idExists(head, s->id) || pos < 1 || pos > count + 1) {
		if(s != NULL) {
			free(s);
		}
		return head;
	}

	if(pos == 1) {
		s->next = head;
		return s;
	}

	curr = head;
	for(i = 1; i < pos - 1; i++) {
		curr = curr->next;
	}

	s->next = curr->next;
	curr->next = s;
	return head;
}

// Inserts a student based on descending GPA order.
List lateEnrol(List head, Studentptr s) {
	Studentptr curr;

	if(s == NULL || idExists(head, s->id)) {
		if(s != NULL) {
			free(s);
		}
		return head;
	}

	if(head == NULL || s->GPA > head->GPA) {
		s->next = head;
		return s;
	}

	curr = head;
	while(curr->next != NULL && curr->next->GPA >= s->GPA) {
		curr = curr->next;
	}

	s->next = curr->next;
	curr->next = s;
	return head;
}

// Displays all student records in table format.
void displayAll(List head) {
	Studentptr curr = head;

	if(head == NULL) {
		printf(RED "No students enrolled.\n" RESET);
		return;
	}

	printf("\n%-8s %-22s %-16s %-5s %-5s\n", "ID", "Full Name", "Program", "Year", "GPA");
	printf("----------------------------------------------------------------\n");
	while(curr != NULL) {
		printf("%-8d %-22s %-16s %-5d %-5.2f\n",
			curr->id, curr->fullName, curr->program, curr->yearLevel, curr->GPA);
		curr = curr->next;
	}
	printf("Total Students: %d\n", getCount(head));
}

// Searches and prints a student record by ID; returns 1 if found.
int searchById(List head, int id) {
	Studentptr curr = head;
	while(curr != NULL) {
		if(curr->id == id) {
			printf("\nID: %d\nName: %s\nProgram: %s\nYear: %d\nGPA: %.2f\n",
				curr->id, curr->fullName, curr->program, curr->yearLevel, curr->GPA);
			return 1;
		}
		curr = curr->next;
	}
	return 0;
}

// Deletes a student node by ID and returns the updated head.
List deleteById(List head, int id) {
	Studentptr curr = head;
	Studentptr prev = NULL;

	while(curr != NULL && curr->id != id) {
		prev = curr;
		curr = curr->next;
	}

	if(curr == NULL) {
		return head;
	}

	if(prev == NULL) {
		head = curr->next;
	} else {
		prev->next = curr->next;
	}

	free(curr);
	return head;
}

// Counts the total number of students in the list.
int getCount(List head) {
	int count = 0;
	Studentptr curr = head;
	while(curr != NULL) {
		count++;
		curr = curr->next;
	}
	return count;
}

// Promotes all students by one year and removes graduates beyond year 5.
List promoteAll(List head, int* promoted, int* removed) {
	Studentptr curr = head;
	Studentptr prev = NULL;

	if(promoted != NULL) {
		*promoted = 0;
	}
	if(removed != NULL) {
		*removed = 0;
	}

	while(curr != NULL) {
		curr->yearLevel++;
		if(promoted != NULL) {
			(*promoted)++;
		}

		if(curr->yearLevel > 5) {
			Studentptr toDelete = curr;
			if(prev == NULL) {
				head = curr->next;
				curr = head;
			} else {
				prev->next = curr->next;
				curr = prev->next;
			}
			free(toDelete);
			if(removed != NULL) {
				(*removed)++;
			}
			continue;
		}

		prev = curr;
		curr = curr->next;
	}

	return head;
}

// Computes and returns average GPA; returns -1.0 if list is empty.
float getAverageGPA(List head) {
	float sum = 0.0f;
	int count = 0;
	Studentptr curr = head;

	while(curr != NULL) {
		sum += curr->GPA;
		count++;
		curr = curr->next;
	}

	if(count == 0) {
		return -1.0f;
	}

	return sum / count;
}

// Displays the first N students from the list.
void displayTopN(List head, int n) {
	Studentptr curr = head;
	int shown = 0;

	if(head == NULL) {
		printf(RED "No students enrolled.\n" RESET);
		return;
	}

	if(n <= 0) {
		printf(RED "Invalid N.\n" RESET);
		return;
	}

	printf("\n%-8s %-22s %-16s %-5s %-5s\n", "ID", "Full Name", "Program", "Year", "GPA");
	printf("----------------------------------------------------------------\n");
	while(curr != NULL && shown < n) {
		printf("%-8d %-22s %-16s %-5d %-5.2f\n",
			curr->id, curr->fullName, curr->program, curr->yearLevel, curr->GPA);
		shown++;
		curr = curr->next;
	}
}

// Reverses the list using three-pointer technique.
List reverse(List head) {
	Studentptr prev = NULL;
	Studentptr curr = head;
	Studentptr next = NULL;

	while(curr != NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	return prev;
}

