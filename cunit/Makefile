all: main clean

main: cunit.o comprimir.o descomprimir.o func_arvore.o func_fila.o dicionario.o
	gcc cunit.o comprimir.o descomprimir.o func_arvore.o func_fila.o dicionario.o -o cunit -lcunit

comprimir.o: ../implementacoes/comprimir.c ../cabecalhos/estruturas.h ../cabecalhos/comprimir.h ../cabecalhos/descomprimir.h ../cabecalhos/func_arvore.h ../cabecalhos/func_fila.h ../cabecalhos/dicionario.h
	gcc -o comprimir.o ../implementacoes/comprimir.c -c

descomprimir.o: ../implementacoes/descomprimir.c ../cabecalhos/estruturas.h ../cabecalhos/comprimir.h ../cabecalhos/descomprimir.h ../cabecalhos/func_arvore.h ../cabecalhos/func_fila.h ../cabecalhos/dicionario.h
	gcc -o descomprimir.o ../implementacoes/descomprimir.c -c
 
func_arvore.o: ../implementacoes/func_arvore.c ../cabecalhos/estruturas.h ../cabecalhos/comprimir.h ../cabecalhos/descomprimir.h ../cabecalhos/func_arvore.h ../cabecalhos/func_fila.h ../cabecalhos/dicionario.h
	gcc -o func_arvore.o ../implementacoes/func_arvore.c -c
 
func_fila.o: ../implementacoes/func_fila.c ../cabecalhos/estruturas.h ../cabecalhos/comprimir.h ../cabecalhos/descomprimir.h ../cabecalhos/func_arvore.h ../cabecalhos/func_fila.h ../cabecalhos/dicionario.h
	gcc -o func_fila.o ../implementacoes/func_fila.c -c
 
dicionario.o: ../implementacoes/dicionario.c ../cabecalhos/estruturas.h ../cabecalhos/comprimir.h ../cabecalhos/descomprimir.h ../cabecalhos/func_arvore.h ../cabecalhos/func_fila.h ../cabecalhos/dicionario.h
	gcc -o dicionario.o ../implementacoes/dicionario.c -c

clean:
	rm -rf *.o *~