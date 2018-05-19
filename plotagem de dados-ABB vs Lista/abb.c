#include <stdio.h>
#include <stdlib.h>
#include "abb.h"


struct arvore_binaria{
	int valor;
	arvore_binaria* esquerda;
	arvore_binaria* direita;
};

arvore_binaria	*criar_vazia()
{
	return NULL;
}

arvore_binaria	*criar_arvore(int valor, arvore_binaria* esquerda, arvore_binaria* direita)
{
	arvore_binaria* novo = (arvore_binaria*)malloc(sizeof(arvore_binaria));

	novo->valor = valor;
	novo->esquerda = esquerda;
	novo->direita = direita;
	return novo;
}

int esta_vazia(arvore_binaria* bt)
{
	return (bt == NULL);
}

arvore_binaria* adiciona_elemento(arvore_binaria* bt, int valor)
{
	if(esta_vazia(bt))
	{
		bt = criar_arvore(valor, NULL, NULL);
	}
	else if(valor > bt->valor)
	{
		bt->direita = adiciona_elemento(bt->direita, valor);
	}
	else
	{
		bt->esquerda = adiciona_elemento(bt->esquerda, valor);
	}
	return bt;
}

long long int busca_binaria(arvore_binaria* bt, int valor)
{
	if((bt->valor == valor))
	{
		return 0;
	}
	else if(valor > bt->valor)
	{
		return 1 + busca_binaria(bt->direita, valor);
	}
	else
	{
		return 1 + busca_binaria(bt->esquerda, valor);
	}
}

