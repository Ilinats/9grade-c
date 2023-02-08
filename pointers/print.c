#include <stdio.h>

int main() {

    int first;
    float second;

    printf("Enter an integer: ");
    scanf("%d", &first);
    printf("Enter a floating value: ");
    scanf("%f", &second);

    int *p = &first;
    float *v = &second;

    printf("Adress of int: %p\n", p);
    printf("Adress of float: %p\n", v);
    printf("Value of int: %d\n", *p);
    printf("Value of float: %f\n", *v);
    
    return 0; 
}