#ifndef SCHOOLCLASS_H
#define SCHOOLCLASS_H

#include "person.h"

struct SchoolClass {
    struct Person students[26];
    char class_ch;
    int class_num;
    struct Person teacher;
};

#endif