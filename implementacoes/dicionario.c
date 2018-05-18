#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*Modulos proprios*/
#include "../cabecalhos/estruturas.h"
#include "../cabecalhos/func_fila.h"
#include "../cabecalhos/func_arvore.h"
#include "../cabecalhos/dicionario.h"
#include "../cabecalhos/comprimir.h"
#include "../cabecalhos/descomprimir.h"

dicionario* criar_dicionario(){
	dicionario* novo =  (dicionario*) malloc(sizeof(dicionario));
	int i;
	for( i = 0; i < 256; i++)
	{
		novo->bytes[i] = NULL;
	}
	return novo;
}
void put(dicionario* ht, char* byte, unsigned char folha)
{
	int tamanho = strlen(byte);
	binario* novo_n = (binario*)malloc(sizeof(binario));
	
	char* novo = (char*)malloc((tamanho+1)*sizeof(char));
	strcpy(novo, byte);
	novo_n->byte = novo;
	ht->bytes[folha] = novo_n;
}

void escrever_dicionario(dicionario* ht)
{
	int i;
	printf("dicionario:\n");
	for(i = 0; i < 256; i++)
	{
		if(ht->bytes[i]!= NULL)
		{	
			if(i!='\n')
				printf("%c %s\n", i, ht->bytes[i]->byte);
			else
				printf("\\n %s\n", ht->bytes[i]->byte);
		}
	}
}
