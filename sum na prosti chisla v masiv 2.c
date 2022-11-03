#include <stdio.h>

int isPrime(n)
{
    for(int j = n-1; j > 1; j--)
        {
            if(n % j == 0)
                return 0;
        } 
        
    return 1;
}

int main()
{
    int a[] = {1, 7, 10, 15, 16, 13, 23, 30};
    int size = sizeof(a)/sizeof(int);
    int sum = 0;
    
    for(int i = 0; i < size; i++) 
    {
        if(isPrime(a[i]) == 1 && a[i] != 1)
            sum += a[i];
    }
    
    printf("%d", sum);

    return 0;
}


