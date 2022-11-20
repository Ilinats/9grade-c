#include "schoolclass.h"
#include "schoolroom.h"

int main() {
    struct School {
        struct SchoolClass classes[20];
        struct SchoolRoom rooms[10];
    };
    return 0;
}