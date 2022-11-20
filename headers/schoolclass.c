#include "person.h"
#include "schoolclass.h"

struct SchoolClass {
    PersonDef students[26];
    char class_ch;
    int class_num;
    PersonDef teacher;
};