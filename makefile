polyapp: main.o utils.o poly.o
	gcc -o polyapp main.o utils.o poly.o

main.o: main.c utils.h poly.h
	gcc -c main.c

utils.o: utils.c utils.h
	gcc -c utils.c

poly.o: poly.c utils.h poly.h polyterm.h
	gcc -c poly.c
