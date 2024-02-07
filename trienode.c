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

void print_trie(trienode *node, unsigned char *prefix, int length) {

	if(node->terminal) {
		printf("WORD: %s\n", prefix);
	}

	unsigned char newPref[length + 2];
	memcpy(newPref, prefix, length);
	newPref[length + 1] = '\0';


	for(int i = 0; i < char_num; i++) {
		if(node->child_node[i] != NULL) {
			newPref[length] = i;
			print_trie(node->child_node[i], newPref, length + 1);
		}
	}
}

void printtrie(trienode *root) {
	if(root == NULL) {
		printf("TRIE EMPTY\n");
		return;
	}

	print_trie(root, NULL, 0);

}

bool search_trie (trienode *root, char *signedtext) {
	unsigned char *text = (unsigned char *)signedtext;
	int length = strlen(signedtext);

	trienode *temp = root;

	for(int i = 0; i < length; i++) {
		if(temp->child_node[text[i]] == NULL) {
			return false;
		}

		temp = temp->child_node[text[i]];
	}
	return temp->terminal;
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

trienode *deleteStr(trienode *node, unsigned char *text, bool *deleted) {
    if (node == NULL) {
        return node;
    }
    
    if(*text == '\0') {
        if(node->terminal) {
            node->terminal = false;
            *deleted = true;
            
            if(!node_has_child(node)) {
                free(node);
                return NULL;
            }
        }
        
        return node;
    }
    
    node->child_node[text[0]] = deleteStr(node->child_node[text[0]], text +   1, deleted);
    
    if(*deleted && !node_has_child(node) && !node->terminal) {
        free(node);
        return NULL;
    }
    
    return node;
}


bool deleteContents(trienode *root, char *signedtext) {
    unsigned char *text = (unsigned char *)signedtext;
    bool result = false;
    
    if (root == NULL) {
        return false;
    }
    
    root = deleteStr(root, text, &result);
    
    return result;
}