#include "listnode.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


ListNode *createListNode(const char *description) {
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    if (newNode == NULL) {
        return NULL;
    }
    newNode->description = strdup(description);
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(ListNode **head, const char *description) {
    ListNode *newNode = createListNode(description);
    if (newNode == NULL) {
        return;
    }
    newNode->next = *head;
    *head = newNode;
}

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

void deleteNode(ListNode **head, const char *description) {
    ListNode *current = *head;
    ListNode *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->description, description) ==  0) {
            if (previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current->description);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

ListNode *searchNode(ListNode *head, const char *description) {
    ListNode *current = head;
    while (current != NULL) {
        if (strcmp(current->description, description) ==  0) {
            return current;
        }
        current = current->next;
    }
    return NULL; // Not found
}

void freeList(ListNode *head) {
    ListNode *current = head;
    ListNode *nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current->description);
        free(current);
        current = nextNode;
    }
}