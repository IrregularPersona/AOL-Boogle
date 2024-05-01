#include "listnode.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// A function to create a new linked node

ListNode *createListNode(const char *description) {
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    if (newNode == NULL) {
        return NULL;
    }
    newNode->description = strdup(description);
    newNode->next = NULL;
    return newNode;
}

// Push tail 

void insertAtEnd(ListNode **head, const char *description) {
    ListNode *newNode = createListNode(description);
    if (newNode == NULL) {
        return;
    }
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    ListNode *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}