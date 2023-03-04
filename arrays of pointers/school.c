#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    
    int op, subjCount, first = 1, studentCount = 1;
    char ** students = (char **)calloc(1, sizeof(char *));

    do {
        printf("Subjects count: ");
        scanf("%d", &subjCount);
    } while(subjCount < 1);

    char ** subjNames = (char **)calloc(subjCount, sizeof(char *));
    int ** grades = (int **)calloc(subjCount, sizeof(int *));

    for(int i = 0; i < subjCount; i++) {
        subjNames[i] = (char *)calloc(15, sizeof(char));
        printf("Subject %d name: ", i+1);
        scanf("%s", subjNames[i]);
        getchar();
    }
    
    do {
        printf("\n1. Add a new student");
        printf("\n2. Print table");
        printf("\n3. Exit\n");
        scanf("%d", &op);
        
        switch(op) {
            case 1: 
                if(first){
                    first = 0;
                    for(int i = 0; i < subjCount; i++)
                        grades[i] = (int *)calloc(studentCount, sizeof(int));
                }
                else {
                    students = (char **)realloc(students, ++studentCount*sizeof(char *));

                    for(int i = 0; i < subjCount; i++)
                        grades[i] = (int *)realloc(grades[i], studentCount * sizeof(int));
                }

                students[studentCount-1] = (char *)calloc(15, sizeof(char));
                printf("Student name: ");
                scanf("%s", students[studentCount-1]);
                getchar();

                for(int i = 0; i < subjCount; i++)
                    for(int j = studentCount-1; j < studentCount; j++) {
                        printf("Grade for %s: ", subjNames[i]);
                        scanf("%d", &grades[i][j]);
                    }
        
                break;
            
            case 2: 
                printf("%-15s", "Name / Subject");
                for(int i = 0; i < subjCount; i++)
                    printf("|%15s", subjNames[i]);

                printf("\n---------------");
                for(int i = 0; i < subjCount; i++)
                    printf("+---------------", subjNames[i]);

                for(int i = 0; i < studentCount; i++) {
                    printf("\n%-15s", students[i]);

                    for(int j = 0; j < subjCount; j++) {
                            printf("|%15d", grades[j][i]);
                    }
                }

                break;
                
            case 3: 
                break;
            
            default:
                printf("Incorect choice");
                break;
        }
        
    } while (op != 3);

    for (int i = 0; i < subjCount; i++)
        free(subjNames[i]);

    free(subjNames);

    for (int i = 0; i < studentCount; i++)
        free(students[i]);

    free(students);

    for (int i = 0; i < subjCount; i++)
        free(grades[i]);

    free(grades);
    
    return 0;
}
