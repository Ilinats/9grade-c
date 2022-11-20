#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H

struct Transformation {
    long result;
    char error[100];
};

struct Transformation str_to_int(char *str);

#endif