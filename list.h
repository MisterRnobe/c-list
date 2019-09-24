//
// Created by nikita on 24.09.2019.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H

#endif //LIST_LIST_H

struct Node {
    struct Node *previous;
    struct Node *next;
    int *value;
};

typedef struct Node ListNode;

ListNode *createListNode();
