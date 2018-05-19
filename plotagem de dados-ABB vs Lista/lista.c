#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct no{
  int info;
  struct no* proximo;
};

no* criar_lista_vazia()
{
  return NULL;
}

no* adicionar_na_cabeca(no* lista, int info)
{
  no* novo_no = (no*)malloc(sizeof(no));
  novo_no->info = info;
  novo_no->proximo = lista;
  return novo_no;
}

long long int busca(no* lista, int info)
{
  long long int contador = 0;

  while(lista!= NULL)
  {
    contador+=1;
    if(lista->info == info)
    {
      return contador;
    }
    lista = lista->proximo;

  }
}

long long int tamanho_lista(no* lista)
{
  if(lista!= NULL)
  {
    return 1 + tamanho_lista(lista->proximo);
  }
  return 0;
}
no* proximo(no* lista)
{
  return lista->proximo;
}
int lista_vazia(no* lista)
{
  return (lista == NULL);
}

long long int item_da_cabeca(no* lista)
{
  return lista->info;
}