#include <stdio.h>
#include <stdlib.h>
#define INVALID_NUMBER              \
    if(gradeCount < 1) {            \
        exit_error(1);              \
        exit(1); }

#define POINTER_ERROR      \
        if(!grades) {      \
            exit_error(2); \
            exit(1); }

void exit_error(int error_type) {
    if(error_type == 1)
        printf("Can't have this number of grades.");
    else
        printf("Error with dynamic memory.");
}

int main () {

    int gradeCount, op;

    printf("Number of grades: ");
    scanf("%d", &gradeCount);

    INVALID_NUMBER;

    float * grades = (float *) calloc(gradeCount, sizeof(float));

    POINTER_ERROR;

    for(int i = 0; i < gradeCount; i++) {
        printf("Enter grade %d: ", i+1);
        scanf("%f", &grades[i]);
    }


    do {
        printf("\n1. Avarage\n");
        printf("2. Add a grade\n");
        printf("3. Delete last grade\n");
        printf("4. Exit\n");
        printf("Choose an option (1, 2, 3 or 4): \n");
        scanf("%d", &op);

        switch(op)
        {
            case 1:
                float avr = 0;

                for(int i = 0; i < gradeCount; i++)
                    avr += grades[i];

                printf("The avarage is: %.2f\n", avr / gradeCount);
                break;

            case 2:
                gradeCount++;
                grades = (float *) realloc(grades, gradeCount * sizeof(float));

                POINTER_ERROR;

                printf("Enter the new grade: ");
                scanf("%f", &grades[gradeCount-1]);

                break;

            case 3:
                gradeCount--;

                INVALID_NUMBER;
                grades = (float *) realloc(grades, gradeCount * sizeof(float));

                POINTER_ERROR;
                
                break;

            case 4:
                free(grades);
                break;

            default:
                printf("Invalid option\n");
                break;
        }

        if(op == 4)
            break;
            
    } while(1);

    return 0;
}