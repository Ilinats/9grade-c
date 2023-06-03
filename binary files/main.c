#include <stdio.h>
#include <stdlib.h>
#include "person.h"
#include "fileUtil.h"

void printdynarr(DynamicArray *arr)
{
    for (int i = 0; i < arr->size; i++) {
        printf("\n%-15s %-15s %-15d ", arr->buffer[i].name, arr->buffer[i].EGN, arr->buffer[i].age, arr->buffer[i].education_state, arr->buffer[i].commitment_state, arr->buffer[i].work_state);

        switch (arr->buffer[i].education_state) {
        case 1:
            printf("%-15s ", "Uneducated");
            break;
        case 2:
            printf("%-15s ", "Primary");
            break;
        case 3:
            printf("%-15s ", "Secondary");
            break;
        case 4:
            printf("%-15s ", "Higher");
            break;
        }

        switch (arr->buffer[i].commitment_state) {
        case 1:
            printf("%-15s ", "Married");
            break;
        case 2:
            printf("%-15s ", "Not married");
            break;
        }

        switch (arr->buffer[i].work_state) {
        case 1:
            printf("%-15s ", "Employed");
            break;
        case 2:
            printf("%-15s ", "Unemployed");
            break;
        }
    }

    printf("\n");
}

void saveToFile(char * filename, DynamicArray arr, int peopleCount) {
    FILE * outputFile = fopen(filename, "wb");
    ASSERT_OPEN_FILE(outputFile);

    fwrite(&peopleCount, sizeof(int), 1, outputFile);
    fwrite(arr.buffer, sizeof(Person), peopleCount, outputFile);

    fclose(outputFile);
}

int main(void) {
    DynamicArray people = init(3);

    FILE * inputFile = fopen("person.bin", "ab+");
    ASSERT_OPEN_FILE(inputFile);

    int peopleCount = 0;
    fread(&peopleCount, sizeof(int), 1, inputFile);
    printf("Number of people: %d\n", peopleCount);

    Person* buffer = (Person*)malloc(sizeof(Person) * peopleCount);
    if (buffer == NULL) {
        printf("Memory allocation failed.\n");
        fclose(inputFile);
        return 1;
    }

    fread(buffer, sizeof(Person), peopleCount, inputFile);
    for (int i = 0; i < peopleCount; i++) {
        pushback(&people, buffer[i]);
    }
    free(buffer);

    fclose(inputFile);

    int op;

    do {
        printf("\n1. Add a person\n");
        printf("2. Remove a person\n");
        printf("3. Print all people\n");
        printf("4. Quit\n");
        printf("Choose an option (1, 2, 3 or 4): ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                Person person;
                printf("Name: ");
                scanf("%s", person.name);

                printf("EGN: ");
                scanf("%s", person.EGN);
                getchar();

                printf("Age: ");
                scanf("%c", &person.age);
                getchar();

                printf("Education: ");
                scanf("%d", &person.education_state);

                printf("Commitment: ");
                scanf("%d", &person.commitment_state);

                printf("Work: ");
                scanf("%d", &person.work_state);
            
                peopleCount++;
                pushback(&people, person);

                saveToFile("person.bin", people, peopleCount);
                break;

            case 2:
                char EGN[10];
                printf("Enter EGN: ");
                scanf("%s", EGN);

                pop(&people, EGN);
                peopleCount--;

                break;

            case 3:
                printdynarr(&people);
                break;

            case 4:
                releasedynarr(&people);
                break;

            default:
                printf("No such option.");
        }

        if (op == 4)
            break;

    } while (1);

    return 0;
}