#include <stdio.h>
#include "dynarr.h"

void printdynarr(DynamicArray * arr) {
  for (int i = 0; i < arr->size; i++) {
    printf("%lf ", getel(arr, i));
  }

  printf("\n");
}

int main(void) {
    DynamicArray arr = init(3);
    printdynarr(&arr);

    pushback(&arr, 5);
    pushback(&arr, 1);
    pushback(&arr, 7);
    pushback(&arr, 3);
    printdynarr(&arr);

    setel(&arr, 1, 2);
    setel(&arr, 7, 9);
    printdynarr(&arr);

    int result = popback(&arr);
    printf("Last element: %d\n", result);
    printdynarr(&arr);

    push(&arr, 2, 11);
    pushfront(&arr, 13);
    printdynarr(&arr);

    pop(&arr, 1);
    printdynarr(&arr);

    popfront(&arr);
    printdynarr(&arr);

    printf("%d\n", findindex(&arr, 7));

  return 0;
}