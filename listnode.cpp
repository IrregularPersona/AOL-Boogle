#include "listnode.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 *  Function: createListNode
 *  -----------
 *  @param = const char*
 *  
 *  Meant to create a new linked node, 
 *  to accomodate the contents of the description.
 *  (Super unnecessary, but cool thing to learn from)
 */

ListNode *createListNode(const char *description) {
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    if (newNode == NULL) {
        return NULL;
    }
    newNode->description = strdup(description);
    newNode->next = NULL;
    return newNode;
}

/*
 *  Function: insertAtEnd
 *  -----------
 *  @param = ListNode**, const char*
 *  
 *  Pushing a newly created node, to the tail
 *  of the linked list.
 */

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