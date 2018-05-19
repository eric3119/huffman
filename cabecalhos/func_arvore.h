/*
*Modulo de funcoes para arvore
*/

/*
*Cria uma arvore com uma subarvore a esquerda e uma a direita
*NO *n1 eh a subarvore da esquerda
*NO *n2 eh a subarvore da direita
*retorna a arvore criada
*/
NO* criar_arvore(NO *n1, NO *n2);

/*
*Escreve a arvore de huffman no arquivo comprimido
*NO *raiz eh a raiz da arvore de huffman
*FILE* tmp eh o arquivo comprimido
*/
void escrever_arvore(NO *raiz, FILE* tmp);

/*
*Verifica se uma arvore esta vazia
*NO *bt eh a arvore
*retorna 1 se a arvore esta vazia ou 0 caso contrario
*/
int esta_vazia(NO *bt);

/*
*Calcula a altura de uma arvore
*NO* bt eh a arvore
*retorna um inteiro representando a altura da arvore
*/
int altura(NO* bt);

/*
*Calcula o tamanho de uma arvore
*NO* arvore eh a arvore 
*retorna um unsigned short representando o tamanho da arvore
*/
unsigned short calc_tam_arvore(NO* arvore);
