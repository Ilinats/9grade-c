#ifndef SAFEINT_H
#define SAFEINT_H

typedef struct SafeResult {
    int value;
    char errorflag;
} SafeResult;

SafeResult safeadd(int num1, int num2);
SafeResult safesubtract(int num1, int num2);
SafeResult safemultiply(int num1, int num2);
SafeResult safedivide(int num1, int num2);
SafeResult safestrtoint(char* str);

#endif