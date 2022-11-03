#include <stdio.h>

//__FILE__
//__LINE__

#define DEBUG(VALUE, FORMAT) printf("Name: " #VALUE ", Value: " FORMAT ", In file: %s, In line: %d", VALUE, __FILE__, __LINE__);

int main(void) {
    
    int varname = 5;
    
    DEBUG(varname, "%d");
    
    return 0;
}
