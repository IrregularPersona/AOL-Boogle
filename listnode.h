#ifndef LISTNODE_H
#define LISTNODE_H

typedef struct ListNode {
    char *description;
    struct ListNode *next;
} ListNode;

ListNode *createListNode(const char *description);
void insertAtEnd(ListNode **head, const char *description);
// Function declarations related to ListNode

#endif // LISTNODE_H