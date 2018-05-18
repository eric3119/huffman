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
	
	NO *aux = fila->cabeca;

	fila->cabeca = fila->cabeca->proximo;
	
	aux->proximo = NULL;
	
	return aux;
}

void enqueue(FILA *fila, NO *n){

	NO *atual = fila->cabeca,
	     *ant = NULL;
	while((atual!= NULL)&&(atual->freq < n->freq))	{
		ant = atual;
		atual = atual->proximo;
	}
	if(ant== NULL){
		n->proximo = fila->cabeca;
		fila->cabeca = n;
	}else{
		ant->proximo = n;
		n->proximo = atual;
	}
}

void imprimir_fila(FILA *fila){
	NO *aux = fila->cabeca;

	while(aux){
		if(aux->byte != '\n') printf("%c, %d\n", aux->byte, aux->freq);		
		else printf("\\n, %d\n", aux->freq);
		aux = aux->proximo;
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
