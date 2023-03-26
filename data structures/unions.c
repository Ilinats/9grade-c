#include <stdio.h>

typedef union index {
  long odd;
  short even;
} Index;

int main() {
    
    Index arr[10];

    for(int i = 0; i < 10; i++) {
        if(i % 2)
            arr[i].odd = i;
        else
            arr[i].even = i;
    }
    
    return 0;
}