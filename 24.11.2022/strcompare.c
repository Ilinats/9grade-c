#include "mystrings.h"
#include <stdio.h>
  
int main(int argc, char* argv[])
{
    if(argc != 3)
        printf("Invalid number of arguments passed");
    else 
        printf("%d", strcompare(argv[1], argv[2]));
    return 0;
}