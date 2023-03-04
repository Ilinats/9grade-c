#include <stdio.h>
#define MAX(a, b) a > b ? a : b 

int main()
{
    int a = 3, b = 8;
    
    printf("%d", MAX(a, b));

    return 0;
}