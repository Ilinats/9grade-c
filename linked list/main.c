#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

void printlinkedlist(LinkedList * list) {
  struct ListNode * currentnode = list->head;
  while (currentnode != NULL) {
    switch(currentnode->stateOfTask)
    {
        case NEW:
            printf("%d %s %8s\n", currentnode->priority, currentnode->name, "NEW");
            break;
        
        case IN_PROCESS:
            printf("%d %s %8s\n", currentnode->priority, currentnode->name, "IN PROCESS");
            break;

        case DONE:
            printf("%d %s %8s\n", currentnode->priority, currentnode->name, "DONE");
            break;
    }
    currentnode = currentnode->next;
  }
}

int main() {

    LinkedList list = init();
    int op, priority;
    State state;
    do {
        printf("\n1. Add a new task\n");
        printf("2. Remove a task\n");
        printf("3. Change state\n");
        printf("4. Print all tasks\n");
        printf("5. Quit\n");
        printf("Choose an option (1, 2, 3, 4 or 5): ");
        scanf("%d", &op);

        switch(op)
        {
            case 1:
                char name[101];
                State state;
                printf("Enter priority: ");
                scanf("%d", &priority);
                printf("Enter name: ");
                scanf("%s", &name);
                getchar();
                push(&list, name, priority, NEW);
                break;

            case 2:
                printf("Enter priority: ");
                scanf("%d", &priority);

                pop(&list, priority);
                break;

            case 3:
                printf("Enter priority: ");
                scanf("%d", &priority);
                printf("Enter a new state (1 for NEW, 2 for IN_PROCESS, or 3 for DONE): ");
                scanf("%d", &state);
                set(&list, priority, state);
                break;
            
            case 4:
                printlinkedlist(&list);
                break;

            case 5:
                releaseList(&list);
                break;

            default:
                printf("Invalid option");
                break;
        }

        if(op == 5)
            break;
            
    } while(1);

    return 0;
}