#include <stdio.h>
#include <stdlib.h>
#include "Singly.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
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
	displayAll(L1-);
	addFront(L1, 4);
	addFront(L1, 3);
	addFront(L1, 2);
	addFront(L1, 1);
	displayAll(L1->head);
	
	// ADD END
	printf("\n--- Add End ---\n");
	addEnd(L1, 6);
	displayAll(L1);
	addEnd(L1, 7);
	addEnd(L1, 8);
	addEnd(L1, 9);
	addEnd(L1, 10);
	displayAll(L1);
	
	return 0;
}
