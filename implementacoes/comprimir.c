#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "../cabecalhos/estruturas.h"
#include "../cabecalhos/func_fila.h"
#include "../cabecalhos/func_arvore.h"
#include "../cabecalhos/dicionario.h"
#include "../cabecalhos/comprimir.h"
#include "../cabecalhos/descomprimir.h"

unsigned char set_bit(unsigned char c, int i){

	unsigned char mask = 1 << i;
	return mask | c;
}

void pre_compressao(FILE* arquivo)
{
	int i, tb_freq[256], tam;
		
	unsigned char c;
	unsigned short lixo, tam_arvore;

	char* byte;

	FILA *fila = criar_fila();

	dicionario* ht;

	memset(tb_freq, 0, sizeof(tb_freq));

	
	fread(&c, sizeof(c), 1, arquivo);

	while(!feof(arquivo)){		
		tb_freq[c]++;
		fread(&c, sizeof(c), 1, arquivo);	
	}

	for(i=0; i<256; i++){
		if(tb_freq[i]){
			NO *novo = criar_no(tb_freq[i],i);
			enqueue(fila, novo);
		}
	}

	while(1){
		NO *n1   = dequeue(fila),
		   *n2   = dequeue(fila);
		NO *novo = criar_arvore(n1, n2);
		
		if(fila_vazia(fila)){
		
			enqueue(fila, novo);
			break;
		}
		enqueue(fila, novo);		
	}
		
	ht = criar_dicionario();

	/*tam índica a quantidade maxima que uma string de configuracao pode assumir*/
	tam  = altura((NO*)fila->cabeca);

	byte = (char*)malloc((tam+1)*sizeof(char));
		
	codificar((NO*)fila->cabeca,byte,ht, 0);

	lixo       = calc_lixo(ht, tb_freq);

	tam_arvore = calc_tam_arvore((NO*)fila->cabeca);

	comprimir(ht, arquivo, lixo, tam_arvore, (NO*)fila->cabeca);
}

void codificar(NO* arvore, char* byte, dicionario* ht, int i){
	if(!arvore) return;

	if(arvore->esquerda == NULL && arvore->direita == NULL)
	{
		byte[i] = '\0';
		inserir(ht, byte, arvore->byte);
	}
	else
	{
		byte[i] = '0';
		codificar(arvore->esquerda, byte, ht, i+1);

		byte[i] = '1';
		codificar(arvore->direita, byte, ht, i+1);
		
	}
}

unsigned short calc_lixo(dicionario* ht, int tb_freq[])
{
	int i;
	unsigned short temp, lixo;

	for(i = 0, temp = 0; i < 256; i++)
	{
		if(tb_freq[i])
		{
			temp += ((unsigned short)(strlen(((binario*)(ht->bytes[i]))->byte) * tb_freq[i]));
		}
	}
	lixo = (unsigned short) (8 - temp%8)%8;
	return lixo;
}

void cabecalho(unsigned short lixo, unsigned short tam_arvore, NO* arvore, FILE* tmp)
{
	unsigned char byte1;
	unsigned char byte2;

	byte1 = lixo<<5;
	byte1 = byte1|((tam_arvore)>>8);
	byte2 = tam_arvore;

	fwrite(&byte1, sizeof(byte1), 1, tmp);
	fwrite(&byte2, sizeof(byte2), 1, tmp);

	escrever_arvore(arvore, tmp);//Gravando a arvore no arquivo
}
void comprimir(dicionario *ht, FILE* antigo, unsigned short lixo, unsigned short tam_arvore, NO* arvore){
	/*Dessa funcao ele já faz o cabecalho*/
	FILE *tmp = fopen("tmp", "wb");	

	unsigned char c, d = 0;

	int i=7, j=0, tamanho;

	rewind(antigo);
	/*Cabecalho*/
	cabecalho(lixo, tam_arvore, arvore, tmp);

	/*Compressao*/
	
	if(!tmp || !antigo){
		printf("erro arquivo");
		return ;
	}

	fread(&c, sizeof(c), 1, antigo);

	if(!feof(antigo))
		tamanho = strlen(((binario*)(ht->bytes[c]))->byte);
		
	while(1){
		for(; j<tamanho && i>=0; j++){
			if(((binario*)(ht->bytes[c]))->byte[j] == '1'){
				d = set_bit(d, i);				
			}
			i--;
		}

		if(i<0){
			i=7;
			fwrite(&d, sizeof(d), 1, tmp);
			d = 0;
		}

		if(j >= tamanho){
			fread(&c, sizeof(c), 1, antigo);
			tamanho = strlen(((binario*)(ht->bytes[c]))->byte);
			j = 0;

		}

		if(feof(antigo)){
			fwrite(&d, sizeof(d), 1, tmp);
			break;
		}
	}
	
	fclose(tmp);
	fclose(antigo);
}

