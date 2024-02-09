#include "trienode.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <Windows.h>

#define MAX_WORD_LENGTH  100

void enterToContinue() {
	printf("Press enter to continue.\n");
	while(getchar() != '\n');
}

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

int main() {
	trienode *root = NULL;
	char word[MAX_WORD_LENGTH];
	char description[MAX_WORD_LENGTH];
	int choice;

	while (true) {
		system("cls");
		printf("\nMenu:\n");
		printf("1. Release a new slang word\n");
		printf("2. Search a slang word\n");
		printf("3. View all slang words starting with a certain prefix word\n");
		printf("4. View all slang words\n");
		printf("5. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice) {
			case  1:
				printf("Input a new slang word [Must be more than 1 characters and contains no space]: ");
				scanf("%99s", word);
				getchar();
				while(strlen(word) < 2 || strchr(word, ' ') != NULL) {
					printf("Please enter the word with the expected requirements!\n");
					printf(">> ");
					scanf("%99s", word);
				}
				printf("Input a new slang word description [Must be more than 2 words]: ");
				scanf("%99s", description);
				getchar();
				trieInsert(&root, word);
				printf("Slang '%s' inserted.\n", word);
				loadingScreen();
				enterToContinue();
				break;
			case  2:
				printf("Enter slang to search for [Must be more than 1 characters and contains no space]: ");
				scanf("%99s", word);
				getchar();
				while(strlen(word) < 2 || strchr(word, ' ') != NULL) {
					printf("Please enter the word with the expected requirements!\n");
					printf(">> ");
					scanf("%99s", word);
				}
				if (search_trie(root, word)) {
					loadingScreen().
					printf("Slang word : %s\n", word);
					printf("Description : %s\n", description);
					enterToContinue();
				} else {
					loadingScreen();
					printf("Word not found.\n");
					enterToContinue();
				}
				break;
			case 3:
				printf("Input a prefix to be searched: ");
				scanf("%s", word);
				search_trie(root, word);
				Sleep(3000);
				break;
			case 4:
				printtrie(root);
				enterToContinue();
				Sleep(3000);
				break;
			case  5:
				printf("Exiting program.\n");
				exit(EXIT_SUCCESS);
			default:
				printf("Invalid choice. Please choose again.\n");
		}
	}

	return  0;
}
