/*
*Modulo de funcoes para compressao
*/

unsigned char set_bit(unsigned char c, int i);

void pre_compressao(FILE* arquivo);

void buscar(NO* arvore, char* byte, configuracoes* ht, int i);

unsigned short calc_lixo(configuracoes* ht, int tb_freq[]);

void converter_decimal_bin(int numero, int* indice, char *string);

void cabecalho(unsigned short lixo, unsigned short tam_arvore, NO* arvore, FILE* tmp);

void comprimir(configuracoes *ht, FILE* antigo, unsigned short lixo, unsigned short tam_arvore, NO* arvore);
