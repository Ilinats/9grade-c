#include <stdio.h>
#define SWAP(C, B, TYPE)\
            TYPE temp = C;\
            C = B;\
            B = temp;

int main()
{
    char a = 'r', b = 't';
    
    SWAP(a, b, char);
    
    printf("a = %c \n", a);
    printf("b = %c \n", b);
    
    return 0;
}
