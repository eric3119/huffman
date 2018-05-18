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

configuracoes* criar_configuracoes(){
	configuracoes* novo =  (configuracoes*) malloc(sizeof(configuracoes));
	int i;
	for( i = 0; i < 256; i++)
	{
		novo->bytes[i] = NULL;
	}
	return novo;
}
void put(configuracoes* ht, char* byte, unsigned char folha)
{
	int tamanho = strlen(byte);
	binario* novo_n = (binario*)malloc(sizeof(binario));
	
	char* novo = (char*)malloc((tamanho+1)*sizeof(char));
	strcpy(novo, byte);
	novo_n->byte = novo;
	ht->bytes[folha] = novo_n;
}

void escrever_configuracoes(configuracoes* ht)
{
	int i;
	printf("configuracoes:\n");
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
