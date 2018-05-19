/*
*modulo de funcoes para fila
*/

FILA* criar_fila();

int fila_vazia(FILA *fila);

NO* dequeue(FILA *fila);

void enqueue(FILA *fila, NO *n);

NO* criar_no(int freq, unsigned char c);
