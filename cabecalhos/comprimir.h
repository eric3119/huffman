/*
*Modulo de funcoes para compressao
*/

/*
*Verifica se um bit de um byte está 'setado' ou nao
*c e o byte
*i e o indice do bit 
*/
unsigned char set_bit(unsigned char c, int i);

/*
*Prepara todo o processo de pre-compressao do arquivo
*Recebe o arquivo 
*Calcula a frequencia dos bytes no arquivo
*Cria a arvore de huffman
*/
void pre_compressao(FILE* arquivo);

/*
*Guarda em um dicionario as cofigurações dos bytes feitas na arvore de huffman
*arvore e a arvore de huffman criada na funcao pre_compressao
*byte e uma cadeia de caracteres vazia que vai sendo formada de acordo com a configuracao de cada byte na arvore de huffman
*ht e o dicionario que se deseja guardar as configuracoes
*/
void buscar(NO* arvore, char* byte, dicionario* ht, int i);

/*
*Calcula o tamanho do lixo que vai restar apos a comressao do arquivo
*retorna um unsigned short representando o tamanho do lixo calculado
*recebe o dicionario ht de configuracoes(criado na funcao buscar) dos bytes do arquivo
*Recebe a frequencia dos bytes tb_freq[] no arquivo a ser comprimido
*/
unsigned short calc_lixo(dicionario* ht, int tb_freq[]);

/*
*Grava o cabecalho no arquivo comprimido
*recebe um unsigned short lixo representando o tamanho do lixo
*recebe um unsigned short tam_arvore representando o tamanho da arvore de huffman
*recebe um NO* arvore representando a arvore de huffman
*e o arquivo no qual o cabecalho vai ser gravado, o arquivo comprimido
*/
void cabecalho(unsigned short lixo, unsigned short tam_arvore, NO* arvore, FILE* tmp);

/*
*Realiza o processo de compressao
*recebe dicionario *ht representando o dicionario que contem as configuracoes dos bytes 
*recebe FILE* antigo representando oa rquivo que se deseja comprimir
*recebe unsigned short lixo representando o tamanho do lixo
*recebe unsigned short tam_arvore representando o tamanho da arvore de huffman
*recebe NO* arvore represnetando a arvore de huffman
*/
void comprimir(dicionario *ht, FILE* antigo, unsigned short lixo, unsigned short tam_arvore, NO* arvore);
