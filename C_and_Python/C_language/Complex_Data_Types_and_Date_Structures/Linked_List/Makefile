all: todo.exe

linkedlist.o: linkedlist.h linkedlist.c
	gcc -c linkedlist.c -o linkedlist.o

todo.exe: linkedlist.o main.c
	gcc main.c linkedlist.o -o todo.exe

clean:
	del *.o *.exe