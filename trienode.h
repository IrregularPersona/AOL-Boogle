#ifndef TRIENODE_H
#define TRIENODE_H

#define char_num 256

typedef struct ListNode {
    char *description;
    struct ListNode *next;
} ListNode;

typedef struct trienode {
    struct trienode *child_node[char_num];
    bool terminal;
    ListNode *description;
} trienode;

trienode *createNode();
bool trieInsert(trienode **root, const char *signedtext);
void printtrie(trienode *root);
bool search_trie(trienode *root, char *signedtext);
// Other function declarations

#endif