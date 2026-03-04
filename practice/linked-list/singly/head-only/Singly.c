#include <stdio.h>
#include <stdlib.h>
#include "Singly.h"

// Function to create a new List, initialize count to 0 and head to NULL, returns a List pointer variable
List* createList() {
	List* newList = malloc(sizeof(List));
	if(newList==NULL) {	// Malloc failed
		return NULL;
	}
	newList->count = 0;
	newList->head = NULL;
	return newList;
}

// Function to create a new node, initialize the item and next to NULL, returns a node pointer variable
Node* createNode(int newItem) {
	Node* n = malloc(sizeof(Node));
	if(n==NULL) { // Malloc failed
		return NULL;
	}
	n->item = newItem;
	n->next = NULL;
	return n;
}

void freeList(List* L) {
	if(L==NULL) {
		return;
	}

	Node* curr = L->head;
	while(curr!=NULL) {
		Node* nextNode = curr->next;
		free(curr);
		curr = nextNode;
	}

	free(L);
}

// Function to display all items in a List
void displayAll(List* L) {
	if(L==NULL) {
		printf("List is NULL!\n");
		return;
	}

	Node* curr = L->head;
	
	if(curr==NULL) {
		printf("List is Empty!\n");
		return;
	}
	
	while(curr!= NULL) {
		printf("%d ", curr->item);
		curr = curr->next;
	}
	printf("(Count: %d)\n", L->count);
}

// Function to Add in front of the list
void addFront(List* L, int newItem){
	if(L==NULL) {	// Invalid List pointer
		return;
	}

	Node* newNode = createNode(newItem);
	if(newNode==NULL) {	// Malloc failed
		return;
	}

	newNode->next = L->head;
	L->head=newNode;	// assign new node as the head
	L->count++;			// update count
}

// Function to Add at the end of the list
void addEnd(List* L, int newItem) {
	if(L==NULL) {	// Invalid List pointer
		return;
	}

	Node* newNode = createNode(newItem);
	if(newNode==NULL) { // Malloc failed
		return;
	}
	
	if(L->head==NULL) {	// empty list
		L->head = newNode;
	} 
	else {
		Node* curr = L->head;
		
		while(curr->next!=NULL) {	// Loop until curr points to the last node
			curr=curr->next;
		}
		curr->next=newNode; // connect the last node to the new node
	}
	
	L->count++;	// update list count
}

// Function to Add at a position in the list (start = 1)
void addAt(List* L, int newItem, int pos) {
	if(L==NULL) {	// Invalid List pointer
		return;
	}
	
	if(pos <= 1) {	// position 0 and negative numbers are considered add front in this practice
		addFront(L,newItem);	// just reuse addFront();
	}
	else if (pos > L->count) {
		addEnd(L,newItem);	// any position beyond count is just addEnd();
	}
	else {
		Node* newNode = createNode(newItem);
		if(newNode==NULL) {
			return;
		}
		Node* curr = L->head;
		int i;
		for(i=2; i<pos; i++) {
			curr=curr->next;
		}
		
		newNode->next=curr->next;	// connect the new node to the next of curr
		curr->next = newNode;		// update next pointer of curr by pointing to the new node
		L->count++;					// only update count within here because the function calls in the other conditions already have their own count update
	}
}
