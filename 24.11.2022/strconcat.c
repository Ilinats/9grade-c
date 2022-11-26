#include "mystrings.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{    
    if(argc != 3)
        printf("Invalid number of arguments passed");
    else {    
        int size_1 = strlen(argv[1]);
        int size_2 = strlen(argv[2]);
        char arr[100];
        strcpy(arr, argv[1]);

        if(size_1 > 50 || size_2 > 50)
            printf("Strings shouldn't be longer than 50 characters");
        else
            strconcat(arr, size_1, argv[2], size_2);
    }

    return 0;
}