#include "schoolclass.h"
#include "schoolroom.h"

int main() {
    struct School {
        SchoolClassDef classes[20];
        SchoolRoomDef rooms[10];
    };
    return 0;
}