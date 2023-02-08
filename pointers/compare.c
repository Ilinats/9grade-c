#include <stdio.h>

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
    
    int first = 3;
    int second = 5;
    void * pFirst = &first;
    void * pSecond = &second;
    
    printf("%d\n", compareasc(pFirst, pSecond));
    printf("%d", comparedesc(pFirst, pSecond));

    return 0; 
}