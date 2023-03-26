#include <stdio.h>
#include <stdlib.h>

typedef struct student {
    char name[15];
    int number;
    double avrGrade;
} Students;

int main() {

    int op, studentCount = 1, first = 1;
    Students * students = (Students *)calloc(1, sizeof(Students *));

    do {
        printf("\n1. Add student\n");
        printf("2. Show all students\n");
        printf("3. Exit\n");
        printf("Choose an option (1, 2 or 3): \n");
        scanf("%d", &op);

        switch(op)
        {
            case 1:

                if(!first)
                    students = (Students *)realloc(students, ++studentCount * sizeof(Students));
                else
                    first = 0;

                printf("Student name: ");
                scanf("%s", students[studentCount-1].name);
                getchar();

                printf("Number in class: ");
                scanf("%d", &students[studentCount-1].number);

                printf("Avarage grade: ");
                scanf("%lf", &students[studentCount-1].avrGrade);

                break;

            case 2:

                for(int i = 0; i < studentCount; i++) {
                    printf("\n%-15s %-15d %-15lf", students[i].name, students[i].number, students[i].avrGrade);
                }

                break;

            case 3:
                free(students);
                break;

            default:
                printf("Invalid option\n");
                break;
        }

        if(op == 3)
            break;
            
    } while(1);

    return 0;
}