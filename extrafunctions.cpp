#include "extrafunctions.h"
#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>

/*
 *  Function: enterToContinue
 *  -----------
 *  @param = void
 *  
 *  To pause the program, and forces it to wait for a 
 *  user input of any kind.
 */

void enterToContinue() {
    printf("Press enter to continue.\n");
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/*
 *  Function: loadingScreen
 *  -----------
 *  @param  = void
 * 
 *  To artificially make a loading template.
 */

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

/*
 *  Function: clearInputBuffer
 *  -----------
 *  @param = void
 *  
 *  Meant to clear the input buffer. Used after
 *  an input stream.
 */

void clearInputBuffer() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

/*
 *  Function: countWords
 *  -----------
 *  @param = char*
 *  
 *  Counts the amount of words are present
 *  in a given string, by using the amount
 *  of whitespaces are there. Returns an int.
 */

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

/*
 *  Function: checkForSpaces 
 *  -----------
 *  @param = char*
 *  
 *  Meant to check for the existence of 
 *  whitespace within a given string and
 *  returns a true/false value.
 */

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
