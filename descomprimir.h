int is_bit_i_set(unsigned char c, int i){
	unsigned char mask = 1 << i;
	return mask & c;
}

int bin_to_int(int *bin, int tam){
	int i = 0, saida = 0;
	
	while(i<tam){
		saida += bin[i]*pow(2, i);
		i++;
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

NODE* criar_no_arv(unsigned char c){
	
	NODE *novo = (NODE*) malloc(sizeof(NODE));

	novo->byte = c;		
	novo->left = novo->right = NULL;

	return novo;
}

NODE* criar_arv(NODE* bt, int *i, int* tam, FILE *compr){
	if(*i == *tam) return bt;
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

NODE* descomprimir(int *tam_lixo, int *tam_arvore){
	
	FILE *compr = fopen("tmp", "rb");
	unsigned char c = 0;
	NODE *arvore = NULL;
	int i;

	fread(&c, sizeof(c), 1, compr);

	*tam_lixo = conv_tam_lixo(c);
	*tam_arvore = conv_tam_arv(c, 5);

	fread(&c, sizeof(c), 1, compr);
		*tam_arvore += conv_tam_arv(c, 8);


	i = 0;
	arvore = criar_arv(arvore, &i, tam_arvore, compr);
		
	return arvore;
}