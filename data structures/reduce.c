#include <stdio.h>

typedef unsigned long long ull;

ull add(ull a, ull b) {
  return a + b;
}

typedef ull (*ADDER)(ull, ull);

ull reduce(ull *arr, ull size_of_arr, ADDER fptr, ull index) {
    ull result = 0;

    for(int i = 0; i < size_of_arr; i++)
        result = (*fptr)(result, arr[i]);

    return result;
}

int main() {

    ull arr[3] = {1, 2, 3};
    ADDER fptr = add;

    printf("%llu", reduce(arr, 3, fptr, 0));

    return 0;
}