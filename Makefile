all: programa

run: programa

programa: main.o menu.o morse.o
	gcc main.o menu.o morse.o -o codificador

main.o: main.c
	gcc -c main.c

menu.o: menu.c menu.h
	gcc -c menu.c 

morse.o: morse.c morse.h
	gcc -c morse.c 

clean:
	rm  *.o programa