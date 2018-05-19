#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "abb.h"
#include "lista.h"

typedef struct hash_table{
	short* comparado;
	long long int tamanho;
	long long int* table;
} hash_table;

hash_table* criar_hash_table(long long int tamanho);

int put(hash_table* ht,long long int item);

long long int get(hash_table* ht, int item);

int main()
{
	no* lista = criar_lista_vazia();
	arvore_binaria* bt = criar_vazia();
	hash_table* ht = criar_hash_table(100100);

	FILE* arq = fopen("banco.csv", "w");

	fprintf(arq, "numero;lista;abb\n");
	long long int comparacoes1,comparacoes2, i;
	long long int item;
	srand((unsigned)time(NULL));

	for(i = 1; i <= 100100; i++)
	{
		long long int a = rand()%i;
		if(put(ht, a)){
			lista = adicionar_na_cabeca(lista, a);
			bt = adiciona_elemento(bt, a);
		}
	}

	for(i = 1; i <= 100100; i++)
	{
		long long int a = rand()%i;
		item = get(ht, a);
		if(item != -1)
		{
			comparacoes1 = busca(lista, item);
			comparacoes2 = busca_binaria(bt, item);
			fprintf(arq, "%lld;%lld;%lld\n",item,comparacoes1, comparacoes2);
		}
	}
	fclose(arq);


	return 0;
}

hash_table* criar_hash_table(long long int tamanho)
{
	hash_table* ht = (hash_table*)malloc(sizeof(hash_table));
	ht->tamanho    = tamanho;
	ht->comparado  = (short*)malloc(tamanho*sizeof(short));
	ht->table 	   = (long long int*)malloc(tamanho*sizeof(long long int*));
	int i;

	for(i = 0; i < tamanho; ++i)
	{
		ht->table[i] = -1;
		ht->comparado[i] = 0;
	}
	return ht;
}

int put(hash_table* ht,long long int item)
{
	long long int h = item%(ht->tamanho);
	if(ht->table[h] == -1){
		ht->table[h] = item;
		return 1;
	}
	else
	{
		return 0;
	}
}

long long int get(hash_table* ht, int item)
{
	long long int h = item % ht->tamanho;
	if(ht->comparado[h]) return -1;
	else
	{
		ht->comparado[h] = 1;
		return ht->table[h];
	}
}