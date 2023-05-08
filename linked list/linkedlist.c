#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static struct ListNode * createnode(char * name, int priority, State stateOfTask) {
    struct ListNode * newnode = (struct ListNode *) malloc(sizeof(struct ListNode));
    if (newnode == NULL) {
        printf("Error allocating memory \n");
        exit(1);
    }
  
    strcpy(newnode->name, name);
    newnode->priority = priority;
    newnode->stateOfTask = stateOfTask;
    return newnode;
}

LinkedList init() {
    LinkedList list = {0, NULL};
    return list;
}

struct ListNode * get(LinkedList * list, int priority) {
    if (priority <= 0 || priority > list->size) {
        return NULL;
    }

    struct ListNode * currentnode = list->head;
    for (int i = 1; i < priority; i++) {
        currentnode = currentnode->next;
    }

    return currentnode;
}

void push(LinkedList * list, char * name, int priority, State stateOfTask) {
    if (priority <= 1) {
        pushfront(list, name, priority, stateOfTask);
    } else {
      struct ListNode * prev = get(list, priority-1);
      struct ListNode * newnode = createnode(name, priority, stateOfTask);
      newnode->next = prev->next;
      prev->next = newnode;
      list->size++;
    }

    if(priority != list->size) {
        struct ListNode * newnode = get(list, priority);
        struct ListNode * currentnode = newnode->next;
        while (currentnode != NULL) {
            currentnode->priority++;
            currentnode = currentnode->next;
        }
    }
}

void pushback(LinkedList * list, char * name, int priority, State stateOfTask) {
    push(list, name, list->size + 1, stateOfTask);
}

void pushfront(LinkedList * list, char * name, int priority, State stateOfTask) {
    struct ListNode * newnode = createnode(name, priority, stateOfTask);
    newnode->next = list->head;
    list->head = newnode;
    list->size++;
}

int pop(LinkedList * list, int priority) {
    if (priority <= 1) {
      return popfront(list);
    }

    struct ListNode * prev = get(list, priority-1);
    struct ListNode * nodetodelete = prev->next;
    prev->next = nodetodelete->next;
    list->size--;

    int result = nodetodelete->priority;
    free(nodetodelete);
    
    struct ListNode * currentnode = prev->next;
      while (currentnode != NULL) {
          currentnode->priority--;
          currentnode = currentnode->next;
      }
      
    return result;
}

int popfront(LinkedList * list) {
    struct ListNode * nodetodelete = list->head;
    list->head = list->head->next;
    list->size--;

    int result = nodetodelete->priority;
    free(nodetodelete);
    return result;
}


int popback(LinkedList * list) {
    return pop(list, list->size);
}

void releaseList(LinkedList * list) {
    for(int i = 0; i < list->size; i++) {
        struct ListNode * nodetodelete = list->head;
        list->head = list->head->next;
        free(nodetodelete);
    }
}

void set(LinkedList * list, int priority, State stateOfTask) {
  struct ListNode * node = get(list, priority);
  
  node->stateOfTask = stateOfTask;
}