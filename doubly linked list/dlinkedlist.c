#include "dlinkedlist.h"
#include <stdlib.h>
#include <stdio.h>

int isFirst = 1;

static struct ListNode * createnode(double value) {
    struct ListNode * newnode = (struct ListNode *) malloc(sizeof(struct ListNode));
    if (newnode == NULL) {
        printf("Error allocating memory \n");
        exit(1);
    }
    newnode->value = value;
    return newnode;
}

LinkedList init() {
    LinkedList list = {size: 0, head: NULL, tail: NULL};
    return list;
};

struct ListNode * get(LinkedList * list, int index) {
    if (index < 0 || index >= list->size)
        return NULL;

    struct ListNode * currentnode;

    if(index <= list->size/2) {
        currentnode = list->head;
        for (int i = 0; i < index; i++)
            currentnode = currentnode->next;
    } else {
        currentnode = list->tail;
        for (int i = list->size-1; i > index; i--)
            currentnode = currentnode->prev;
    }

    return currentnode;
}

void pushback(LinkedList * list, double value) {
    struct ListNode * prev = list->tail;
    struct ListNode * newnode = createnode(value);
    newnode->next = NULL;
    newnode->prev = prev;
    prev->next = newnode;
    list->tail = newnode;
    list->size++;
}

void pushfront(LinkedList * list, double value) {
    struct ListNode * newnode = createnode(value);

    newnode->next = list->head;
    list->head = newnode;
    list->head->prev = newnode; 
    newnode->prev = NULL;
    list->size++;
    if(isFirst) {
        list->tail = newnode;
        isFirst = 0;
    }
}

void push(LinkedList * list, int index, double value) {
    if (index == 0) {
        pushfront(list, value);
        return;
    } else if (index == list->size-1) {
        pushback(list, value);
    }

    struct ListNode * prev = get(list, index-1);
    struct ListNode * newnode = createnode(value);
    newnode->next = prev->next;
    newnode->prev = prev;
    prev->next->prev = newnode;
    prev->next = newnode;
    list->size++;
}

void popfront(LinkedList * list) {

    struct ListNode * nodetodelete = list->head;
    list->head = nodetodelete->next;
    list->head->prev = NULL;
    list->size--;

    free(nodetodelete);
}

void popback(LinkedList * list) {
    struct ListNode * prev = list->tail->prev;
    struct ListNode * nodetodelete = list->tail;

    prev->next =NULL;
    list->tail = prev;
    list->size--;
    
    free(nodetodelete);
}

void pop(LinkedList * list, int index) {
    if (index == 0)
        return popfront(list);
    else if (index == list->size-1) {
        popback(list);
    }

    struct ListNode * prev = get(list, index - 1);
    struct ListNode * nodetodelete = prev->next;
    prev->next = nodetodelete->next;
    nodetodelete->next->prev = nodetodelete->prev;
    list->size--;

    free(nodetodelete);
}

void release(LinkedList * list) {
    for(int i = 0; i < list->size; i++) {
        struct ListNode * nodetodelete = list->head;
        list->head = list->head->next;
        free(nodetodelete);
    }
}