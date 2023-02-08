#include <stdio.h>
#include <string.h>
#define SIZE 100

int main() {
    char str[SIZE];
    char ch = '\n';
    char *p;
    
    printf("Enter a string: ");
    fgets(str, SIZE, stdin);

    p = strchr(str, ch);

    if(p != NULL)
        *p = '\0';

    printf("%s", str);
    
    return 0; 
}