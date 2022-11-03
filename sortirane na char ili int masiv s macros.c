/*
 * 6.Допълнителна задача:
 * Направете макро функция, която да сортира масив от произволен тип, и да може да сортира низходящо или възходящо в зависимост от аргумент, подаден на макрото.
 * Пример за дефиниция на подобно макро функция SORT(ARRAY, SIZE, TYPE, COMPARE).
 * Пример за използване на подобна макро функция: SORT(array, 5, int, >).
 * Хубаво е да се преизползва SWAP макро функцията от задача 5. Когато дефинирате макрото за да се чете по лесно кодът, можете да слагата “/” за да направите макрото на няколко реда.
 */

#include <stdio.h>

#define COUNT 5

#define SWAP(C, B, TYPE) \
            TYPE temp = C; \
            C = B; \
            B = temp;

#define SORT(ARRAY, SIZE, TYPE, COMPARE)                    \
            for (int num = 0; num < (SIZE - 1); num++)      \
                for (int i = 0; i < (SIZE - 1); i++)        \
                    if (ARRAY[i] COMPARE ARRAY[i + 1]) {    \
                        SWAP(ARRAY[i], ARRAY[i+1], TYPE);   \
                    }





int main()
{
    int arr[COUNT] = {4, 5, 2, 1, 7};
    char str[COUNT] = {'d', 'a', 'c', 'e', 'b'};

    SORT(str, COUNT, char, >);
    for (int i = 0; i < COUNT; i++)
        printf("%c ", str[i]);

    printf("\n");

    SORT(str, COUNT, char, <);
    for (int i = 0; i < COUNT; i++)
        printf("%c ", str[i]);

    printf("\n");

    SORT(arr, COUNT, int, >);
    for (int i = 0; i < COUNT; i++)
        printf("%d ", arr[i]);

    printf("\n");

    SORT(arr, COUNT, int, <);
    for (int i = 0; i < COUNT; i++)
        printf("%d ", arr[i]);

    return 0;
}
