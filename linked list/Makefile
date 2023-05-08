all: main.exe

linkedlist.o: linkedlist.h linkedlist.c
	gcc -c linkedlist.c -o linkedlist.o

main.exe: main.c linkedlist.o
	gcc main.c linkedlist.o -o main.exe

clean:
	del *.o *.exe