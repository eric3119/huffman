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

FILA* criar_fila(){
	FILA *novo = (FILA*) malloc(sizeof(FILA));

	novo->cabeca = NULL;

	return novo;
}

int fila_vazia(FILA *fila){
	return (fila->cabeca)? 0:1;
}

NO* dequeue(FILA *fila){

	if(fila_vazia(fila)) return NULL;
	
	NO *aux 	 =(NO*) fila->cabeca;

	fila->cabeca =(void*) ((NO*)fila->cabeca)->proximo;
	
	aux->proximo = NULL;
	
	return aux;
}

void enqueue(FILA *fila, NO *n){

	NO *atual = (NO*)fila->cabeca,
	     *ant = NULL;

	while((atual!= NULL)&&(atual->freq < n->freq))	{
		ant   = atual;
		atual = atual->proximo;
	}

	if(ant== NULL){
		n->proximo   = (NO*)fila->cabeca;
		fila->cabeca = (NO*)n;
	}else{
		ant->proximo = n;
		n->proximo   = atual;
	}
}

NO* criar_no(int freq, unsigned char c){
	NO *novo = (NO*) malloc(sizeof(NO));

	novo->byte = c;

	novo->freq = freq;

	novo->esquerda = novo->direita = novo->proximo = NULL;

	if((c == 42) || (c == 92))
	{
		novo->caracter_controle = 1;
	}

	else
	{
		novo->caracter_controle = 0;
	}
	return novo;
}
