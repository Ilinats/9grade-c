#ifndef LIBRARY_H
#define LIBRARY_H

typedef struct book {
    char name[100];
    char author[100];
    char genre[50];
    int date;
    char isbn[100];
} Book;

typedef struct {
  Book * buffer;
  unsigned int capacity;
  unsigned int size;
} DynamicArray;

DynamicArray init(unsigned int capacity);

void pushback(DynamicArray * arr, Book value);

void pop(DynamicArray * arr, char * ISBN);

int findindex(DynamicArray * arr, const char* ISBN);

Book getel(DynamicArray * arr, int index);

void releasedynarr(DynamicArray * arr);

#endif