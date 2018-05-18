# huffman

compilar

gcc "implementacoes/comprimir.c" -c && gcc "implementacoes/descomprimir.c" -c && gcc "implementacoes/func_arvore.c" -c && gcc "implementacoes/func_fila.c" -c && gcc "implementacoes/dicionario.c" -c && gcc "comprimir.o"  "descomprimir.o"  "func_arvore.o"  "func_fila.o"  "dicionario.o"  main.c -o main
