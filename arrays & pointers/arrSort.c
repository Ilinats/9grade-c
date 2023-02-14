#include <stdio.h>
#define SIZE 4

void swap(int* first, int* second)
{
    int temp = *second;
    *second = *first;
    *first = temp;
}

void sort(int* arr) {
    for (int i = 0; arr + i <= arr + SIZE; i++) { 
        for (int j = i + 1; arr + j < arr + SIZE; j++) { 
            if (*(arr + j) < *(arr + i))
                swap((arr+j), (arr+i));
        } 
    } 
                
}

int main()
{
    int arr[SIZE] = {12, 2, 0, 4};

    sort(arr);
     
    for(int i = 0; i < SIZE; i++)
        printf("%d ", arr[i]);

    return 0;
}