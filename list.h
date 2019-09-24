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

typedef struct {
    ListNode *head;
    ListNode *tail;
    unsigned int size;
} List;

ListNode *createListNode();

ListNode *withValue(int *value);

List *emptyList();

List *addLast(List *list, int *value);

List *addAfter(List *list, int *value, unsigned int index);

int *removeAt(List *list, unsigned int index);

int *first(List *list);

int *last(List *list);

void prettyPrint(List *list);