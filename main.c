#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
    ListNode *pNode = createListNode();
    int a = 10;
    pNode->value = &a;
    printf("%d", *(pNode->value));
    free(pNode);
    return 0;
}