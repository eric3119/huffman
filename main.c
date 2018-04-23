#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char* byte;
}binary; 

typedef struct hash_table{
	binary* bytes[256];
}hash_table;

typedef struct NODE{
	unsigned char byte;
	int freq;
	struct NODE *next;
	struct NODE *left, *right;
}NODE;

typedef struct FILA{
	NODE *head;
}FILA;

#include "func_fila.h"
#include "func_arvore.h"
#include "hash.h"
#include "comprimir.h"

void print(NODE *p){
	if(!p) return;

	printf("%c %d\n", p->byte, p->freq);
	print(p->next);
}

void print_pre(NODE *n){
	if(n!= NULL){
		printf("%c ", n->byte);
		print_pre(n->left);
		print_pre(n->right);
	}
}

int calc_lixo(hash_table* ht, int tb_freq[])
{
	int i, temp, lixo;

	for(i = 0, temp = 0; i < 256; i++)
	{
		if(tb_freq[i])
		{
			temp+= (strlen(ht->bytes[i]->byte) * tb_freq[i]);
		}
	}
	lixo = (8 - temp%8)%8;
	return lixo;
}


int main(int argc, char const *argv[]){

	if(argc == 1){
		puts("erro nome arquivo");
		return 0;
	}

	FILE *arquivo = fopen(argv[1], "rb");
	
	if(!arquivo){
		puts("erro abrir arquivo");
		return -1;
	}
	int i, tb_freq[256], lixo;
	unsigned char c;
	memset(tb_freq, 0, sizeof(tb_freq));

	FILA *fila = create_fila();	
	
	fread(&c, sizeof(c), 1, arquivo);

	while(!feof(arquivo)){		
		tb_freq[c]++;
		fread(&c, sizeof(c), 1, arquivo);	
	}

	for(i=0; i<256; i++){
		if(tb_freq[i]){
			NODE *novo = create_node(tb_freq[i],i);
			enqueue(fila, novo);
		}
	}
	
	fclose(arquivo);
	puts("fila:");
	print_fila(fila);
	while(1){
		NODE *n1 = dequeue(fila),
			 *n2 = dequeue(fila);

		NODE *novo = criar_arvore(n1, n2);
		
		if(empty_queue(fila)){
		
			enqueue(fila, novo);
			break;
		}
		enqueue(fila, novo);		
	}
	puts("arvore:");
	print_arvore(fila->head);puts("");
	
	hash_table* ht = criar_hash();

	int tam = height(fila->head);
	char* byte = (char*)malloc((tam+1)*sizeof(char));
	
	search(fila->head,byte,ht, 0);
	lixo = calc_lixo(ht, tb_freq);
	print_hash(ht);
	printf("lixo = %d", lixo);
	comprimir(ht, argv[1]);
	
	return 0;
}
