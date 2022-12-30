all: processes.exe

processes.o: processes.c processes.h
	gcc -c processes.c -o processes.o

taskmanager.o: taskmanager.c
	gcc -c taskmanager.c -o taskmanager.o

processes.exe: processes.o taskmanager.o
	gcc -o taskmanager processes.o taskmanager.o


clean:
	del *.exe *.o