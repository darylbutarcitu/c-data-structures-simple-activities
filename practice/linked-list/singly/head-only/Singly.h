#ifndef SINGLY_H
#define SINGLY_H

typedef struct node Node;
//typedef struct node* Nodeptr;

typedef struct node{
	int item;
	Node* next;
	//Nodeptr next;
}Node;

typedef struct list{
	int count;
	Node *head;
	//Nodeptr head;
}List;

// Function Prototypes
List* createList();	// List* createList();
Node* createNode(int newItem);

void displayAll(List* L);
void addFront(List* L, int newItem);
void addEnd(List* L, int newItem);
void addAt(List* L, int newItem, int pos);


#endif // SINGLY_H
