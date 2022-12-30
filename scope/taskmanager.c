#include <stdio.h>
#include <stdlib.h>
#include "processes.h"
#include <string.h>

void print_process_list() {
    
    if(processescount == 0) {
        printf("No processes\n");
        return;
    }

    printf("\nID\t | NAME\n------------------------------\n");
    for(int i = 0; i < processescount; i++)
        printf("%d\t | %s\n", processes[i].ID, processes[i].name);
}

void creat_new() {
    char name[30];
    printf("Enter a name for the process: ");
    scanf("%s",name);
    int result = createnewprocess(name);

    if(result) {    
        processes[processescount-1].ID = result;
        memcpy(processes[processescount-1].name, name, strlen(name));
    } else
        printf("Too many operations or invalid ID\n");
}

int main() {

    int op;
    do {
        printf("\n1. Create process\n");
        printf("2. Print all processes\n");
        printf("3. Stop a process\n");
        printf("4. Quit\n");
        printf("Choose an option (1, 2, 3 or 4): ");
        scanf("%d", &op);

        switch(op)
        {
            case 1:
                creat_new();
                break;

            case 2:
                print_process_list();
                break;

            case 3:
                int id;
                printf("Enter the ID of the process: ");
                scanf("%d", &id);

                stopprocess(id);
                break;

            case 4:
                break;

            default:
                printf("Invalid option\n");
                break;
        }

        if(op == 4)
            break;
            
    } while(1);

    return 0;
}