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

NO* criar_arvore(NO *n1, NO *n2){
	NO *novo = (NO*) malloc(sizeof(NO));
	
	novo->byte = '*';

	if(n1 && n2)
		novo->freq = n1->freq + n2->freq;
	else if(n1)
		novo->freq = n1->freq;
	else
		novo->freq = 0;

	novo->esquerda = n1;
	novo->direita = n2;
	novo->proximo = NULL;

	return novo;
}

void mostrar_arvore(NO *raiz){//printa na saída padrão
	if(raiz != NULL){
		if(raiz->caracter_controle == 1)
			printf("\\%c", raiz->byte);
		else
			printf("%c", raiz->byte);
		mostrar_arvore(raiz->esquerda);
		mostrar_arvore(raiz->direita);
	}
}

void escrever_arvore(NO *raiz, FILE* tmp){//printa no arquivo
	if(raiz != NULL)
	{
		unsigned char c = raiz->byte;
		if(raiz->caracter_controle == 1)
		{
			unsigned char d = 92;//'\'
			fwrite(&d, sizeof(d), 1, tmp);
			fwrite(&c, sizeof(c), 1, tmp);
		}else
		{
			fwrite(&c, sizeof(c), 1, tmp);
		}
		escrever_arvore(raiz->esquerda, tmp);
		escrever_arvore(raiz->direita, tmp);
	}
}

int esta_vazia(NO *bt){
	return (bt)? 0:1;
}

int altura(NO* bt){
	
	if(esta_vazia(bt->esquerda) || esta_vazia(bt->direita))
	{
		return 0;
	}
	int altura_esquerda, altura_direita;
	altura_esquerda = altura(bt->esquerda);
	altura_direita= altura(bt->direita);

	if(altura_esquerda > altura_direita)
	{
		return 1 + altura_esquerda;
	}
	else
	{
		return 1 + altura_direita;
	}
}

unsigned short calc_tam_arvore(NO* arvore){

	if(!arvore) return 0;
	//O tamanho da arvore eh 1 + o tamanho da arvore da esuqerda + o tamanho da subarvore da direita
	if((arvore->esquerda == NULL)  && (arvore->direita == NULL))
	{
		//o tamanho d euma folha eh 2, se a folha for '*' ou '\' , ou 1. 
		if(arvore->caracter_controle == 1)
		{
			return (unsigned short)2;
		}
		else
		{
			return (unsigned short)1;
		}
	}
	unsigned short tamanho;
	tamanho = (unsigned short) 1 + calc_tam_arvore(arvore->esquerda);
	return (unsigned short)tamanho + calc_tam_arvore(arvore->direita);
}
