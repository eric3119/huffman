# huffman

compilar

gcc "implementacoes/comprimir.c" -c && gcc "implementacoes/descomprimir.c" -c && gcc "implementacoes/func_arvore.c" -c && gcc "implementacoes/func_fila.c" -c && gcc "implementacoes/dicionario.c" -c && gcc "comprimir.o"  "descomprimir.o"  "func_arvore.o"  "func_fila.o"  "dicionario.o"  main.c -o main

CUnit

sudo apt-get install libcunit1 libcunit1-doc libcunit1-dev

gcc "../implementacoes/func_arvore.c" -c && gcc "../implementacoes/func_fila.c" -c && gcc "../implementacoes/dicionario.c" -c && gcc "../implementacoes/comprimir.c" -c && gcc "func_arvore.o" "func_fila.o" "dicionario.o" "comprimir.o" cunit.c -o cunit -lcunit

plotagem de dados

gcc abb.c -c && gcc lista.c -c && gcc abb.o lista.o main.c -o main
