#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef enum state {
    NEW = 1,
    IN_PROCESS,
    DONE
} State;

struct ListNode {
    int priority;
    State stateOfTask;
    char name[100];
    struct ListNode * next;
};

typedef struct {
  int size;
  struct ListNode * head;
} LinkedList;

LinkedList init();

struct ListNode * get(LinkedList * list, int priority);

void push(LinkedList * list, char * name, int priority, State stateOfTask);
void pushback(LinkedList * list, char * name, int priority, State stateOfTask);
void pushfront(LinkedList * list, char * name, int priority, State stateOfTask);

int pop(LinkedList * list, int priority);
int popfront(LinkedList * list);
int popback(LinkedList * list);

void releaseList(LinkedList * list);

void set(LinkedList * list, int priority, State stateOfTask);

#endif 