#ifndef LISTNODE_H
#define LISTNODE_H

typedef struct ListNode {
    char *description;
    struct ListNode *next;
} ListNode;

ListNode *createListNode(const char *description);
void insertAtBeginning(ListNode **head, const char *description);
void insertAtEnd(ListNode **head, const char *description);
void deleteNode(ListNode **head, const char *description);
ListNode *searchNode(ListNode *head, const char *description);
void freeList(ListNode *head);
// Function declarations related to ListNode

#endif // LISTNODE_H