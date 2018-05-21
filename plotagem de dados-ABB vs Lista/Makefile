all: main clean
 
main: main.o abb.o lista.o
	gcc -o main main.o abb.o lista.o
 
main.o: main.c abb.h lista.h
	gcc -o main.o main.c -c

abb.o: abb.h
	gcc -o abb.o abb.c -c

lista.o: lista.h
	gcc -o lista.o lista.c -c

clean:
	rm -rf *.o *~