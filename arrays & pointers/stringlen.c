#include <stdio.h>
#define SIZE 10

int lenOfStr(char* p) {
    int sum = 0;
    for(; *p != '\0'; p++)
        sum++;

    return sum;
}

int main()
{
    char str[SIZE] = "E";
    char *p = str;

    printf("Size of string is: %d", lenOfStr(p));

    return 0;
}