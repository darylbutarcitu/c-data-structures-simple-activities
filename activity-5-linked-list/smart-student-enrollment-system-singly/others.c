#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "others.h"

// Displays the activity title.
void displayTitle() {
	printf(BRIGHTYELLOW"======= SMART ENROLLMENT SYSTEM =======\n"RESET);
}

// Displays the main menu options.
void displayMenu() {
	printf("\t1. Regular Enrollment\n");
	printf("\t2. Priority Enrollment\n");
	printf("\t3. Manual Insert\n");
	printf("\t4. Late Enrollment\n");
	printf("\t5. Display All Students\n");
	printf("\t6. Search Student\n");
	printf("\t7. Delete Student\n");
	printf("\t8. Count Students\n");
	printf("\t9. Promote Year Level\n");
	printf("\t10. Compute Average GPA\n");
	printf("\t11. Display Top N Students\n");
	printf("\t12. Reverse List\n");
	printf(BRIGHTRED"\t13. Exit\n"RESET);
	printf(YELLOW "[=------------------------------------=]\n" RESET);
}

// Clears leftover characters from input buffer.
void clearInputBuffer(void) {
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}

// Reads a full line and strips trailing newline.
void readLine(char *buffer, int size) {
	if (fgets(buffer, size, stdin) != NULL) {
		buffer[strcspn(buffer, "\n")] = '\0';
	}
}

