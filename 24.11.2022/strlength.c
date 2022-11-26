#include <stdio.h>
#include "mystrings.h"
  
int main(int argc, char* argv[])
{
    int counter;
    
    if(argc != 2)
        printf("Invalid number of arguments passed");
    else 
        printf("%d", strlength(argv[1]));
    return 0;
}