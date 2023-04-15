#ifndef DYNARR_H
#define DYNARR_H

typedef struct {
  double * buffer;
  unsigned int capacity;
  unsigned int size;
} DynamicArray;

DynamicArray init(unsigned int capacity);

double getel(DynamicArray * arr, int index);

void setel(DynamicArray * arr, int index, double value);

void pushback(DynamicArray * arr, double value);

double popback(DynamicArray * arr);

void push(DynamicArray * arr, int index, double value);

void pushfront(DynamicArray * arr, double value);

//For homework
void pop(DynamicArray * arr, int index);

//For homework
double popfront(DynamicArray * arr);

int findindex(DynamicArray * arr, double value);

void releasedynarr(DynamicArray * arr);

#endif