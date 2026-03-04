#ifndef SINGLY_H
#define SINGLY_H

typedef struct node Node;

typedef struct node{
	int item;
	Node* next;
}Node;

typedef struct list{
	int count;
	Node *head;
}List;

// Function Prototypes
List* createList();
Node* createNode(int newItem);
void freeList(List* L);

void displayAll(List* L);
void addFront(List* L, int newItem);
void addEnd(List* L, int newItem);
void addAt(List* L, int newItem, int pos);


#endif // SINGLY_H
