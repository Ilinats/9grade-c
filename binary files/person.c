#include <stdio.h>
#include "person.h"
#include <stdlib.h>
#include <string.h>

#define ASSERT_MEMORY_ALLOC(PTR) \
  if ((PTR) == NULL) { \
    printf("Error allocating memory \n"); \
    exit(1); \
  } \

static void resize(DynamicArray * arr, int newsize) {
  if (newsize > arr->capacity) {
    arr->capacity *= 2;
    arr->buffer = (Person *) realloc(arr->buffer, sizeof(Person) * arr->capacity);
    ASSERT_MEMORY_ALLOC(arr->buffer);
  } else if (newsize <= arr->capacity / 2) {
    arr->capacity /= 2;
    arr->buffer = (Person *) realloc(arr->buffer, sizeof(Person) * arr->capacity);
    ASSERT_MEMORY_ALLOC(arr->buffer);
  }
  arr->size = newsize;
}

DynamicArray init(unsigned int capacity) {
  DynamicArray arr = {
    capacity: capacity,
    size: 0,
    buffer: NULL
  };

  arr.buffer = (Person *) calloc (arr.capacity, sizeof(Person));
  ASSERT_MEMORY_ALLOC(arr.buffer);

  return arr;
}

void pushback(DynamicArray * arr, Person value) {
  int newsize = arr->size + 1;
  resize(arr, newsize);
  arr->buffer[arr->size - 1] = value;
}

void pop(DynamicArray *arr, char * EGN)
{
    int index = findindex(arr, EGN);
    
    if (index < 0 || index >= arr->size) {
        printf("The index is out of bounds\n");
        exit(1);
    }

    for (int i = index; i < arr->size - 1; i++)
        arr->buffer[i] = arr->buffer[i + 1];

    resize(arr, arr->size - 1);
}

int findindex(DynamicArray* arr, const char* EGN)
{
    int result = -1;

    for (int i = 0; i < arr->size; i++) {
        if (strcmp(arr->buffer[i].EGN, EGN) == 0) {
            result = i;
            break;
        }
    }

    return result;
}

void releasedynarr(DynamicArray * arr) {
  if (arr->buffer != NULL) {
    free(arr->buffer);
    arr->buffer = NULL;
  }
  arr->capacity = 0;
  arr->size = 0;
}