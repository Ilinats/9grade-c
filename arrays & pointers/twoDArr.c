#include <stdio.h>
#define ROWS 4

void print(int (* arr)[4], int rows)
{
    for (int i = 0; arr + i < arr + rows; i++) {
        for (int j = 0; j < 4; j++)
            printf("%d ", *(*(arr + i) + j));

        printf("\n");
    }
}

int main()
{
    int arr[ROWS][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {5, 6, 7, 8}, {5, 6, 7, 8}};

    print(arr, ROWS);

    return 0;
}