#ifndef PERSON_H
#define PERSON_H

typedef enum education {
    UNEDUCATED = 1,
    PRIMARY,
    SECONDARY,
    HIGHER 
} Education;

typedef enum commitment {
    MARRIED = 1,
    NOTMARRIED 
} Commitment;

typedef enum work {
    EMPLOYED = 1,
    UNEMPLOYED
} Work;

typedef struct person {
    char name[255];
    char EGN[10];
    unsigned char age;
    Education education_state;
    Commitment commitment_state;
    Work work_state;
} Person;

typedef struct dynamicarr {
  Person * buffer;
  unsigned int capacity;
  unsigned int size;
} DynamicArray;

DynamicArray init(unsigned int capacity);
void pushback(DynamicArray * arr, Person value);
void pop(DynamicArray *arr, char * EGN);
int findindex(DynamicArray* arr, const char* EGN);
void releasedynarr(DynamicArray * arr);

#endif