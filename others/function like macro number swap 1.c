#include <stdio.h>
#define SWAP(C, B, TYPE)\
            C += B;\
            B = C - B;\
            C = C - B;\
            printf("a = "TYPE" \n", C);\
            printf("b = "TYPE" ", B);

int main()
{
    int a = 7, b = 8;
    
    SWAP(a, b, "%d");
    
    return 0;
}
