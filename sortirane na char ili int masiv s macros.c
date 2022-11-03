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
