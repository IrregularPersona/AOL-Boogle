#include "extrafunctions.h"
#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>

// 		A function to quite literally pause the console, 
//		and to continue the program after a newline input.

void enterToContinue() {
    printf("Press enter to continue.\n");
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    getchar();
}

// A function to slow down the speed of the load times, artificially.
void loadingScreen() {
	printf("Loading");
	fflush(stdout);
	
	for(int i = 0; i < 3; i++) {
		Sleep(500);
		printf(".");
		fflush(stdout);
	}
	printf("\n");
	Sleep(500);
}

void clearInputBuffer() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

int countWords(char *input) {
    int words = 0;
    bool inWord = false;

    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == ' ' || input[i] == '\n') {
            inWord = false;
        } else if (!inWord) {
            words++;
            inWord = true;
        }
    }

    return words;
}

bool checkForSpaces(char* str) {
    int length = strlen(str);

    for(int i = 0; i < length; i++) {
        if(str[i] == ' ') {
            return true;
            break;
        }
    }
    return false;
}
