/*
*Modulo de funcoes para compressao
*/

/*
*'seta' um bit i de um byte c
*unsigned char c e o byte
*int i e o indice do bit 
*/
unsigned char set_bit(unsigned char c, int i);

/*
*Prepara todo o processo de pre-compressao do arquivo
*FILE* arquivo eh o  arquivo 
*Calcula a frequencia dos bytes no arquivo
*Cria a arvore de huffman
*/
void pre_compressao(FILE* arquivo);

/*
*Guarda em um dicionario as cofigurações dos bytes feitas na arvore de huffman
*NO* arvore eh a arvore de huffman criada na funcao pre_compressao
*char* byte e uma cadeia de caracteres vazia que vai sendo formada de acordo com a configuracao de cada byte na arvore de huffman
*dicionario* ht e o dicionario que se deseja guardar as configuracoes
*int i deve ser inicializado com 0
*/
void buscar(NO* arvore, char* byte, dicionario* ht, int i);

/*
*Calcula o tamanho do lixo que vai restar apos a comressao do arquivo
*retorna um unsigned short representando o tamanho do lixo calculado
*dicionario* ht eh o dicionario de configuracoes(criado na funcao buscar) dos bytes do arquivo
*int tb_freq[] eh a frequencia dos bytes no arquivo a ser comprimido
*/
unsigned short calc_lixo(dicionario* ht, int tb_freq[]);

/*
*Grava o cabecalho no arquivo comprimido
*unsigned short lixo eh o tamanho do lixo
*unsigned short tam_arvore eh o tamanho da arvore de huffman
*NO* arvore eh a arvore de huffman
*FILE* tmp eh o arquivo comprimido no qual o cabecalho vai ser gravado
*/
void cabecalho(unsigned short lixo, unsigned short tam_arvore, NO* arvore, FILE* tmp);

/*
*Realiza o processo de compressao
*dicionario *ht eh o dicionario que contem as configuracoes dos bytes 
*FILE* antigo eh o arquivo que se deseja comprimir
*unsigned short lixo eh o tamanho do lixo
*unsigned short tam_arvore eh o tamanho da arvore de huffman
*NO* arvore eh a arvore de huffman
*gera um arquivo de saida 'tmp' 
*/
void comprimir(dicionario *ht, FILE* antigo, unsigned short lixo, unsigned short tam_arvore, NO* arvore);
