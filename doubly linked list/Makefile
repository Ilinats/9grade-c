all: main.exe

linkedlist.o: dlinkedlist.h dlinkedlist.c
	gcc -c dlinkedlist.c -o dlinkedlist.o

main.exe: main.c dlinkedlist.o
	gcc main.c dlinkedlist.o -o main.exe

clean:
	del *.o *.exe