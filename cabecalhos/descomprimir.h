/*
*Modulo de descompressao
*/

/*
*Verifica se um bit i de um byte c esta setado
*unsigned char c eh o byte
*int i eh o indice do bit
*/
int is_bit_i_set(unsigned char c, int i);

/*
*Cria um no em uma arvore que tem c como informacao
*unsigned char c represnetando a informacao a ser gravada no no
*retorna o no criado
*/
NO* criar_no_arv(unsigned char c);

/*
*Cria e retorna a arvore de huffman gravada no arquivo comprimido
*NO* bt eh a raiz da arvore
*unsigned short* i deve ter valor inicial igual a 0
*unsigned short tam eh o tamanho da arvore gravada no arquivo
*FILE* compr eh o arquivo comprimido
*retorna a arvore de huffman
*/
NO* criar_arv(NO* bt, unsigned short *i, unsigned short tam, FILE *compr);

/*
*Realiza o processo de pre_descompressao
*FILE* compr eh o arquivo a ser descomprimido
*Cria a arvore de huffman
*determina o tamanho do lixo
*determina o tamanho da arvore de huffman
*/
void pre_descompressao(FILE* compr);
/*
*Realiza o processo de descompressao
*unsigned short tam_lixo eh o tamanho do lixo
*unsigned short tam_arvore eh o tamanho da arvore
*NO* arvore eh a raiz da arvore de huffman
*FILE* arq_comp eh o arquivo comprimido
*gera um arquivo de saida denominado 'descomprimido' 
*/
void descompressao(unsigned short tam_lixo, unsigned short tam_arvore, NO* arvore, FILE* arq_comp);
