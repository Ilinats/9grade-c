// Направете програма (в отделен файл), която да използва динамичния масив, за да пази егн-тата на дарители на сиропиталище
// за деца, останали без родители. Програмата, трябва да дава възможност да се записва нов дарител, като се въвежда неговото
// егн, да се премахва потребител от списъка, като се подава неговото егн, да се изведат егн-тата на всички дарители и да 
// се излезе от програмата, като се освободят всички ресурси, заемани от динамичния масив.

#include <stdio.h>
#include "dynarr.h"

void printdynarr(DynamicArray * arr) {
  for (int i = 0; i < arr->size; i++) {
    printf("Donor %d: %g\n", i+1, getel(arr, i));
  }

  printf("\n");
}

int main() {

    DynamicArray donors = init(3);
    int op;
    do {
        printf("\n1. Add a donor\n");
        printf("2. Remove a donor\n");
        printf("3. Print the states of all diodes\n");
        printf("4. Quit\n");
        printf("Choose an option (1, 2, 3 or 4): ");
        scanf("%d", &op);

        switch(op)
        {
            case 1:
                double egn;
                printf("Enter EGN: ");
                scanf("%lf", &egn);
                pushback(&donors, egn);
                break;

            case 2:
                printf("Enter EGN: ");
                scanf("%lf", &egn);

                int index = findindex(&donors, egn);
                pop(&donors, index);
                break;

            case 3:
                printdynarr(&donors);
                break;
            
            case 4:
                releasedynarr(&donors);
                break;
        }

        if(op == 4)
            break;
            
    } while(1);


    return 0;
}