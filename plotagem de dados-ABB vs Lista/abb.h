/*
*Modulo exportado para arvore de busca binaria
*/

typedef struct arvore_binaria arvore_binaria;

//Cria uma arvore binaria vazia
arvore_binaria	*criar_vazia();

//Adiciona filhos a esquerda e direta em um pai
arvore_binaria	*criar_arvore(int valor, arvore_binaria* esquerda, arvore_binaria* direita);

//Verifica se uma arvore binaria está vazia
int esta_vazia(arvore_binaria* bt);

//Adiciona um elemento a uma arvore binaria
arvore_binaria* adiciona_elemento(arvore_binaria* bt, int valor);

//Realiza busca binaria em uma arvore de busca binaria
//Retorna a quantidade de comparações até achar o elemento
long long int busca_binaria(arvore_binaria* bt, int valor);
