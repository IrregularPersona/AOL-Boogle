#include "trienode.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

/*
 *  Function: createNode
 *  -----------
 *  @param = void
 *  
 *  Meant to create a new node, to accomodate
 * 	the characters that are to be pushed into the tree.
 */

trienode *createNode() {
	trienode *newNode = (trienode *) malloc(sizeof *newNode);

	for (int i = 0; i < char_num; i++) {
		newNode->child_node[i] = NULL;
	}

	newNode->terminal = false;
	return newNode;
}

/*
 *  Function: trieInsert
 *  -----------
 *  @param = trienode**, const char*
 *  
 *  Functions as a way to insert characters into the tree.
 * 	It assigns a new node for every character within the 
 * 	provided string. Finally, once at the last character,
 * 	it returns and sets a bool linked to that specific 
 * 	character to be true, indicating that this is the end 
 * 	of a string.
 */

bool trieInsert(trienode **root, const char *signedtext) {
	if(*root == NULL) {
		*root = createNode();
	}

	unsigned char *text = (unsigned char *) signedtext;

	trienode *temp = *root;

	int length = strlen(signedtext);

	for (int i  = 0; i < length; i++) {
		if(temp->child_node[text[i]] == NULL) {
			temp->child_node[text[i]] = createNode();
		}
		temp = temp->child_node[text[i]];
	}

	if (temp->terminal) {
		return false;
	} else {
		temp->terminal = true;
		return true;
	}
}

/*
 *  Function: print_trie
 *  -----------
 *  @param = trienode*, unsigned char*, int, int*
 *  
 *  Functions as a way to print all words saved 
 * 	within the tree. It works by checking if a node
 * 	is a terminal node or not, and printing the string
 * 	up until the terminal node if it is a terminal. It 
 * 	searches trhough the tree recursively. Counter 
 * 	variable functions as a way to list it in a proper
 * 	numerical order.
 */

void print_trie(trienode *node, unsigned char *prefix, int length, int *counter) {
	if (node->terminal) {
		printf("%d. %s\n", ++(*counter), prefix);
	}

	unsigned char newPref[length + 2];
	memcpy(newPref, prefix, length);
	newPref[length + 1] = '\0';

	for (int i = 0; i < char_num; i++) {
		if (node->child_node[i] != NULL) {
			newPref[length] = i;
			print_trie(node->child_node[i], newPref, length + 1, counter);
		}
	}
}

/*
 *  Function: printtrie
 *  -----------
 *  @param = trienode*
 *  
 *  Functions as a bridge to the actual 
 * 	print_trie function. Serves as modularity.
 */

void printtrie(trienode *root) {
	if(root == NULL) {
		printf("There is no slang word yet in the dictionary.\n");
		return;
	}
	int counter = 0;
	printf("List of all slang words in the dictionary:\n");
	print_trie(root, NULL, 0, &counter);

}

/*
 *  Function: search_prefix
 *  -----------
 *  @param = trienode*, unsigned char*, int, int, int
 *  
 *  Functions as a way to look up strings with 
 * 	a specific set of prefix. Works similarly 
 * 	to print_trie, with it being recursively 
 * 	checking the characters, but with a change 
 * 	that the user inputs a set amount of characters,
 * 	and that the function only traverses a specific
 * 	side of the tree.
 */

void search_prefix(trienode *node, unsigned char *prefix, int length, int originalLength, int *counter) {
	if (node == NULL) {
		return;
	}

	if (node->terminal) {
		prefix[length] = '\0';
		printf("%d. %s\n", ++(*counter), prefix);
	}

	for (int i = 0; i < char_num; i++) {
		if (node->child_node[i] != NULL) {
			prefix[length] = i;
			search_prefix(node->child_node[i], prefix, length + 1, originalLength, counter);
		}
	}
}

/*
 *  Function: search_trie
 *  -----------
 *  @param = trienode*, char*
 *  
 *  Functions similarly to printtrie, as it
 * 	functions as a bridge to the actual search_prefix
 * 	function. Serves as modularity.
 */

bool search_trie(trienode *root, char *signedtext) {
	unsigned char *text = (unsigned char *)signedtext;
	int length = strlen(signedtext);

	trienode *temp = root;

	for (int i = 0; i < length; i++) {
		if (temp->child_node[text[i]] == NULL) {
			printf("There is no prefix “%s” in the dictionary\n", signedtext);
			return false;
		}

		temp = temp->child_node[text[i]];
	}

	printf("\nMatching words for prefix '%s':\n", signedtext);
	unsigned char prefix[length + 1];
	memcpy(prefix, text, length);
	prefix[length] = '\0';
	int counter = 0;

	search_prefix(temp, prefix, length, length, &counter);

	return true;
}
