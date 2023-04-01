#include <stdio.h>

typedef struct {
    int hour;
    int minutes;
} Timeofday;

typedef struct {
    char firstname[15];
    char secondname[15];
    char thirdname[15];
    char email[30];
    char phone[15];
} Person;

typedef struct {
    Person participant;
    int isParticipating;
} Participants;

typedef struct {
    char title[30];
    char description[100];
    struct {
        int day;
        int month;
        int year;
        Timeofday timeOfDay;
    } date;
    Participants participant[100];    
} Cause;

int main() {

    Cause cause1 = {.description = "Something 1", title: "Name 1", participant: {[0]{{"Stoqn", "Aleksandrov", "Georgiev", "ert@gmail.com", "0887564493"}, 1}, [1]{{"Gosho", "Aleksandrov", "Georgiev", "sdjfh@gmail.com", "0887654343"}, 1}}, date: {2, 3, 2003, {12, 34}}};
    Cause cause2 = {.description = "Something 2", title: "Name 2", participant: {[0]{{"Sasho", "Nikolaev", "Canov", "tryu@gmail.com", "0887564493"}, 1}, [1]{{"Boris", "Iliev", "Georgiev", "sdf@gmail.com", "0889754493"}, 1}}, date: {12, 6, 1999, {4, 18}}};
    printf("%s", cause1.participant[1].participant.firstname);

    return 0;
}