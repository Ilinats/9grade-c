#include <stdio.h>

#define COMMAND(NAME, TYPE) TYPE ## _ ## NAME ## _command();
#define DEFINE_COMMAND(NAME, TYPE) void COMMAND(NAME, TYPE) {\
                                                printf("AAA\n");\
                                            }
                                            
#define DEFINE_EXTERNAL_COMMAND(NAME) DEFINE_COMMAND(NAME, external)
#define DEFINE_INTERNAL_COMMAND(NAME) DEFINE_COMMAND(NAME, internal)
#define CALL_COMMAND(NAME, TYPE) DEFINE_COMMAND(NAME, TYPE)
#define CALL_INTERNAL_COMMAND(NAME) CALL_COMMAND(NAME, internal)
#define CALL_EXTERNAL_COMMAND(NAME) CALL_COMMAND(NAME, external)

int main(void) {
    
    DEFINE_COMMAND(quit, external);
//    COMMAND(quit, internal);
    DEFINE_INTERNAL_COMMAND(print);
    DEFINE_EXTERNAL_COMMAND(quit);
    CALL_COMMAND(quit, internal);
    CALL_INTERNAL_COMMAND(quit);
    CALL_EXTERNAL_COMMAND(delete);
    
    return 0;
}
