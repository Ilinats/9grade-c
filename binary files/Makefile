all: main.exe

person.o: person.h person.c
	gcc -c person.c -o person.o

main.exe: main.c person.o fileUtil.h
	gcc main.c person.o -o main.exe

clean:
	del *.o *.exe