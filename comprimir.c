#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "estruturas.h"
#include "func_fila.h"
#include "func_arvore.h"
#include "hash.h"
#include "comprimir.h"
#include "descomprimir.h"

unsigned char set_bit(unsigned char c, int i){

	unsigned char mask = 1 << i;
	return mask | c;
}

void pre_compressao(FILE* arquivo)
{
	int i, tb_freq[256];
		
	unsigned char c;
	unsigned short lixo, tam_arvore;

	memset(tb_freq, 0, sizeof(tb_freq));

	FILA *fila = criar_fila();	
	
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
		NO *n1 = dequeue(fila),
			 *n2 = dequeue(fila);
		NO *novo = criar_arvore(n1, n2);
		
		if(fila_vazia(fila)){
		
			enqueue(fila, novo);
			break;
		}
		enqueue(fila, novo);		
	}
		
	configuracoes* ht = criar_configuracoes();

	/*tam índica a quantidade maxima que uma string de configuracao pode assumir*/
	int tam = altura(fila->cabeca);
	char* byte = (char*)malloc((tam+1)*sizeof(char));
		
	buscar(fila->cabeca,byte,ht, 0);
	lixo = calc_lixo(ht, tb_freq);
	tam_arvore = calc_tam_arvore(fila->cabeca);

	comprimir(ht, arquivo, lixo, tam_arvore, fila->cabeca);
}

void buscar(NO* arvore, char* byte, configuracoes* ht, int i){
	if(!arvore) return;

	if(arvore->esquerda == NULL && arvore->direita == NULL)
	{
		byte[i] = '\0';
		put(ht, byte, arvore->byte);
	}
	else
	{
		byte[i] = '0';
		buscar(arvore->esquerda, byte, ht, i+1);
		byte[i] = '1';
		buscar(arvore->direita, byte, ht, i+1);
		
	}
}

unsigned short calc_lixo(configuracoes* ht, int tb_freq[])
{
	int i;
	unsigned short temp, lixo;

	for(i = 0, temp = 0; i < 256; i++)
	{
		if(tb_freq[i])
		{
			temp+= ((unsigned short)(strlen(ht->bytes[i]->byte) * tb_freq[i]));
		}
	}
	lixo =(unsigned short) (8 - temp%8)%8;
	return lixo;
}

void converter_decimal_bin(int numero, int* indice, char *string)
{
	if(numero < 2)
	{
		string[*indice] = numero + '0';
		*indice+= 1;
	}
	else
	{
		int resto = numero%2;
		numero/=2;
		converter_decimal_bin(numero, indice, string);
		string[*indice] = resto + '0';
		*indice+=1;
	}
}
void cabecalho(unsigned short lixo, unsigned short tam_arvore, NO* arvore, FILE* tmp)
{
	unsigned char byte1;
	unsigned char byte2;
	byte1 = lixo<<5;
	byte1 = byte1|(((tam_arvore)<<3)>>8);
	byte2 = (tam_arvore<<8)>>8;

	fwrite(&byte1, sizeof(byte1), 1, tmp);
	fwrite(&byte2, sizeof(byte2), 1, tmp);
	escrever_arvore(arvore, tmp);//Gravando a arvore no arquivo
}
void comprimir(configuracoes *ht, FILE* antigo, unsigned short lixo, unsigned short tam_arvore, NO* arvore){
	/*Dessa funcao ele já faz o cabecalho*/
	FILE *tmp = fopen("tmp", "wb");	
	rewind(antigo);
	/*
	*Cabecalho
	*/
	cabecalho(lixo, tam_arvore, arvore, tmp);
	/*Compressao*/
	unsigned char c, d = 0;
	int i=7, j=0, tamanho;
	
	if(!tmp || !antigo){
		puts("erro arquivo");
		return ;
	}
	fread(&c, sizeof(c), 1, antigo);
	if(!feof(antigo))
		tamanho = strlen(ht->bytes[c]->byte);
		
	while(1){
		for(; j<tamanho && i>=0; j++){
			if(ht->bytes[c]->byte[j]=='1'){
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
			tamanho = strlen(ht->bytes[c]->byte);
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

