#include <stdio.h>

int main()
{
    int a[] = {1, 7, 3, 4, 9, 2};
    int sum = 0;
    int c;
    int size = sizeof(a)/sizeof(int);
    
    for (int num = 0; num < 6; num++)
    {
        for (int i = 0; i < 6; i++)
        {
            if (a[i] > a[i + 1])
            {
                c = a[i];
                a[i] = a[i + 1];
                a[i + 1] = c;
            }
            
        }
    }
    
    for(int i = 0; i < 6; i++)
    {
        int n = a[i];
        sum += n * i;
    }
    
    printf("%d", sum);
    
    

    return 0;
}






