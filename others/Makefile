all: safeadd.o safedivide.o safemultiply.o safesubtract.o

safeint.o: safeint.c
	gcc -c safeint.c -o safeint.o

safeadd.o: safeadd.c safeint.o
	gcc safeadd.c safeint.o -o safeadd.exe

safedivide.o: safedivide.c safeint.o
	gcc safedivide.c safeint.o -o safedivide.exe

safemultiply.o: safemultiply.c safeint.o
	gcc safemultiply.c safeint.o -o safemultiply.exe

safesubtract.o: safesubtract.c safeint.o
	gcc safesubtract.c safeint.o -o safesubtract.exe

clean:
	del *.exe *.o