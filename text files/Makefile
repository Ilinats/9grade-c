all: main.exe

library.o: library.h library.c
	gcc -c library.c -o library.o

main.exe: main.c library.o
	gcc main.c library.o -o main.exe

clean:
	del *.o *.exe