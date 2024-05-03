#include "trienode.h"
#include "extrafunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <Windows.h>

#define MAX_WORD_LENGTH 100

int main() {
	trienode *root = NULL; 				// Init root as NULL.
	char word[MAX_WORD_LENGTH];			// Var: Word, used to take in an input of a char, for slangs.
	char description[MAX_WORD_LENGTH];	// Var: Description, used to take in an input of Char, for Slang description.
	int choice;							// Var: Choice, used to take in an input of Int, for menu selection.

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
			case 1:
                printf("Input a new slang word [Must be more than 1 character and contains no space]: ");
                clearInputBuffer(); 
                fgets(word, sizeof(word), stdin); // Takes any user input, and input it into word, with the sizeof the variable word itself.
                word[strcspn(word, "\n")] = '\0'; // Find the newline character in word and replace it with the null-terminator.

				/*
				 *  If the user input has less than 2 words, or has a whitespace, 
				 * 	itll reloop until the required requirements are met.
				 */

                while (strlen(word) < 2 || checkForSpaces(word)) {  
                    printf("Input a new slang word [Must be more than 1 character and contains no space]: ");
                    clearInputBuffer();
                    fgets(word, sizeof(word), stdin);
                    word[strcspn(word, "\n")] = '\0';
                }

				/*
				 * Same as the previous user input, but this time for the description.
				 */

                printf("Input a new slang word description [Must be more than 2 words]: ");
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = '\0';

				/*
				 *  If the user input has less than 2 words, itll reloop until the 
				 * 	required requirements are met.
				 */

                while (countWords(description) < 2) {
                    printf("Input a new slang word description [Must be more than 2 words]: ");
                    fgets(description, sizeof(description), stdin);
                    description[strcspn(description, "\n")] = '\0'; 
                }

				/*
				 * 	Insert the word, given the address of root.
				 */

                trieInsert(&root, word);
                printf("Slang '%s' inserted.\n", word);
                loadingScreen(); // Loading sequence
                enterToContinue(); // Hold stdin to wait for and user input
                break;
			case 2:

				/*
				 *	User input for slangs to search. In this case, its meant
				 * 	to search full words, and not prefixes.
				 */

				printf("Enter slang to search for [Must be more than 1 characters and contains no space]: ");
				scanf("%99s", word);
				getchar();

				/*
				 *  If the user input has less than 2 characters, itll reloop until the 
				 * 	required requirements are met.
				 */

				while(strlen(word) < 2 || checkForSpaces(word)) {
					printf("Please enter the word with the expected requirements!\n");
					printf(">> ");
					scanf("%99s", word);
				}

				/*
				 * 	If the word is found, print out the word and its description.
				 *	If not, just tell the user the word isn't found.
				 */
				
				if (search_trie(root, word)) {
					loadingScreen();
					printf("\nSlang word : %s\n", word);
					printf("Description : %s\n\n", description);
					enterToContinue();
				} else {
					loadingScreen();
					printf("Word not found.\n");
					enterToContinue();
				}
				break;
			case 3:

				/*
				 *	User input for a word, but this time its just a prefix
				 *	(or in other words, part/subset of a word).
				 */

				printf("Input a prefix to be searched: ");
				scanf("%s", word);
				search_trie(root, word); // And we search the word using a built-in function. Refer to trienode.cpp
				enterToContinue();
				break;
			case 4:
				printtrie(root); // Print all words that are contained in the trie.
				system("pause");
				break;
			case 5:
				printf("Exiting program.\n");
				exit(EXIT_SUCCESS);
			default:
				printf("Invalid choice. Please choose again.\n");
		}
	}

	return  0;
}
