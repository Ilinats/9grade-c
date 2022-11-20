#include "transformation.h"
#include <stdio.h>
#include <string.h>

struct Transformation str_to_int(char *str) {
    struct Transformation tmp;

    memset(&tmp, 0, sizeof (struct Transformation));

    int negative = *str == '-';
    if(negative)
        str++;

    while(*str >= '0' && *str <= '9') {
        tmp.result = tmp.result * 10 + *str - '0';
        str++;
    }

    if(*str) {
        tmp.result = 0;
        strcpy(tmp.error, "Invalid input string ");
        tmp.error[strlen(tmp.error)] = *str;
    }

    if(negative)
        tmp.result = -tmp.result;

    return tmp;
}