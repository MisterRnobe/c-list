#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef int bool;
#define true 1
#define false 0
#define isTrue > 0
#define is ==
#define log(TEXT) printf("%s\r\n", TEXT)


void assertEqualsInt(int expected, int actual) {
    int result = expected is actual;
    if (result is false) {
        printf("Expected: %d\r\nActual: %d", expected, actual);
        exit(1);
    }
}

void assertEqualsUnsigned(unsigned int expected, unsigned int actual) {
    int result = expected is actual;
    if (result is false) {
        printf("Expected: %d\r\nActual: %d", expected, actual);
        exit(1);
    }
}


void shouldReturnProperSize() {
    List *list = emptyList();

    unsigned int expected = 0;
    assertEqualsUnsigned(expected, list->size);
}

void shouldAddIfListIsEmpty() {
    List *list = emptyList();
    int value = 1012;

    addLast(list, &value);

    assertEqualsUnsigned(1, list->size);
    assertEqualsInt(value, *first(list));
    assertEqualsInt(value, *last(list));
}

void shouldAddToNonEmptyList() {
    List *list = emptyList();
    int value1 = 1012;
    int value2 = 331;

    addLast(list, &value1);
    addLast(list, &value2);

    assertEqualsUnsigned(2, list->size);
    assertEqualsInt(value1, *first(list));
    assertEqualsInt(value2, *last(list));
}

void shouldRemoveFirst() {
    List *list = emptyList();
    int value1 = 4;
    int value2 = 5;
    int value3 = 1;
    addLast(list, &value1);
    addLast(list, &value2);
    addLast(list, &value3);

    int *removed = removeAt(list, 0);

    assertEqualsInt(value1, *removed);
    assertEqualsUnsigned(2, list->size);
    assertEqualsInt(value2, *first(list));
    assertEqualsInt(value3, *last(list));
}

void shouldRemoveLast() {
    List *list = emptyList();
    int value1 = 4;
    int value2 = 5;
    int value3 = 1;
    addLast(list, &value1);
    addLast(list, &value2);
    addLast(list, &value3);

    int *removed = removeAt(list, 2);

    assertEqualsInt(value3, *removed);
    assertEqualsUnsigned(2, list->size);
    assertEqualsInt(value1, *first(list));
    assertEqualsInt(value2, *last(list));
}

void shouldRemoveInsideList() {
    List *list = emptyList();
    int value1 = 4;
    int value2 = 5;
    int value3 = 1;
    addLast(list, &value1);
    addLast(list, &value2);
    addLast(list, &value3);

    int *removed = removeAt(list, 1);

    assertEqualsInt(value2, *removed);
    assertEqualsUnsigned(2, list->size);
    assertEqualsInt(value1, *first(list));
    assertEqualsInt(value3, *last(list));
}


int main() {
    log("Running shouldReturnProperSize");
    shouldReturnProperSize();
    log("Success");

    log("Running shouldAddIfListIsEmpty");
    shouldAddIfListIsEmpty();
    log("Success");

    log("Running shouldAddToNonEmptyList");
    shouldAddToNonEmptyList();
    log("Success");

    log("Running shouldRemoveFirst");
    shouldRemoveFirst();
    log("Success");

    log("Running shouldRemoveLast");
    shouldRemoveLast();
    log("Success");

    log("Running shouldRemoveInsideList");
    shouldRemoveInsideList();
    log("Success");

    log("Tests passed");

    return 0;
}