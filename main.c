#include "trienode.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <Windows.h>

#define MAX_WORD_LENGTH  100

int main() {
	trienode *root = NULL;
	char word[MAX_WORD_LENGTH];
	char description[MAX_WORD_LENGTH];
	int choice;

	while (true) {
		printf("\nMenu:\n");
		printf("1. Insert word with description\n");
		printf("2. Search for word\n");
		printf("3. Delete word\n");
		printf("4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice) {
			case  1:
				printf("Enter word: ");
				scanf("%s", word);
				getchar();
				printf("Enter description: ");
				scanf("%s", description);
				getchar();
				trieInsert(&root, word);
				printf("Word '%s' inserted.\n", word);
				Sleep(2500);
				system("cls");
				break;
			case  2:
				printf("Enter word to search for: ");
				scanf("%s", word);
				getchar();
				if (search_trie(root, word)) {
					printf("Word '%s' found.\n", word);
					printf("Description: %s", description);
					Sleep(2500);
					system("cls");
				} else {
					printf("Word not found.\n");
					Sleep(2500);
					system("cls");
				}
				break;
			case  3:
				printf("Enter word to delete: ");
				scanf("%s", word);
				getchar();
				if (deleteContents(root, word)) {
					printf("Word '%s' deleted.\n", word);
					Sleep(2500);
					system("cls");
				} else {
					printf("Word not found.\n");
					Sleep(2500);
					system("cls");
				}
				break;
			case  4:
				printf("Exiting program.\n");
				exit(EXIT_SUCCESS);
			default:
				printf("Invalid choice. Please choose again.\n");
		}
	}

	return  0;
}
