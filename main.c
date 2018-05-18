#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*Modulos proprios*/
#include "estruturas.h"
#include "func_fila.h"
#include "func_arvore.h"
#include "hash.h"
#include "comprimir.h"
#include "descomprimir.h"

int main(int argc, char const *argv[]){

	if(argc == 1){
		puts("Arquivo nao encontrado!\n");
		return 0;
	}

	if(strcmp(argv[2], "comprimir") == 0)
	{
		FILE *arquivo = fopen(argv[1], "rb");
		if(!arquivo){
			puts("erro ao abrir arquivo\n");
			return -1;
		}
		pre_compressao(arquivo);
	}
	else if(strcmp(argv[2], "descomprimir") == 0)
	{
		FILE* arquivo = fopen(argv[1], "rb");
		if(!arquivo){
			puts("erro ao abrir arquivo\n");
			return -1;
		}
		descomprimir(arquivo);
	}
	else
	{
		printf("Operacao nao reconhecida!\n");
	}
	return 0;
}
