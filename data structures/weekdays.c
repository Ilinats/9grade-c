#include <stdio.h>

typedef enum weekdays {
  SUNDAY,
  MONDAY,
  TUESDAY,
  WEDNESDAY,
  THURSDAY,
  FRIDAY,
  SATURDAY
} WEEKDAYS;

int main() {

    WEEKDAYS input;
    printf("Enter a number(1-7): ");
    scanf("%d", &input);

    input = (WEEKDAYS) input-1;

    switch(input) {
        case SUNDAY:
            printf("Sunday");
            break;

        case MONDAY:
            printf("Monday");
            break;

        case TUESDAY:
            printf("Tuesday");
            break;

        case WEDNESDAY:
            printf("Wednesday");
            break;

        case THURSDAY:
            printf("Thursday");
            break;

        case FRIDAY:
            printf("Friday");
            break;

        case SATURDAY:
            printf("Saturday");
            break;

        default:
            printf("Invalid input");
            break;
    }

    return 0;
}