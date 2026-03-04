#include <stdio.h>
#include <stdlib.h>
#include "Singly.h"

// Function to create a new List, initialize count to 0 and head to NULL, returns a List pointer variable
List* createList() {
	List* newList = (List*)malloc(1*sizeof(List)); // (type_to_cast)malloc(count * sizeof(object));
	newList->count = 0;
	newList->head = NULL;
	return newList;
}

// Function to create a new node, initialize the item and next to NULL, returns a node pointer variable
Node* createNode(int newItem) {
	Node* n = (Node*)malloc(sizeof(Node));
	n->item = newItem;
	n->next = NULL;
	return n;
}

// Function to display all items in a List
void displayAll(List* L) {
	Node* curr = L->head;
	
	if(curr==NULL) {
		printf("List is Empty!\n");
		return;
	}
	
	while(curr!= NULL) {
		printf("%d ", curr->item);
		curr = curr->next;
	}
	printf("(Count: %d)\n", L1->count);
}

// Function to Add in front of the list
void addFront(List* L, int newItem){
	Node* newNode = createNode(newItem);
	newNode->next = L->head;
	L->head=newNode;	// assign new node as the head
	L->count++;			// update count
}

// Function to Add at the end of the list
void addEnd(List* L, int newItem) {
	if(L==NULL /*L->count == 0*/) {	// List is empty or null
		printf("List is Empty!\n");
		return;
	}
	
	Node* newNode = createNode(newItem);
	Node* curr = L->head;
	
	// Loop until curr points to the last node
	while(curr->next!=NULL) {
		curr=curr->next;
	}
	
	curr->next=newNode; // connect the last node to the new node
	L->count++;			// update list count
}
