int is_bit_i_set(unsigned char c, int i){
	unsigned char mask = 1 << i;
	return mask & c;
}

int bin_to_int(int bin[], int tam){
	int i = tam-1, saida = 0, j = 0;
	while(i >= 0){
		if(bin[i]== 1)
		{
			double potencia = pow(2.0, (double)j);
			saida += ((bin[i])*potencia);
		}
		i--;
		j++;
	}
	
	return saida;
}

int conv_tam_lixo(unsigned char c){
	int bin[3], i=7, j=2;

	while(i>4){		
		
		if(is_bit_i_set(c, i))
			bin[j] = 1;	
		else
			bin[j] = 0;	
		
		i--;
		j--;
	}

	return bin_to_int(bin, 3);
}

//Nao funciona desse jeito :/
int conv_tam_arv(unsigned char c, int tam){
	int bin[tam], i = tam-1, j=tam-1;

	while(i>=0){		
		
		if(is_bit_i_set(c, i))
			bin[j] = 1;	
		else
			bin[j] = 0;	
		
		i--;
		j--;
	}

	return bin_to_int(bin, tam);
}
//:(

void string_tam(unsigned char c, int* string, int pos_byte, int pos_string)
{
	while(pos_byte>= 0)
	{
		if(is_bit_i_set(c, pos_byte))
		{
			string[pos_string] = 1;
		}
		else
		{
			string[pos_string] = 0;
		}
		pos_byte--;
		pos_string++;
	}
}
NODE* criar_no_arv(unsigned char c){
	
	NODE *novo = (NODE*) malloc(sizeof(NODE));

	novo->byte = c;		
	novo->left = novo->right = NULL;

	return novo;
}

NODE* criar_arv(NODE* bt, int *i, int tam, FILE *compr){
	if(*i == tam) return bt;
	(*i)++;
	unsigned char item;
	
	fread(&item, sizeof(item), 1, compr);

	if(item == 92){
		fread(&item, sizeof(item), 1, compr);		
		(*i)++;
		return criar_no_arv(item);
	}
	
	bt = criar_no_arv(item);

	if(item == 42){	
		bt->left = criar_arv(bt->left, i, tam, compr);		
		bt->right = criar_arv(bt->right, i, tam, compr);
	}

	return bt;
}
void descompressao(NODE* arvore,int tam_arvore,  int tam_lixo, FILE* arq_comp)
{
	int indice = 7, pos_atual, pos_final, tam_arquivo;
	unsigned char c, ultimo;
	
	NODE* raiz = arvore;
	 FILE* arq_descomp = fopen("descomprimido", "wb");
	fpos_t pos;

	fgetpos(arq_comp, &pos);
	/*Nessa parte ele calcula o tamanho do arquivo*/
	fseek(arq_comp, 0, SEEK_SET);//Volta pro inicio do arquivo
	tam_arquivo = 0;
	while(!feof(arq_comp))
	{
		tam_arquivo++;
		fread(&c, sizeof(c), 1, arq_comp);
	}

	fseek(arq_comp, tam_arquivo, SEEK_SET);
	fread(&ultimo, sizeof(ultimo), 1, arq_comp);//Leu o último byte antes do eof

	fsetpos(arq_comp, &pos);//Volta pra posição depois da arvore

	pos_atual = 3 + tam_arvore;
	pos_final = tam_arquivo; 
	/*FIM*/

	fread(&c, sizeof(c), 1, arq_comp);

	while(pos_atual < pos_final-1)
	{
		if((arvore->left == NULL) && (arvore->right == NULL))
		{
			unsigned char d = arvore->byte;
			fwrite(&d, sizeof(d), 1, arq_descomp);
			arvore = raiz;
		}
		else if((indice < 0))
		{
				indice = 7;
				fread(&c, sizeof(c), 1, arq_comp);
				pos_atual+=1;
		}
		else if(is_bit_i_set(c, indice))
		{
			indice --;
			arvore = arvore->right;
		}
		else
		{
			indice--;
			arvore = arvore->left;
		}
	}

	indice = 7;

	while(indice >= tam_lixo)
	{
		if((arvore->left == NULL) && (arvore->right == NULL))
		{
			unsigned char d = arvore->byte;
			fwrite(&d, sizeof(d), 1, arq_descomp);
			arvore = raiz;
		}
		if(is_bit_i_set(ultimo, indice))
		{
			indice--;
			arvore = arvore->right;
		}
		else
		{
			(indice)--;
			arvore = arvore->left;
		}
	}
	fclose(arq_descomp);
}
void descomprimir(FILE* compr){
	
	int i, *tam_arv = (int*)malloc(13*sizeof(int)), tam_arquivo;
	int tam_lixo, tam_arvore;
	unsigned char c = 0;

	NODE *arvore = NULL;

	fread(&c, sizeof(c), 1, compr);

	tam_lixo = conv_tam_lixo(c);
	string_tam(c, tam_arv, 4, 0);

	fread(&c, sizeof(c), 1, compr);
	string_tam(c, tam_arv, 7, 5);
	for(i = 0; i < 13; i++)
	{
		printf("%d", tam_arv[i]);
	}
	tam_arvore = bin_to_int(tam_arv, 13);

	i = 0;
	arvore = criar_arv(arvore, &i, tam_arvore, compr);
	
	mostrar_arvore(arvore);puts("");

	descompressao(arvore, tam_arvore, tam_lixo,compr);
}