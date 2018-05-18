/*
*Modulo de descompressao
*/

int is_bit_i_set(unsigned char c, int i);

NO* criar_no_arv(unsigned char c);

NO* criar_arv(NO* bt, unsigned short *i, unsigned short tam, FILE *compr);

void descompressao(unsigned short tam_lixo, unsigned short tam_arvore, NO* arvore, FILE* arq_comp);

void descomprimir(FILE* compr);