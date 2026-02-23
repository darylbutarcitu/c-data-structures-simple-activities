# Array Management System – Insertion and Deletion Operations

## 📌 Project Description
This project implements a **menu-driven Array Management System in C** that performs insertion and deletion operations on a one-dimensional integer array.  
The program simulates a basic data manager where users can dynamically modify array contents through menu options.

---

## 📝 Functional Requirements
The system must allow the user to:

- Insert an element at the beginning  
- Insert an element at the end  
- Insert an element at a specific position  
- Insert an element after a given value  
- Delete an element at a specific position  
- Delete the first occurrence of a value  
- Delete all occurrences of a value  
- Delete the second smallest element  
- Delete the second largest element  
- Search for an element  
- Display all elements  
- Exit  

---

## 🔧 Function Prototypes
```c
void insertBeginning(int arr[], int *count, int value);
void insertEnd(int arr[], int *count, int value);
void insertAtPosition(int arr[], int *count, int position, int value);
void insertAfterValue(int arr[], int *count, int target, int value);

void deleteAtPosition(int arr[], int *count, int position);
void deleteByValue(int arr[], int *count, int value);
void deleteAllOccurrences(int arr[], int *count, int value);
void deleteSecondSmallest(int arr[], int *count);
void deleteSecondLargest(int arr[], int *count);

int search(int arr[], int count, int value);
void display(int arr[], int count);