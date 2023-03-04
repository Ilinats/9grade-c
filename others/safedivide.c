#include "safeint.h"
#include <stdio.h>
#include <limits.h>
  
int main(int argc, char* argv[])
{
    SafeResult temp;
    SafeResult temp2;
    SafeResult temp3;
    
    temp2 = safestrtoint(argv[1]);
    temp3 = safestrtoint(argv[2]);

    printf("Number 1: %d\n", temp2.value);
    printf("Number 2: %d\n", temp3.value);
    printf("%c\n", temp2.errorflag);
    printf("%c\n", temp3.errorflag);
    
    if(temp2.errorflag || temp3.errorflag)
        printf("Numbers are too big/small");   
    else {
        temp = safedivide(temp2.value, temp3.value);
        printf("%d", temp.errorflag);
        if(temp.errorflag)
            printf("Number after operation is too big/small");
        else
            printf("Result: %d", temp.value);
    }

    return 0;
}