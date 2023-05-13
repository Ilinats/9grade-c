#include <stdio.h>
#include "dlinkedlist.h"

void printlinkedlist(LinkedList * list) {
    struct ListNode * currentnode = list->head;
    while (currentnode != NULL) {
        printf("%lf ", currentnode->value);
        currentnode = currentnode->next;
    }
    printf("\n");
}

int main(void) {
    LinkedList list = init();
    printlinkedlist(&list);

    pushfront(&list, 3);
    pushfront(&list, 7);
    pushfront(&list, 5);
    pushfront(&list, 4);
    printlinkedlist(&list);

    struct ListNode * el3 = get(&list, 2);
    printf("Element 3: %lf \n", el3->value);

    push(&list, 1, 11);
    printlinkedlist(&list);

    pushback(&list, 13);
    printlinkedlist(&list);

    popfront(&list);
    printlinkedlist(&list);

    pop(&list, 1);
    printlinkedlist(&list);

    popback(&list);
    printlinkedlist(&list);

    return 0;
}