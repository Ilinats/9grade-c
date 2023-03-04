/* Направете програма, която да принтира таблица с информация за всеки един целочислен тип в C. Всеки ред от таблицата 
трябва да съдържа името на типа, формата, чрез който се принтира, колко байта заема, максималната стойност на знаковата 
(signed) версията на типа, минималната стойност на знаковата (signed) стойност на типа  и формата на безнаковата версия 
и максималната стойност на безнаковата версия на типа (unsigned). Можете да използвате макро за да съкратите работата по
принтирането на данните.*/
#include <stdio.h>
#include <limits.h>

int main() {
    
    printf("%-14s%-10s%-10s%-20s%-24s%-17s%-17s\n", "Type", "Format", "Size", "Signed max", "Signed min", "Unsigned Format", "Unsigned max");
    printf("%-14s%-10s%-10zu%-20d%-24d%-17s%-17s\n", "int", "%d", sizeof(int), INT_MAX, INT_MIN, "%u", "2^16-1");
    printf("%-14s%-10s%-10zu%-20d%-24d%-17s%-17s\n", "short", "%hd", sizeof(short int), SHRT_MAX, SHRT_MIN, "%hu", "2^16-1");
    printf("%-14s%-10s%-10zu%-20d%-24d%-17s%-17s\n", "long", "%ld", sizeof(long int), LONG_MAX, LONG_MIN, "%lu", "2^32-1");
    printf("%-14s%-10s%-10zu%-20lld%-24lld%-17s%-17s\n", "long long", "%lld", sizeof(long long int), LLONG_MAX, LLONG_MIN, "%llu", "2^64-1");
    printf("%-14s%-10s%-10zu%-20d%-24d%-17s%-17s\n", "char", "%c", sizeof(char), SCHAR_MAX, SCHAR_MIN, "%c", "2^8-1");

    return 0;
}