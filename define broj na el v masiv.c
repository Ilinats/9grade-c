#include <stdio.h>
#define COUNT 5

int main()
{
    int arr[COUNT] = {4, 3, 2, 5, 6};
    
    for(int i = 0; i < COUNT; i++)
    {
        printf("%d ", arr[i]);    
    }

    return 0;
}
