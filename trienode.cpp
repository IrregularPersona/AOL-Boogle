#include "trienode.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

trienode *createNode() {
	trienode *newNode = (trienode *) malloc(sizeof *newNode);

	for (int i = 0; i < char_num; i++) {
		newNode->child_node[i] = NULL;
	}

	newNode->terminal = false;
	return newNode;
}

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

void printtrie(trienode *root) {
	if(root == NULL) {
		printf("There is no slang word yet in the dictionary.\n");
		return;
	}
	int counter = 0;
	printf("List of all slang words in the dictionary:\n");
	print_trie(root, NULL, 0, &counter);

}

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

	printf("Matching words for prefix '%s':\n", signedtext);
	unsigned char prefix[length + 1];
	memcpy(prefix, text, length);
	prefix[length] = '\0';
	int counter = 0;

	search_prefix(temp, prefix, length, length, &counter);

	return true;
}

bool node_has_child(trienode *node) {
	if(node == NULL) return false;

	for(int i = 0; i <  char_num; i++) {
		if(node->child_node[i] != NULL) {
			return true;
		}
	}

	return false;
}
