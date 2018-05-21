/*
*Modulo de funcoes para estrutura dicionario
*/

/*
*Cria um dicionario vazio
*retorna um dicionario* vazio
*/
dicionario* criar_dicionario();

/*
*coloca um byte no dicionario
*dicionario* ht eh o dicionario
*char* byte eh o byte a ser colocado no dicionario
*unsigned char folha eh o indice no dicionario que o byte vai ser colocado
*/
void inserir(dicionario* ht, char* byte, unsigned char folha);

