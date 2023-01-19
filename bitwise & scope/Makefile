all: bitstate.o robot.exe

bitstate.o: bitstate.c bitstate.h
	gcc -c bitstate.c -o bitstate.o

robot.exe: bitstate.o robot.c
	gcc -o robot.exe bitstate.o robot.c

clean:
	del *.exe *.o