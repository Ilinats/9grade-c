#include <stdio.h>
#define SIZE 5

void bubblesort(int *arr, int arrSize, int (* cmp)(void *, void *)) {

    for (int i = 0; i < arrSize - 1; i++) {
        for (int j = 0; j < arrSize - i - 1; j++) {

            if (((* cmp)((void *)(arr+j), (void *)(arr+j+1))) == 1) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    for(int i = 0; i < SIZE; i++) 
        printf("%d ", arr[i]);
}

int compareasc(void* pFirst, void* pSecond) {
    int result = 0;
    int first = *(int *)pFirst;
    int second = *(int *)pSecond;
    
    if(first != second)
        result = first > second ? 1 : -1;

    return result;
}

int comparedesc(void* pFirst, void* pSecond) {
    int result = 0;
    int first = *(int *)pFirst;
    int second = *(int *)pSecond;
    
    if(first != second)
        result = first < second ? 1 : -1;

    return result;
}

int main() {
    
    int arr[SIZE] = {3, 1, 8, 2, 0};

    int (* comAsc)(void*, void*) = compareasc;
    int (* comDesc)(void*, void*) = comparedesc;
    bubblesort(arr, SIZE, comparedesc);
    return 0; 
}