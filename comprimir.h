unsigned char set_bit(unsigned char c, int i){

	unsigned char mask = 1 << i;
	return mask | c;
}
void search(NODE* fila, char* byte, hash_table* ht, int i){

	if(!fila) return;

	if(fila->left == NULL && fila->right == NULL)
	{
		byte[i] = '\0';
		put(ht, byte, fila->byte);
	}
	else
	{
		byte[i] = '0';
		search(fila->left, byte, ht, i+1);
		byte[i] = '1';
		search(fila->right, byte, ht, i+1);
		
	}

}

int calc_lixo(hash_table* ht, int tb_freq[])
{
	int i, temp, lixo;

	for(i = 0, temp = 0; i < 256; i++)
	{
		if(tb_freq[i])
		{
			temp+= (strlen(ht->bytes[i]->byte) * tb_freq[i]);
		}
	}
	lixo = (8 - temp%8)%8;
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
void cabecalho(int lixo, int tam_arvore, NODE* arvore, FILE* tmp)
{
	unsigned char byte1, byte2;
	byte1 = 0;
	byte2 = 0;
	char lixo_s[3], tam_s[14];//tam_s é string pro tamanho da árvore e lixo_s eh pro tamanho do lixo
	/*Cria as string pros 16 bits iniciais*/
	int i = 0, j;

	converter_decimal_bin(lixo, &i, lixo_s);
	i = 0;
	converter_decimal_bin(tam_arvore, &i, tam_s);
	tam_s[i] = '\0';


	if(strlen(tam_s) < 13)
	{
		/*Coloca 0's a esquerda em tam_s*/
		char tam_s2[14];
		int quant = 13 -  strlen(tam_s);
		for(i = 0; i < quant; i++)
		{
			tam_s2[i] = '0';
		}
		for(j = 0; i < 13; i++, j++)
		{
			tam_s2[i] = tam_s[j];
		}
		strcpy(tam_s, tam_s2);
	}

	/*Setando os bits*/
	//setando o tamanho do lixo
	for(i = 7, j = 0; i >= 5;)
	{
		if(lixo_s[j] == '1')
		{
			byte1 = set_bit(byte1, i);
		}
		i--;
		j++;

	}
	
	//primeira parte do tamanho da árvore
	for( i = 4, j = 0; i >= 0;)
	{
		if(tam_s[j] == '1')
		{
			byte1 = set_bit(byte1, i);
		}
		i--;
		j++;
	}//Primeiro bit setado
	
	//Segunda parte
	i = 7;
	while(i >= 0)
	{
		if(tam_s[j] == '1')
		{
			byte2 = set_bit(byte2, i);
		}
		i--;
		j++;
	}

	fwrite(&byte1, sizeof(byte1), 1, tmp);
	fwrite(&byte2, sizeof(byte2), 1, tmp);
	print_arvore(arvore, tmp);//Gravando a arvore no arquivo
}
void comprimir(hash_table *ht, const char *arquivo, int lixo, int tam_arvore, NODE* arvore){
	/*Dessa funcao ele já faz o cabecalho*/
	FILE *tmp = fopen("tmp", "wb");	
	FILE* antigo = fopen(arquivo, "rb");
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
		
	while(!feof(antigo)){

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
			tamanho = strlen(ht->bytes[c]->byte);
			printf("ultimo %u ", d);
			fwrite(&d, sizeof(d), 1, tmp);
			puts("");
			break;
		}
	}
	fclose(tmp);
	fclose(antigo);
}

