#include <stdio.h>
#include "mystrings.h"

int strlength(char *str) {
    int i = 0;
    for(; str[i] != 0; i++);
    
    return i;
}

void strconcat(char *str1, int str1_size, char *str2, int str2_size)
{
    int i = str1_size;
    
    for(int j = 0; j <= str2_size; j++)
        str1[i++] = str2[j];
        
    str1[i] = 0;

    printf("%s", str1);
}

int strcompare(char *str1, char *str2)
{
    int i = 0;
    
    for(; str1[i] && str1[i] == str2[i]; i++);

    int res = str1[i] - str2[i];
    return res < 0 ? -1 : res > 0 ? 1 : 0;
}