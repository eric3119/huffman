#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*Modulos proprios*/
#include "cabecalhos/estruturas.h"
#include "cabecalhos/func_fila.h"
#include "cabecalhos/func_arvore.h"
#include "cabecalhos/dicionario.h"
#include "cabecalhos/comprimir.h"
#include "cabecalhos/descomprimir.h"

int main(int argc, char const *argv[]){

	if(argc == 1){
		printf("nome_do_programa -operação nome_do_arquivo\n\n");
		printf("-c --> comprimir\n");
		printf("-d --> descomprimir\n");
		return 0;
	}

	if(strcmp(argv[1], "-c") == 0)
	{
		FILE *arquivo = fopen(argv[2], "rb");
		if(!arquivo){
			puts("erro ao abrir arquivo\n");
			return -1;
		}
		pre_compressao(arquivo);
	}
	else if(strcmp(argv[1], "-d") == 0)
	{
		FILE* arquivo = fopen(argv[2], "rb");
		if(!arquivo){
			puts("erro ao abrir arquivo\n");
			return -1;
		}
		descomprimir(arquivo);
	}
	else
	{
		printf("nome_do_programa -operação nome_do_arquivo\n\n");
		printf("-c --> comprimir\n");
		printf("-d --> descomprimir\n");
	}
	return 0;
}
