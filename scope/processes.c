#include "processes.h"
#include <stdlib.h>  
#include <conio.h>  
#include <string.h>
#include <limits.h>

struct Process processes[5] = {0};
int processescount = 0;

int nextprocessid (void) {
    int ID;
    int notUnique = 0;
    static int counter = 1;

    if(counter == INT_MAX)
        return 0;

    ID = counter++;
    return ID;
}

int createnewprocess(char name[30]) {

    if(processescount >= 5)
        return 0;
    
    memcpy(processes[processescount].name, name, strlen(name));
    processescount ++;
    return nextprocessid();
}

void stopprocess (int id) {
    int process;
    int exist = 0;
    
    for(int i = 0; i < processescount; i++) {
        if(processes[i].ID == id) {
            process = i;
            exist = 1;
            break;
        }
    }

    if(exist) {
        for(int i = process; i < processescount - 1; i++) {
            processes[i].ID = processes[i+1].ID;
            memcpy(processes[i].name, processes[i+1].name, strlen(processes[i+1].name));
        }

        processescount--;  
    }
}