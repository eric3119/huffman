#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
	unsigned char byte;
	int freq;
	struct NODE *next, *prev;
	struct NODE *left, *right;
}NODE;

typedef struct FILA{
	NODE *head, *tail;
}FILA;

#include "func_lista.h"
#include "func_fila.h"
#include "func_arvore.h"

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

int main(int argc, char const *argv[]){

	if(argc == 1){
		puts("erro");
		return 0;
	}

	FILE *arquivo = fopen(argv[1], "rb");
	
	if(!arquivo){
		puts("erro");
		return -1;
	}else 
		printf("Comprimindo -> %s\n",argv[1]);
	
	unsigned char c;	
	FILA *fila = create_fila();
	
	fread(&c, sizeof(c), 1, arquivo);

	while(!feof(arquivo)){		
		enqueue(fila, c);
		fread(&c, sizeof(c), 1, arquivo);	
	}
	
	fclose(arquivo);

	while(!empty_queue(fila)){
		NODE *n1 = dequeue(fila),
			 *n2 = dequeue(fila);
		if(empty_queue(fila)){
			enqueue_arvore(f, n1, n2);
			break;
		}
	}

	printf("%d\n", size_fila(fila));

	return 0;
}
