unsigned char set_bit(unsigned char c, int i){

	unsigned char mask = 1 << i;
	return mask | c;
}
void search(NODE* fila, char* byte, hash_table* ht, int i)
{
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
/*int calc_tam_arvore(NODE* arvore)
{

}*/

void comprimir(hash_table *ht, const char *arquivo){

	FILE *tmp = fopen("tmp", "wb");	
	FILE* antigo = fopen(arquivo, "rb");
	unsigned char c, d = 0;
	int i=7, j=0, tamanho;

	if(!tmp || !antigo){
		puts("erro arquivo");
		return ;
	}
	fread(&c, sizeof(c), 1, antigo);
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

/*void cabecalho(int lixo, int tam_arvore, NODE* arvore)
{

}*/