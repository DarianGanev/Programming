all: processes.o taskmanager.exe

processes.o: processes.c processes.h
	gcc -c processes.c

taskmanager.exe: taskmanager.c processes.o
	gcc -o taskmanager.exe taskmanager.c processes.o

clean:
	del processes.o taskmanager.exe
