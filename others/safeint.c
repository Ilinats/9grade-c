#include <stdio.h>
#include "safeint.h"
#include <limits.h>
#include <string.h>

SafeResult safeadd(int num1, int num2) {
    
    SafeResult temp={0};
    
    long long result = (long long)num1 + num2;

    temp.value = result;
    temp.errorflag = result != temp.value;

    return temp;
}

SafeResult safesubtract(int num1, int num2) {
    
    SafeResult temp={0};
    
    long long result = (long long)num1 - num2;

    temp.value = result;
    temp.errorflag = result != temp.value;

    return temp;
}

SafeResult safemultiply(int num1, int num2) {
    
    SafeResult temp={0};
    
    long long result = (long long)num1 * num2;

    temp.value = result;
    temp.errorflag = result != temp.value;

    return temp;
}

SafeResult safedivide(int num1, int num2) {
    
    SafeResult temp={0};
    
    long long result = (long long)num1 / num2;

    temp.value = result;
    temp.errorflag = result != temp.value;

    return temp;
}

SafeResult safestrtoint(char *str) {
    SafeResult res={0};

    int negative = *str == '-';
    if(negative)
        *str++;

    while(*str) {
        if(*str < '0' || *str > '9') {
            res.errorflag = 1;
            break;
        }

        res = safemultiply(res.value,10);
        if(res.errorflag)
            break;

        res = safeadd(res.value, *str-'0');
        if(res.errorflag)
            break;

        str++;
    }

    if(negative)
        res.value = -res.value;

    return res;
}