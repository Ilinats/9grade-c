#ifndef BITSATE_H
#define BITSATE_H

void setbit (int position);
void unsetbit (int position);
void togglebit (int position);
int isbitset (int position);
unsigned int getbitstate (void);

#endif

/*1.Направете модул, който се казва “bitstate”, който се състои от два файла: bitstate.h и bitstate.c. В модула 
декларирайте глобална променлива bitstate, която да пази 32 битово състояние (тоест да се състои от 32 бита). За целта 
използвайте обикновена променлива, а не масив за да направите програмата по-оптимална. Глобалната променлива не трябва 
да се вижда извън границите на модула за да не би някой инцидентно да я промени. Направете метод който да се казва 
“setbit”, който да приема номера на бит и да прави съответния бит на глобалната променлива единица. Направете метод, 
който да се казва unsetbit, който да приема номер на бит и да сваля съответния бит от глобалната променлива (да го прави 0). 
Направете метод който се казва “togglebit”, който да приема номер на бит и да вдига бита на глобалната променлива ако е 
нула или да го сваля ако е единица. Методите трябва да работят с входни параметри от 0 до 31. Ако се подаде различно от 
тях число, извикването на метода не трябва да има никакъв ефект. Направете метод “isbitset”, която да приема номер на бит
и да връща дали бита е вдигнат или не. Методът isbitset трябва да връща 1 ако битът е вдигнат и 0 ако не е вдигнат и -1 
ако е подаден невалиден входен бит. Направете метод getbitstate, който да връща стойността на глобалната променлива. 
Методите трябва да са видими извън границите на модула.

2. Направете програма„ която се казва robot и която да симулира работа на робот, който има 32 диода. 
В програмата направете меню което да дава възможност на потребителя да включи диод на робота, да изключи диод на робота, 
да превключи диод на робота (от запален да го направи изгасен от изгасен на запален), да провери състоянието на диод 
(дали е запален или не) или да принтира състоянието на всички диоди. Номерата на диодите започват от 1 до 32. За изпълнение 
на логиката програмата трябва да използва модула “bitstate”.

3.Направете Makefile, който да построява модула и програмата.*/