#include <stdio.h>
#define SIZE 10

int lenOfStr(char* p) {
    int sum = 0;
    for(; *p != '\0'; p++)
        sum++;
        
    return sum;
}

void strhalf(char* str, char** p) {
    int len = lenOfStr(str) / 2;
    *p += len;
}

int main()
{
    char str[SIZE] = "Karina";
    char *p = str;

    strhalf(str, &p);

    printf("String in half: %s", p);

    return 0;
}