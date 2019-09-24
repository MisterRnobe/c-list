//
// Created by nikita on 24.09.2019.
//
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

ListNode *createListNode() {
    return (ListNode *) malloc(sizeof(ListNode));
}

ListNode *withValue(int *value) {
    ListNode *pNode = createListNode();
    pNode->value = value;
    return pNode;
}

List *emptyList() {
    List *ptr = (List *) malloc(sizeof(List));
    ptr->size = 0;
    return ptr;
}

List *addLast(List *list, int *value) {
    ListNode *pNode = withValue(value);

    if (list->size == 0) {
        list->head = pNode;
        list->tail = pNode;
    } else {
        list->tail->next = pNode;
        pNode->previous = list->tail;
        list->tail = pNode;
    }
    list->size++;
    return list;
}

List *addAfter(List *list, int *value, unsigned int index) {
    return list;
}

int *removeAt(List *list, unsigned int index) {
    if (index == 0) {
        list->size--;
        if (list->head == list->tail) {
            ListNode *pNode = list->head;
            list->head = NULL;
            list->tail = NULL;
            int *value = pNode->value;
            free(pNode);
            return value;
        } else {
            ListNode *pNode = list->head;
            list->head = pNode->next;
            int *value = pNode->value;
            free(pNode);
            return value;
        }
    } else if (index == list->size - 1) {
        ListNode *pNode = list->tail;
        list->tail = pNode->previous;
        int *value = pNode->value;
        free(pNode);
        list->size--;
        return value;
    } else if (index < list->size) {
        unsigned int i = 0;
        ListNode *currentNode = list->head;
        for (; i < index; i++) {
            currentNode = currentNode->next;
        }
        currentNode->next->previous = currentNode->previous;
        int *value = currentNode->value;
        free(currentNode);
        list->size--;
        return value;
    } else
        return NULL;
}

int *first(List *list) {
    return list->size == 0 ? NULL : list->head->value;
}

int *last(List *list) {
    return list->size == 0 ? NULL : list->tail->value;
}

void prettyPrint(List *list) {
    if (list->size == 0) {
        printf("[ ]\r\n");
        return;
    }
}