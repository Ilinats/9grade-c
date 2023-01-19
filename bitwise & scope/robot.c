#include <stdio.h>
#include <stdlib.h>
#include "bitstate.h"

int main() {

    unsigned char rooms = 0;

    int op;
    do {
        printf("1. Turn on a diode\n");
        printf("2. Turn off a diode\n");
        printf("3. Switch a diode\n");
        printf("4. Check the state of a diode\n");
        printf("5. Print the states of all diodes\n");
        printf("6. Quit\n");
        printf("Choose an option (1, 2, 3, 4, 5 or 6): ");
        scanf("%d", &op);

        switch(op)
        {
            case 1:
                int pos;
                printf("Choose a position (1-32): \n");
                scanf("%d", &pos);
                printf("\n");

                setbit(pos-1);

                break;

            case 2:
                printf("Choose a position (1-32): \n");
                scanf("%d", &pos);
                printf("\n");

                unsetbit(pos-1);

                break;

            case 3:
                printf("Choose a position (1-32): \n");
                scanf("%d", &pos);
                printf("\n");

                togglebit(pos-1);

                break;
            
            case 4:
                printf("Choose a position (1-32): \n");
                scanf("%d", &pos);
                printf("\n");

                int temp = isbitset(pos-1);

                if(temp == 0)
                    printf("Diode is turned off\n");
                else if(temp == 1)
                    printf("Diode is turned on\n");
                else
                    printf("There is no such diode\n");

                break;

            case 5:
                printf("%u\n", getbitstate());

                break;

            
            case 6:
                break;

            default:
                printf("Invalid option\n");
                break;
        }

        if(op == 6)
            break;
            
    } while(1);

    return 0;
}