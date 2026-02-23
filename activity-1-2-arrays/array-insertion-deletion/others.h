#ifndef OTHERS_H
#define OTHERS_H

// Text color code
#define RESET   		"\033[0m"
#define YELLOW  		"\033[33m"
#define RED     		"\033[31m"
#define BRIGHTRED   	"\033[91m"
#define GREEN   		"\033[32m"
#define BRIGHTGREEN   	"\033[92m"

void displayTitle();
int getUserInput();

void showMainMenu();
void showInsertMenu();
void showDeleteMenu();

void validateMenuChoice(int *choice, int range);

#endif
