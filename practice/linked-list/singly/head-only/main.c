#include <stdio.h>
#include <stdlib.h>
#include "Singly.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {
	
	List* L1 = createList();
	
	// Check if L1 is allocated successfuly
	if(L1==NULL) {
		printf("Memory Allocation Failed! List not created.\n"); 
		return 1;	// exit program with return status 1 XP
	} else {
		printf("List created.\n"); 
	}
	
	// ADD FRONT
	printf("--- Add Front ---\n");
	addFront(L1, 5);
	displayAll(L1);
	addFront(L1, 4);
	addFront(L1, 3);
	addFront(L1, 2);
	addFront(L1, 1);
	displayAll(L1);
	
	// ADD END
	printf("\n--- Add End ---\n");
	addEnd(L1, 6);
	displayAll(L1);
	addEnd(L1, 7);
	addEnd(L1, 8);
	addEnd(L1, 9);
	addEnd(L1, 10);
	displayAll(L1);

	// ADD AT
	printf("\n--- Add At ---\n");
	addAt(L1, 11, 1);	// Add at position 1 (front)
	displayAll(L1);
	addAt(L1, 12, 5);	// Add at position 5 (middle)
	displayAll(L1);
	addAt(L1, 13, -1);	// Add at negative position (front)
	displayAll(L1);
	addAt(L1, 14, 25);	// Add at position beyond count (end)
	displayAll(L1);

	freeList(L1);
	
	return 0;
}
