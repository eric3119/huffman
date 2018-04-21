hash_table* criar_hash(){
	hash_table* novo =  (hash_table*) malloc(sizeof(hash_table));
	int i;
	for( i = 0; i < 256; i++)
	{
		novo->bytes[i] = NULL;
	}
	return novo;
}
void put(hash_table* ht, char* byte, unsigned char folha)
{
	int tamanho = strlen(byte);
	binary* novo_n = (binary*)malloc(sizeof(binary));
	
	char* novo = (char*)malloc((tamanho+1)*sizeof(char));
	strcpy(novo, byte);
	novo_n->byte = novo;
	ht->bytes[folha] = novo_n;
}

void print_hash(hash_table* ht)
{
	int i;
	printf("hash_table:\n");
	for(i = 0; i < 256; i++)
	{
		if(ht->bytes[i]!= NULL)
		{	
			if(i!='\n')
				printf("%c %s\n", i, ht->bytes[i]->byte);
			else
				printf("\\n %s\n", ht->bytes[i]->byte);
		}
	}
}
