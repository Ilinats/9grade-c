all: info.exe strlength.exe strcompare.exe strconcat.exe

info.exe:
	gcc info.c -o info.exe

clean:
	del *.exe *.o

mystrings.o: 
	gcc -c mystrings.c -o mystrings.o

strlength.exe: mystrings.o
	gcc strlength.c mystrings.o -o strlength.exe

strcompare.exe: mystrings.o
	gcc strcompare.c mystrings.o -o strcompare.exe

strconcat.exe: mystrings.o
	gcc strconcat.c mystrings.o -o strconcat.exe