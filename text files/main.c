#include <stdio.h>
#include <stdlib.h>
#include "library.h"
#include <string.h>

void printdynarr(DynamicArray *arr)
{
    for (int i = 0; i < arr->size; i++) {
        printf("\n%-15s %-15s %-15s %-15d %-15s", arr->buffer[i].name, arr->buffer[i].author, arr->buffer[i].genre, arr->buffer[i].date, arr->buffer[i].isbn);
    }

    printf("\n");
}

Book enterBook() {
    Book newBook;

    printf("Name: ");
    scanf("%s", newBook.name);

    printf("Author: ");
    scanf("%s", newBook.author);

    printf("Genre: ");
    scanf("%s", newBook.genre);

    printf("Date: ");
    scanf("%d", &newBook.date);

    printf("ISBN: ");
    scanf("%s", newBook.isbn);

    return newBook;
}

void saveToFile(DynamicArray* arr, int count) {
    FILE* file = fopen("books.txt", "w");

    if (file == NULL) {
        printf("Error in opening.\n");
        exit(1);
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "Name: %s\n", arr->buffer[i].name);
        fprintf(file, "Author: %s\n", arr->buffer[i].author);
        fprintf(file, "Genre: %s\n", arr->buffer[i].genre);
        fprintf(file, "Date: %d\n", arr->buffer[i].date);
        fprintf(file, "ISBN: %s\n", arr->buffer[i].isbn);
    }

    fclose(file);
}

void readFromFile(DynamicArray* arr) {
    FILE* file = fopen("books.txt", "r");

    if (file != NULL) {
        char line[100];
        Book book;
        int lineCount = 0;

        while (fgets(line, sizeof(line), file)) {
            line[strcspn(line, "\n")] = '\0';

            switch (lineCount % 5) {
                case 0:
                    strncpy(book.name, line + 6, sizeof(book.name));
                    break;
                case 1:
                    strncpy(book.author, line + 8, sizeof(book.author));
                    break;
                case 2:
                    strncpy(book.genre, line + 7, sizeof(book.genre));
                    break;
                case 3:
                    book.date = atoi(line + 6);
                    break;
                case 4:
                    strncpy(book.isbn, line + 6, sizeof(book.isbn));
                    pushback(arr, book);
                    break;
            }

            lineCount++;
        }

        fclose(file);
    } else {
        printf("Error in opening the file.\n");
    }
}

int main()
{
    DynamicArray books = init(3);
    readFromFile(&books);
    int op;

    do {
        printf("\n1. Add a book\n");
        printf("2. Remove a book\n");
        printf("3. Print all books\n");
        printf("4. Save into a file\n");
        printf("5. Quit\n");
        printf("Choose an option (1, 2, 3, 4 or 5): ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                Book data = enterBook();
                pushback(&books, data);
                break;

            case 2:
                char ISBN[100];
                printf("Enter ISBN: ");
                scanf("%s", ISBN);

                pop(&books, ISBN);
                break;

            case 3:
                printdynarr(&books);
                break;

            case 4:
                saveToFile(&books, books.size);
                break;

            case 5:
                releasedynarr(&books);
                break;

            default:
                printf("No such option.");
        }

        if (op == 5)
            break;

    } while (1);

    return 0;
}
