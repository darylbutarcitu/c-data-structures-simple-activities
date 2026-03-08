#ifndef ENROL_H
#define ENROL_H
#define SIZE 50
#define MIN_GPA 0.0
#define MAX_GPA 4.0

typedef struct student* Studentptr;

typedef struct student {
	int id;
	char fullName[SIZE];
	char program[SIZE];
	int yearLevel;
	float GPA;
	Studentptr next;
}Student;

typedef Studentptr List;

/* Function Prototypes */
Studentptr createStudent(int id, const char* fullName, const char* program, int yearLevel, float gpa);
void freeList(List head);

List regEnrol(List head, Studentptr s);
List priorityEnrol(List head, Studentptr s);
List manualEnrol(List head, Studentptr s, int pos);
List lateEnrol(List head, Studentptr s);

void displayAll(List head);
int searchById(List head, int id);

List deleteById(List head, int id);

int getCount(List head);
List promoteAll(List head, int* promoted, int* removed);
float getAverageGPA(List head);
void displayTopN(List head, int n);

List reverse(List head);

#endif // ENROL_H
