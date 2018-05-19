/*
*modulo de funcoes para fila
*/

/*
*Cria uma fila vazia
*retorna FILA* representando a fila criada
*/
FILA* criar_fila();

/*
*Verifica se uma fila esta vazia
*FILA *fila eh a fila
*retorna 1 se a fila esta vazia e 0 caso contrario
*/
int fila_vazia(FILA *fila);

/*
*Realiza um dequeue em uma fila
*FILA *fila eh a fila
*retorna NO* que eh o item desenfileirado
*/
NO* dequeue(FILA *fila);

/*
*Realiza um enqueue em uma fila
*FILA *fila eh a fila
*NO *n eh o no que vai ser enfileirado
*/
void enqueue(FILA *fila, NO *n);

/*
*Cria um no representando um byte c  que tem uma frequencia freq no arquivo que vai ser comprimido
*unsigned char c eh o byte
*int freq eh a frequencia desse byte no arquivo
*retorna NO* o no criado
*/
NO* criar_no(int freq, unsigned char c);
