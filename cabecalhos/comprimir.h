/*
*Modulo de funcoes para compressao
*/

unsigned char set_bit(unsigned char c, int i);

void pre_compressao(FILE* arquivo);

void buscar(NO* arvore, char* byte, dicionario* ht, int i);

unsigned short calc_lixo(dicionario* ht, int tb_freq[]);

void cabecalho(unsigned short lixo, unsigned short tam_arvore, NO* arvore, FILE* tmp);

void comprimir(dicionario *ht, FILE* antigo, unsigned short lixo, unsigned short tam_arvore, NO* arvore);
