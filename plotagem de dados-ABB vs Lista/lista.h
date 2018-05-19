/*
*Modulo para lista
*/

//Tipo exportado 'no'
typedef struct no no;

//Cria uma lista vazia
no* criar_lista_vazia();

//Adiciona um novo no na cabeca da lista com informação 'info'
//Retorna a cabeca da lista
no* adicionar_na_cabeca(no* lista, int info);

//Busca um elemento na lista e retorna o número de comparações até achar tal elemento
long long int busca(no* lista, int info);

//Retorna o tamanho de uma lista
long long int tamanho_lista(no* lista);

//Retorna o elemento seguinte ao especificado por 'lista'
no* proximo(no* lista);

//Retorna 1 se 'lista' está vazia e 0 caso contrário
int lista_vazia(no* lista);

//Retorna o valor do item que está na cabeca da lista
long long int item_da_cabeca(no* lista);