/*
*Modulo de funcoes para arvore
*/

NO* criar_arvore(NO *n1, NO *n2);

void mostrar_arvore(NO *raiz);

void escrever_arvore(NO *raiz, FILE* tmp);

int esta_vazia(NO *bt);

int altura(NO* bt);

unsigned short calc_tam_arvore(NO* arvore);
