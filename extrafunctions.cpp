#include "extrafunctions.h"
#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>

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

int countWords(char *input) {
    int words = 0;
    bool inWord = false;

    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == ' ' || input[i] == '\n' || input[i] == '\t') {
            inWord = false;
        } else if (!inWord) {
            words++;
            inWord = true;
        }
    }

    return words;
}
