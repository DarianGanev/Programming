all: tests.exe

dynarr.o: dynarr.h dynarr.c
	gcc -c dynarr.c -o dynarr.o

tests.exe: dynarr.o tests.c
	gcc tests.c dynarr.o -o tests.exe

clean:
	del *.o *.exe