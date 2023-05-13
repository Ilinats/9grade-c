#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

struct ListNode {
    double value;
    struct ListNode * next;
    struct ListNode * prev;
};

typedef struct {
    struct ListNode * head;
    struct ListNode * tail;
    int size;
} LinkedList;

LinkedList init();

struct ListNode * get(LinkedList * list, int index);

void push(LinkedList * list, int index, double value);
void pushback(LinkedList * list, double value);
void pushfront(LinkedList * list, double value);

void pop(LinkedList * list, int index);
void popfront(LinkedList * list);
void popback(LinkedList * list);

void release(LinkedList * list);

#endif