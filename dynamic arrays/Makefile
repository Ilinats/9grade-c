all: tests.exe donor.exe

tests.exe: dynarr.o tests.c
	gcc tests.c dynarr.o -o tests.exe

donor.exe: dynarr.o donor.c
	gcc donor.c dynarr.o -o donor.exe

dynarr.o: dynarr.h dynarr.c
	gcc -c dynarr.c -o dynarr.o

clean:
	del *.exe *.o